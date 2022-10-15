project('test', 'c')

subdir('tools')

libgba = dependency('libgba')
libtonc = dependency('libtonc')
libseven = dependency('libseven')

libgba_hello = executable(
  'libgba-hello',
  'src/libgba-hello.c',
  dependencies: libgba,
  name_suffix: 'elf',)

libtonc_hello = executable(
  'libtonc-hello',
  'src/libtonc-hello.c',
  dependencies: libtonc,
  name_suffix: 'elf',)

libseven_first = executable(
  'libseven-first',
  'src/libseven-first.c',
  dependencies: libseven,
  name_suffix: 'elf',)

# Build .gba ROMs
foreach bin : [libgba_hello, libtonc_hello, libseven_first]
  custom_target(
    bin.name() + '-rom',
    input: bin,
    output: bin.name() + '.gba',
    command: [makerom, '@INPUT@', '@OUTPUT@'],
    build_by_default: true,)
endforeach
