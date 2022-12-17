project('dusk', 'c',
  version: '0.1.7',
  license: 'GPL-3.0-or-later',
  default_options: ['warning_level=1', 'c_std=none'])

libtonc = dependency('libtonc')

sources = [
  'src/dusk/src/contrib/initMapRegisters.c',
  'src/dusk/src/contrib/libgbfs.c',
  'src/dusk/src/contrib/loadMapFromROM.c',
  'src/dusk/src/contrib/loadObject.c',
  'src/dusk/src/contrib/loadObjectID.c',
  'src/dusk/src/contrib/loadPosition.c',
  'src/dusk/src/contrib/loadString.c',
  'src/dusk/src/contrib/mgba.c',
  'src/dusk/src/contrib/popValue.c',
  'src/dusk/src/contrib/setMapOnScreen.c',
  'src/dusk/src/contrib/shiftMap.c',
  'src/dusk/src/contrib/shiftMapLayer.c',
  'src/dusk/src/contrib/shiftMapObjects.c',
  'src/dusk/src/load.c',
  'src/dusk/src/sprites.c',
  'src/dusk/src/sys.c',
]

includes = [
  'src/dusk/include',
  'src/dusk/include/contrib',
]

dusk = static_library(
  'dusk',
  sources,
  include_directories: includes,
  dependencies: [libtonc],
  c_args: ['-DDUSK_VERSION="@0@"'.format(meson.project_version())])

dusk_dep = declare_dependency(
  link_with: dusk,
  include_directories: includes)

meson.override_dependency('dusk', dusk_dep)
