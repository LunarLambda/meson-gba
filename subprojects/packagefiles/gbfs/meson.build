project('gbfs', 'c',
  license: 'MIT',
  meson_version: '>=0.54.0',
  default_options: ['warning_level=1', 'c_std=none'])

gbfs = static_library('gbfs', 'libgbfs.c')

gbfs_exe = executable('gbfs', 'tools/gbfs.c', native: true)
insgbfs = executable('insgbfs', 'tools/insgbfs.c', native: true)
lsgbfs = executable('lsgbfs', 'tools/lsgbfs.c', native: true)
ungbfs = executable('ungbfs', 'tools/ungbfs.c', native: true)

# FIXME: Clean this up
gbfs_dep = declare_dependency(
  include_directories: ['.'],
  link_with: gbfs)

meson.override_dependency('gbfs', gbfs_dep)
