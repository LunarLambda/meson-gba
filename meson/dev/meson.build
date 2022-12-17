subprojects = [
  'agbabi',
  'butano',
  'dusk',
  'gba-hpp',
  'gba-plusplus',
  'gba-tools',
  'gbadv',
  'gbfs',
  'gbt-player',
  'general-tools',
  'libgba',
  'libtonc',
  'libugba',
  'maxmod',
  'mmutil',
  'posprintf',
  'sdk-seven',
  'superfamiconv',
]

if have_devkitarm
  subprojects += ['libfat']
endif

foreach s : subprojects
  subproject(s)
endforeach
