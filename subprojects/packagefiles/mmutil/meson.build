project('mmutil', 'c',
  version: '1.10.1',
  meson_version: '>=0.50.0',
  default_options: ['warning_level=0'])

cc = meson.get_compiler('c', native: true)

m_dep = cc.find_library('m', required: false)

sources = [
  'source/adpcm.c',
  'source/files.c',
  'source/gba.c',
  'source/it.c',
  'source/kiwi.c',
  'source/main.c',
  'source/mas.c',
  'source/mod.c',
  'source/msl.c',
  'source/nds.c',
  'source/s3m.c',
  'source/samplefix.c',
  'source/simple.c',
  'source/upload.c',
  'source/wav.c',
  'source/xm.c',
]

includes = ['source']

pkgver = 'PACKAGE_VERSION="@0@"'.format(meson.project_version())

args = ['-D' + pkgver]

if cc.get_id() != 'msvc'
  args += ['-Wno-multichar']

mmutil = executable('mmutil',
  sources,
  include_directories: includes,
  c_args: args,
  dependencies: m_dep,
  native: true)

meson.override_find_program('mmutil',  mmutil)
