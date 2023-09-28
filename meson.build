# Change these to suit your project, if you want.
project(
  'gba-meson', 'c',
  version: '0.6.0',
  license: 'Zlib',
  meson_version: '>=0.60.0',
  default_options: ['buildtype=debugoptimized', 'warning_level=2', 'c_std=c99', 'cpp_std=c++20'])

# Set up recommended compiler and linker flags.
subdir('meson/toolchain')

subprojects = [
  'agbabi',
  'butano',
  'dusk',
  'gba-hpp',
  'gba-link-connection',
  'gbfs',
  'gbt-player',
  'grit',
  'heartlib',
  'libgba',
  'libtonc',
  'libugba',
  'maxmod',
  'mmutil',
  'posprintf',
  'sdk-seven',
  'superfamiconv',
]

if have_devkitarm
  subprojects += ['libfat']
endif

foreach s : subprojects
  subproject(s)
endforeach
