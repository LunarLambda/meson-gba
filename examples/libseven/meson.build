rt_dep = dependency('minrt')

dependencies = [rt_dep, dependency('libseven')]

elf = executable(
  'libseven-template',
  'src/main.c',
  dependencies: dependencies,
  name_suffix: 'elf')

makerom = find_program('makerom')

custom_target(
  'libseven-template-rom',
  input: elf,
  output: '@BASENAME@.gba',
  command: [makerom, '@INPUT@', '@OUTPUT@'],
  build_by_default: true)
