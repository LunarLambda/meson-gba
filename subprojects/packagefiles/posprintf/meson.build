project('posprintf', 'c')

posprintf = static_library('posprintf', 'posprintf/posprintf.S')

posprintf_dep = declare_dependency(
  include_directories: ['posprintf'],
  link_with: posprints)

meson.override_dependency('posprintf', posprintf_dep)
