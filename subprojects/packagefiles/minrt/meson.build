project('gba-minrt', 'c',
  license: 'MPL-2.0')

sources = [
  'src/crt0.s',
  'src/ram.c',
]

include = ['include']

lib = meson.source_root() / 'lib'

minrt = static_library(
  'minrt',
  sources,
  include_directories: include + 'src')

minrt_dep = declare_dependency(
  include_directories: include,
  link_with: minrt,
  link_args: ['-L' + lib, '-Trom.ld'],
  link_depends: [lib / 'gba_base.ld', lib / 'rom.ld'])

minrt_mb_dep = declare_dependency(
  include_directories: include
  link_with: minrt,
  link_args: ['-L' + lib, '-Tmultiboot.ld'],
  link_depends: [lib / 'gba_base.ld', lib / 'multiboot.ld'])

meson.override_dependency('minrt', minrt_dep)
meson.override_dependency('minrt-multiboot', minrt_mb_dep)
