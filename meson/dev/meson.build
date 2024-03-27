subprojects = [
  'agbabi',
  'butano',
  'gba-hpp',
  'gba-link-connection',
  'gbfs',
  'gbt-player',
  'grit',
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
  message('Setting up subproject', s)
  subproject(s)
endforeach
