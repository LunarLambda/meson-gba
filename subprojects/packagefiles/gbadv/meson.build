project('gbadv', 'c')

libgba = dependency('libgba')

gbadv = static_library('gbadv', 'src/gbadv.c', dependencies: [libgba])

gbadv_dep = declare_dependency(
  include_directories: ['src'],
  link_with: gbadv)

meson.override_dependency('gbadv', gbadv_dep)
