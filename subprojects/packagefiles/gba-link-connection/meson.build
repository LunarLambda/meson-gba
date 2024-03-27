# Based on
project('gba-link-connection', 'cpp',
  version: '6.2.3',
  license: 'MIT',
  meson_version: '>=0.54.0')

gba_link_connection_dep = declare_dependency(
  include_directories: ['lib'])

meson.override_dependency('gba-link-connection', gba_link_connection_dep)
