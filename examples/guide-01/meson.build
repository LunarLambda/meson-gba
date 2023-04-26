libseven = dependency('libseven')
minrt = dependency('minrt')

elf = executable('guide-01', 'src/main.c',
  dependencies: [minrt, libseven],
  name_suffix: 'elf')

makerom = find_program('makerom')

rom = custom_target('guide-01-rom',
  input: elf,
  output: 'guide-01.gba',
  command: [makerom, '@INPUT@', '@OUTPUT@'],
  build_by_default: true)
