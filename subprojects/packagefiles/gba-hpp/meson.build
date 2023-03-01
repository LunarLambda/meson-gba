# Based on https://github.com/felixjones/gba-hpp/blob/405f379e7fee311815c7f7a4a6339c38a9e24c8f/CMakeLists.txt#L13-L14
project('gba-hpp', 'cpp',
  version: '4.0.0',
  license: 'Zlib',
  meson_version: '>=0.54.0',
  default_options: ['warning_level=0', 'cpp_std=c++20'])

gba_hpp_dep = declare_dependency(
  include_directories: ['include'])

meson.override_dependency('gba-hpp', gba_hpp_dep)
