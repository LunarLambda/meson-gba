# Figure out if we have devkitARM.
cc = meson.get_compiler('c')

cc_ver = run_command(cc, '--version', capture: true, check: false)

if cc_ver.stdout().to_lower().contains('devkitarm')
  have_devkitarm = true
else
  have_devkitarm = false
endif

# List of global compilation args. All libraries will be built with these.
compile_args = [
  '-mthumb',
  '-ffunction-sections',
  '-fdata-sections',
]

# no$gba does not support DWARF 5 debug info and crashes. Use DWARF 4.
if get_option('debug')
  compile_args += '-gdwarf-4'
endif

add_global_arguments(compile_args, language: 'c')

# List of link arguments.
link_args = [
  '-mthumb',
  '-Wl,--gc-sections',
]

# Newer binutils add warnings we don't care about
if find_program('ld', version: '>=2.39', required: false).found()
  link_args += '-Wl,--no-warn-rwx-segments'
endif

# Use libc_nano if available.
if cc.find_library('c_nano', required: false).found()
  link_args += '-specs=nano.specs'
endif

add_project_link_arguments(link_args, language: 'c')

subdir('devkitarm')
