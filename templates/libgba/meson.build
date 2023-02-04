# Figure out a suitable runtime library. Pick devkitARM if possible.
dka_rt = dependency('dka-rom-rt', required: false)

if dka_rt.found()
  rt_dep = dka_rt
else
  rt_dep = dependency('minrt')
endif

dependencies = [rt_dep, dependency('libgba')]

elf = executable(
  'libgba-template',
  'src/main.c',
  dependencies: dependencies,
  name_suffix: 'elf')

makerom = find_program('makerom')

custom_target(
  'libgba-template-rom',
  input: elf,
  output: '@BASENAME@.gba',
  command: [makerom, '@INPUT@', '@OUTPUT@'],
  build_by_default)
