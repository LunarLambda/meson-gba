subprojects = [
  'agbabi',
  'butano',
  'dusk',
  'gba-hpp',
  'gba-link-connection',
  'gbfs',
  'gbt-player',
  'grit',
  'heartlib',
  'libgba',
  'libseven',
  'libtonc',
  'libugba',
  'libutil',
  'maxmod',
  'minrt',
  'mmutil',
  'posprintf',
  'superfamiconv',
]

if have_devkitarm
  subprojects += ['libfat']
endif

foreach s : subprojects
  subproject(s)
endforeach
