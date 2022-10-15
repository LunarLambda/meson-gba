# devkitARM-gba-meson - Ports of devkitARM's GBA development tooling to meson

Make sure devkitPRO compilers are in PATH:

```sh
export PATH="$DEVKITARM/bin:$PATH"
```

Compile with meson:

```sh
meson setup --cross-file cross/arm7tdmi --cross-file cross/gba-dkp build
meson compile -C build
```

The built ROMs (.elf, .gba) will be in the build directory you specified.
