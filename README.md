# devkitARM-gba-meson - Ports of devkitARM's GBA development tooling to meson

See `meson.build` for available libraries and how to generate .gba ROMs.

```sh
meson setup --cross-file cross/arm7tdmi build
meson compile -C build
```

The built ROMs (.elf, .gba) will be in the build directory you specified.

## Note About Toolchains

This project works both with devkitARM, and an unmodified arm-none-eabi toolchain.

libgba and libtonc have special integration with devkitARM's version of newlib.
The provided meson.build files will automatically detect availability and disable
those features if needed. See `src/libgba-hello.c` and `subprojects/packagefiles/libgba/meson.build`.

You can also pass `-Dlibgba.dkp-console=enabled`, which will cause a compile error
when not using devkitARM.

If you wish to detect devkitARM, something like this should work:

```
cc = meson.get_compiler('c')

output = run_command(cc, '--version', capture: true)

if output.stdout().to_lower().contains('devkitarm')
    message('we have devkitARM!')
endif
```

gba-minrt works with both devkitARM's newlib, as well as unmodified newlib and newlib-nano builds.

If you wish to use devkitARM's usual stuff, remove `minrt` as a dependency and add `-specs=gba.specs`
or equivalent to your target's link args.
