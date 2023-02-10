# Change these to suit your project, if you want.
project('gba-meson', 'c',
  version: '0.5.0',
  license: 'Zlib',
  meson_version: '>=0.60.0',
  default_options: ['warning_level=2'])

# Set up recommended compiler and linker flags.
subdir('meson/toolchain')

# Build the project.
subdir('game')
