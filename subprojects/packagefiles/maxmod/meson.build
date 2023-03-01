# Based on https://github.com/devkitPro/maxmod/blob/v1.0.15/maxmod.mak#L63-L68
project('maxmod', 'c',
  version: '1.0.12',
  meson_version: '>=0.54.0')

sources = [
  'source/mm_effect.s',
  'source/mm_main.s',
  'source/mm_mas.s',
  'source/mm_mas_arm.s',
  'source_gba/mm_init_default.s',
  'source_gba/mm_main_gba.s',
  'source_gba/mm_mixer_gba.s',
]

includes = ['asm_include']

maxmod = static_library('mm', sources,
  include_directories: includes,
  c_args: ['-xassembler-with-cpp', '-DSYS_GBA', '-DUSE_IWRAM'])

maxmod_dep = declare_dependency(
  include_directories: ['include'],
  link_with: maxmod)

meson.override_dependency('maxmod', maxmod_dep)
