project('test', 'c')

subdir('tools')

add_project_arguments('-mthumb', language: 'c')
add_project_link_arguments('-specs=gba.specs', '-mthumb', language: 'c')

libgba = dependency('libgba')
libtonc = dependency('libtonc')
libseven = dependency('libseven')

mapfile = '-Wl,-Map,@0@.map'

libgba_hello = executable(
  'libgba-hello',
  'src/libgba-hello.c',
  dependencies: libgba,
  name_suffix: 'elf',
  link_args: [mapfile.format('libgba-hello')],)

libtonc_hello = executable(
  'libtonc-hello',
  'src/libtonc-hello.c',
  dependencies: libtonc,
  name_suffix: 'elf',
  link_args: [mapfile.format('libtonc-hello')],)

libseven_first = executable(
  'libseven-first',
  'src/libseven-first.c',
  dependencies: libseven,
  name_suffix: 'elf',
  link_args: [mapfile.format('libseven-hello')],)

# Build .gba ROMs
foreach bin : [libgba_hello, libtonc_hello, libseven_first]
  custom_target(
    bin.name() + '-rom',
    input: bin,
    output: bin.name() + '.gba',
    command: [makerom, '@INPUT@', '@OUTPUT@'],
    build_by_default: true,)
endforeach
