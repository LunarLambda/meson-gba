subprojects = [
  'agbabi',
  'butano',
  'dusk',
  'gba-hpp',
  'gba-link-connection',
  'gbadv',
  'gbfs',
  'gbt-player',
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
