project('libgba', 'c',
  version: '0.5.2',
  license: 'LGPL-2.0-or-later',
)

bin2s_exe = find_program('bin2s', required: true)

font = custom_target(
  'amiga-font',
  command: ['./bin2s-shim', bin2s_exe.full_path(), '@OUTPUT1@', '-a', '2', '-H', '@OUTPUT0@', '@INPUT@'],
  input: ['data/amiga.fnt'],
  output: ['amiga_fnt.h', 'amiga_fnt.s'],
)

sources = [
  'src/AffineSet.c',
  'src/ArcTan.s',
  'src/BoyScout/BoyScout.c',
  'src/Compression.c',
  'src/console.c',
  'src/CpuSet.c',
  'src/disc_io/disc.c',
  'src/disc_io/dldi.c',
  'src/disc_io/dldi_stub.s',
  'src/disc_io/io_cf_common.c',
  'src/disc_io/io_m3cf.c',
  'src/disc_io/io_m3_common.c',
  'src/disc_io/io_m3sd.c',
  'src/disc_io/io_mpcf.c',
  'src/disc_io/io_sccf.c',
  'src/disc_io/io_sc_common.c',
  'src/disc_io/io_scsd.c',
  'src/disc_io/io_scsd_s.s',
  'src/disc_io/io_sd_common.c',
  'src/DivArm.s',
  'src/Div.s',
  'src/fade.c',
  'src/input.c',
  'src/interrupt.c',
  'src/InterruptDispatcher.s',
  'src/IntrWait.c',
  'src/mappy_print.c',
  'src/mb2print.c',
  'src/mbv2.c',
  'src/MultiBoot.s',
  'src/Reset.s',
  'src/Sound.s',
  'src/Sqrt.s',
  'src/xcomms.c',
  'src/xcomms_print.c',
  font,
]

includes = ['include']

libgba = static_library('gba', sources, include_directories: includes)

libgba_dep = declare_dependency(include_directories: includes, link_with: libgba)

meson.override_dependency('libgba', libgba_dep)
