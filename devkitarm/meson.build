cc = meson.get_compiler('c')

dka_rom_rt = dependency('', required: false)
dka_mb_rt = dependency('', required: false)
dka_er_rt = dependency('', required: false)

if cc.has_argument('-specs=gba.specs')
  dka_rom_rt = declare_dependency(
    link_args: ['-specs=gba.specs'])
endif

if cc.has_argument('-specs=gba_mb.specs')
  dka_mb_rt = declare_dependency(
    link_args: ['-specs=gba_mb.specs'])
endif

if cc.has_argument('-specs=gba_er.specs')
  dka_er_rt = declare_dependency(
    link_args: ['-specs=gba_er.specs'])
endif

meson.override_dependency('devkitarm-gba-rom-rt', dka_rom_rt)
meson.override_dependency('devkitarm-gba-multiboot-rt', dka_mb_rt)
meson.override_dependency('devkitarm-gba-ereader-rt', dka_er_rt)
