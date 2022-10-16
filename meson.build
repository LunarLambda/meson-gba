project('gba-meson', 'c',
  default_options: [
    'b_staticpic=false',
    'cpp_eh=none',
    'cpp_rtti=false'])

# We want to compile and link as THUMB code primarily,
# and leverage linker section garbage collection
add_global_arguments('-mthumb', '-ffunction-sections', '-fdata-sections', language: 'c')
add_project_link_arguments('-mthumb', '-Wl,--gc-sections', language: 'c')

# The tools directory provides some helper scripts, like `makerom` for turning
# our ELF binaries into .gba ROM images
#
# TODO: Add gbafix flag support to makerom
subdir('tools')

libgba = dependency('libgba')
libtonc = dependency('libtonc')
libseven = dependency('libseven')
minrt = dependency('minrt')

mapfile = '-Wl,-Map,@0@.map'

# A 'classical' ELF binary build, with .elf extension and linker map output.
#
# We use gba-minrt as a runtime here, mostly for testing
# If you want to use devkitARM's runtime, remove minrt from dependencies
# and add `-specs=gba.specs` to link_args.
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

# Build .gba ROMs using makerom
foreach bin : [libgba_hello, libtonc_hello, libseven_first]
  custom_target(
    bin.name() + '-rom',
    input: bin,
    output: bin.name() + '.gba',
    command: [makerom, '@INPUT@', '@OUTPUT@'],
    build_by_default: true)
endforeach
