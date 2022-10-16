project('general-tools', 'c', 'cpp',
  version: '1.2.0',
  license: 'GPL-3.0-or-later')

package_string = '"@0@ @1@"'.format(meson.project_name(), meson.project_version())

add_project_arguments(
  ['-DPACKAGE_STRING=' + package_string],
  language: ['c', 'cpp'],
  native: true)

bin2s   = executable('bin2s',   'bin2s.c',     native: true)
bmp2bin = executable('bmp2bin', 'bmp2bin.cpp', native: true)
padbin  = executable('padbin',  'padbin.c',    native: true)
raw2c   = executable('raw2c',   'raw2c.c',     native: true)

meson.override_find_program('bin2s',   bin2s)
meson.override_find_program('bmp2bin', bmp2bin)
meson.override_find_program('padbin',  padbin)
meson.override_find_program('raw2c',   raw2c)
