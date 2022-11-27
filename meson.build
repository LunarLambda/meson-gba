project('gba-meson', 'c',
  version: '0.1.0',
  license: 'Zlib',
  meson_version: '>=0.56.0',
  default_options: ['warning_level=2', 'cpp_eh=none', 'cpp_rtti=false'])

# Set up compiler flags
subdir('meson/toolchain')

# For internal development
if get_option('dev')
  subdir('meson/dev')
endif

# Register devkitARM runtime libraries
subdir('meson/devkitarm')

# Build the examples
subdir('examples')
