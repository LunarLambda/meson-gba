project('gbfs', 'c',
  license: 'LGPL-2.0-or-later',
  default_options: ['warning_level=1'])

gbfs = static_library('gbfs', 'libgbfs.c')

gbfs_dep = declare_dependency(
  include_directories: ['.'],
  link_with: gbfs)

meson.override_dependency('gbfs', gbfs_dep)
