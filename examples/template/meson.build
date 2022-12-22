# Get the 'makerom' program from sdk-seven.
#
# Normally you should be using find_program(...) instead, but sdk-seven
# currently requires this workaround.
makerom = subproject('sdk-seven').get_variable('makerom')

# The name of your project.
name = 'template'

# All of the source files used by your project.
sources = [
  'src/main.c',
]

# All of the include directories used by your project.
includes = [
  'include',
]

# Linker arguments. Be careful with these.
# -Wl,-Map causes the linker to output a 'link map', which can be useful for
# debugging. If you don't know what that is, you can safely ignore it.
link_args = [
  f'-Wl,-Map,@name@.map',
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
  link_args: link_args,
  dependencies: dependencies,
  name_suffix: 'elf')

# Build a raw GBA ROM file from your ELF file.
rom = custom_target(
  name + '_rom',
  input: elf,
  output: name + '.gba',
  command: [makerom, '@INPUT@', '@OUTPUT@'],
  build_by_default: true)
