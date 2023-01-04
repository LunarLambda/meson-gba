subprojects = [
  'agbabi',
  'butano',
  'dusk',
  'gba-hpp',
  'gba-link-connection',
  'gba-plusplus',
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

if build_machine.system() == 'windows'
  warning('some subprojects do not currently compile under windows')
else
  subprojects += ['gba-tools', 'general-tools']
endif

if have_devkitarm
  subprojects += ['libfat']
endif

foreach s : subprojects
  subproject(s)
endforeach
