# Change these to suit your project, if you want.
project(
  'gba-meson', 'c',
  version: '0.10.0',
  license: 'Zlib',
  meson_version: '>=0.60.0',
  default_options: ['buildtype=debugoptimized', 'warning_level=2', 'c_std=c99', 'cpp_std=c++20'])

# Set up recommended compiler and linker flags.
subdir('meson/toolchain')

# If you're working on meson-gba
if get_option('dev')
  subdir('meson/dev')
  subdir_done()
endif

# The name of your project.
name = 'gba-meson-template'

# All of the source files used by your project.
sources = [
  'src/main.c',
]

# All of the include directories used by your project.
includes = [
  'include',
]

# Dependencies. gba-meson provides a large number of GBA development libraries.
# Check them out and add the ones you want to use to this list.
dependencies = [
  dependency('minrt'),
]

# The main executable for your game. We give it a '.elf' file extension,
# just to make the file more easy to differentiate from a raw ROM.
elf = executable(
  name,
  sources,
  include_directories: includes,
  dependencies: dependencies,
  name_suffix: 'elf')

# Get the 'makerom' program from sdk-seven.
makerom = find_program('makerom')

# Build a raw GBA ROM file from your ELF file.
rom = custom_target(
  name + '-rom',
  input: elf,
  output: name + '.gba',
  command: [makerom, '@INPUT@', '@OUTPUT@'],
  build_by_default: true)
