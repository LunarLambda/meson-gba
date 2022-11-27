subprojects = [
  'agbabi',
  'gba-hpp',
  'gba-tools',
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
