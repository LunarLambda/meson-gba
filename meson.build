# Change these to suit your project, if you want.
project(
  'gba-meson', 'c',
  version: '0.6.0',
  license: 'Zlib',
  meson_version: '>=0.60.0',
  default_options: ['buildtype=debugoptimized', 'warning_level=2', 'c_std=c99', 'cpp_std=c++20'])

# Set up recommended compiler and linker flags.
subdir('meson/toolchain')
subdir('examples')
