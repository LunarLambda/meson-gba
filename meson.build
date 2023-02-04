# Change these to suit your project!
project('gba-meson', 'c',
  version: '0.5.0',
  license: 'Zlib',
  meson_version: '>=0.60.0',
  default_options: ['warning_level=2'])

# Set up recommended compiler and linker flags, as well as devkitARM support.
subdir('meson/toolchain')

# Build the project.
subdir('game')
