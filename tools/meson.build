gbafix = find_program('gbafix')
objcopy = find_program('objcopy')

makerom = configure_file(
  input: 'makerom.in',
  output: 'makerom',
  configuration: {
    'OBJCOPY': objcopy.full_path(),
    'GBAFIX': gbafix.full_path(),
  },)
