subprojects = [
  'agbabi',
  'butano',
  'dusk',
  'gba-hpp',
  'gba-link-connection',
  'gba-plusplus',
  'gba-tools',
  'gbadv',
  'gbfs',
  'gbt-player',
  'general-tools',
  'heartlib',
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
