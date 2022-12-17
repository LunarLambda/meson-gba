# Change these to suit your project!
project('gba-meson', 'c',
  version: '0.1.0',
  license: 'Zlib',
  meson_version: '>=0.56.0',
  default_options: ['warning_level=2'])

# Set up recommended compiler and linker flags, as well as devkitARM support.
subdir('meson/toolchain')

# Build the examples
#
# Usually you will want to remove this line, and replace it with your own
# build code. The easiest way to do this is to copy one of the examples,
# modify it, and then add a `subdir('my_directory')` line here.
#
# You can also write your build definitions here directly, but using a subdir
# is a little cleaner, since you don't need to worry about this file otherwise.
subdir('examples')
