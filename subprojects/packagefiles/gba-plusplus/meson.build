project('gba-plusplus', 'cpp',
  version: '0.0.4',
  license: 'Zlib',
  default_options: ['cpp_std=c++17'])

gba_plusplus_dep= declare_dependency(
  include_directories: ['include'])

meson.override_dependency('gba-plusplus', gba_hpp_dep)
