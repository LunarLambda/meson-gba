dka_rt = dependency('devkitarm-rom-rt', required: false)

# Figure out a suitable runtime library. Pick devkitARM if possible.
if dka_rt.found()
  rt_dep = dka_rt
else
  rt_dep = dependency('minrt')
endif

subdir('libgba-helloworld')
subdir('libseven-helloworld')
subdir('libtonc-helloworld')
subdir('posprintf')
subdir('template')
