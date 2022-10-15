project('gba-tools', 'c', 'cpp',
  version: '1.2.0',
  license: 'GPL-3.0-or-later',
  default_options: ['cpp_std=c++11'],
)

gbafix  = executable('gbafix',  'src/gbafix.c',    native: true)
gbalzss = executable('gbalzss', 'src/gbalzss.cpp', native: true)
gbfs    = executable('gbfs',    'src/gbfs.c',      native: true)
insgbfs = executable('insgbfs', 'src/insgbfs.c',   native: true)
lsgbfs  = executable('lsgbfs',  'src/lsgbfs.c',    native: true)
ungbfs  = executable('ungbfs',  'src/ungbfs.c',    native: true)

meson.override_find_program('gbafix',  gbafix)
meson.override_find_program('gbalzss', gbalzss)
meson.override_find_program('gbfs',    gbfs)
meson.override_find_program('insgbfs', insgbfs)
meson.override_find_program('lsgbfs',  lsgbfs)
meson.override_find_program('ungbfs',  ungbfs)
