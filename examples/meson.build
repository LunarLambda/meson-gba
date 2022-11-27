dka_rt = dependency('devkitarm-rom-rt', required: false)

# Figure out a suitable runtime library. Pick devkitARM if possible.
if dka_rt.found()
  rt_dep = dka_rt
else
  rt_dep = dependency('minrt')
endif

libgba = dependency('libgba')
libtonc = dependency('libtonc')
libseven = dependency('libseven')
posprintf = dependency('posprintf')

# Template string for linker map arguments
mapfile = '-Wl,-Map,@0@.map'

libgba_hello = executable(
  'libgba-hello',
  'src/libgba-hello.c',
  dependencies: [libgba, rt_dep],
  name_suffix: 'elf',
  link_args: [mapfile.format('libgba-hello')])

libtonc_hello = executable(
  'libtonc-hello',
  'src/libtonc-hello.c',
  dependencies: [libtonc, rt_dep],
  name_suffix: 'elf',
  link_args: [mapfile.format('libtonc-hello')])

libseven_first = executable(
  'libseven-first',
  'src/libseven-first.c',
  dependencies: [libseven, rt_dep],
  name_suffix: 'elf',
  link_args: [mapfile.format('libseven-hello')])

posprintf_test = executable(
  'posprintf-test',
  'src/posprintf-test.c',
  dependencies: [libtonc, rt_dep, posprintf],
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
