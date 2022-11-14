project('gba-meson', 'c',
  version: '0.1.0',
  license: 'Zlib',
  meson_version: '>=0.56.0',
  default_options: [
    'warning_level=2',
    'cpp_eh=none',
    'cpp_rtti=false'])

# We want to compile and link as THUMB code primarily,
# and leverage linker section garbage collection.
#
# Passing -mthumb to the linker causes THUMB builds of libc, libgcc, etc.
# to be used.
add_global_arguments(
  '-mthumb',
  '-ffunction-sections',
  '-fdata-sections',
  language: 'c')

add_project_link_arguments(
  '-mthumb',
  '-Wl,--gc-sections',
  '-Wl,--no-warn-rwx-segments',
  language: 'c')

# For development purposes only
if get_option('buildtheworld')
  subprojects = [
    'agbabi',
    'gba-hpp',
    'gba-tools',
    'general-tools',
    'libgba',
    'libtonc',
    'posprintf',
    'sdk-seven',
    'superfamiconv',
  ]

  foreach s : subprojects
    subproject(s)
  endforeach
endif

# Expose devkitARM GBA specs files as dependencies, if available.
#
# dependency('devkitarm-gba-{rom,multiboot,ereader}-rt')
subdir('devkitarm')

# All the available libraries, compiled from source
libgba = dependency('libgba')
libtonc = dependency('libtonc')
libseven = dependency('libseven')
posprintf = dependency('posprintf')
gba_hpp = dependency('gba-hpp')
agbabi = dependency('agbabi')
minrt = dependency('minrt')

# Template string for linker map arguments
mapfile = '-Wl,-Map,@0@.map'

# A 'classical' ELF binary build, with .elf extension and linker map output.
libgba_hello = executable(
  'libgba-hello',
  'src/libgba-hello.c',
  dependencies: [libgba, minrt],
  name_suffix: 'elf',
  link_args: [mapfile.format('libgba-hello')])

libtonc_hello = executable(
  'libtonc-hello',
  'src/libtonc-hello.c',
  dependencies: [libtonc, minrt],
  name_suffix: 'elf',
  link_args: [mapfile.format('libtonc-hello')])

libseven_first = executable(
  'libseven-first',
  'src/libseven-first.c',
  dependencies: [libseven, minrt],
  name_suffix: 'elf',
  link_args: [mapfile.format('libseven-hello')])

posprintf_test = executable(
  'posprintf-test',
  'src/posprintf-test.c',
  dependencies: [libtonc, minrt, posprintf],
  name_suffix: 'elf',
  link_args: [mapfile.format('posprintf-test')])

makerom = subproject('sdk-seven').get_variable('makerom')

# Build .gba ROMs using makerom
foreach bin : [libgba_hello, libtonc_hello, libseven_first, posprintf_test]
  custom_target(
    bin.name() + '-rom',
    input: bin,
    output: bin.name() + '.gba',
    command: [makerom, '@INPUT@', '@OUTPUT@'],
    build_by_default: true)
endforeach
