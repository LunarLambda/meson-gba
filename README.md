# meson-gba - Modern GBA Development with Meson

This project provides [Meson][meson-build] build files for various Game Boy
Advance libraries and tools.

## Development Notice

This project is still very much in alpha. Things are still messy, particularly
around differences between devkitARM and other ARM toolchains. Things might
break unexpectedly, and things are developed with the latest versions of
meson and GCC/devkitARM in mind.

If things don't work, make sure things are up to date, and check the
[Configurable Features](#configurable-features) section for settings you may
need to adjust.

If a library/tool fails to compile at all, it's probably been updated upstream,
in which case, please open an issue about it.

## What's Included

- Development Libraries:
    - [agbabi]
    - [butano]
    - [dusk]
    - [gba-hpp]
    - [gbt-player]
    - [heartlib]
    - [libfat]
    - [libgba]
    - [libseven]
    - [libtonc]
    - [libugba]
    - [maxmod]
    - [posprintf]
- Runtime Libraries:
    - [devkitARM]
    - [libsysgba]
    - [minrt]
- Build Tools:
    - From [gbt-player]:
        - mod2gbt
        - s3m2gbt
        - s3msplit
    - From [mmutil]:
        - mmutil
    - From [sdk-seven]:
        - gbafix-py
        - bin2s-py
        - makerom
    - From [SuperFamiconv]:
        - superfamiconv

## Installation

As all the libraries and tools are compiled from source, the only things you
need to have installed and in your PATH are:

- meson (at least version 0.59.0)
- git
- A compiler for your system (`cl.exe`, `gcc`, etc.)
- A compiler for the GBA (`arm-none-eabi-gcc`)

## Compiling

Once you have everything, `git clone` or [download] this repository, then
navigate to the directory in a terminal (or "command-line") window, and run the
following commands:

```sh
meson subprojects download
meson setup --cross-file=gba.ini build
```

If you're using devkitPro, install meson (not mingw-\*-meson),
then run

```
meson setup --cross-file=devkitarm.ini build
```

For the setup step.

If meson doesn't report any errors at this point, you should be able to compile
the project with

```sh
meson compile -C build
```

or

```sh
ninja -C build
```

The built ROMs (.elf, .gba) will be in the `build` directory.

## Windows

For development on Windows, the easiest method is to use MSYS2, either using
the [official installer][msys2-official], or the [devkitPro installer][msys2-dkp].

Install everything needed like so:

```sh
pacman -S mingw-w64-ucrt-x86_64-meson git mingw-w64-ucrt-x86_64-gcc
```

And if using the non-devkitPro compiler:

```sh
pacman -S mingw-w64-ucrt-x86_64-arm-none-eabi-toolchain
```

## Compiler Support

This toolchain works both with devkitARM, and "standard" arm-none-eabi-gcc
distributions. When reporting problems, please specify which compiler you're
using, and what version (output of `arm-none-eabi-gcc --version`), as well
as the output of `meson setup`.

If you wish to detect the devkitARM compiler specifically:

```meson
cc = meson.get_compiler('c')

output = run_command(cc, '--version', capture: true)

if output.stdout().to_lower().contains('devkitarm')
    message('we have devkitARM!')
endif
```

See the [Meson compiler API][meson-compiler] for other things you can test for.

## Configurable Features

libgba and libtonc have special integration with devkitARM's version of newlib.
The provided `meson.build` files will automatically detect availability and add
appropriate compiler flags (C/C++). See `examples/libgba-helloworld/src/main.c` for an example.

You can specify the following [Meson build options][meson-options]:

Option                 | Type    | Description                       | Default
-----------------------|---------|-----------------------------------|---------
`agbabi:use_devkitarm` | boolean | Build for devkitARM's newlib      | false
`libgba:dkp_console`   | feature | Enable devkitARM console features | auto
`libtonc:dkp_console`  | feature | Enable devkitARM console features | auto

## License

This project is licensed under the zlib license.\
See [LICENSE.txt](./LICENSE.txt) for more information.

[agbabi]: https://github.com/felixjones/agbabi
[butano]: https://github.com/GValiente/butano
[devkitARM]: https://github.com/devkitPro/devkitarm-crtls
[download]: https://github.com/LunarLambda/meson-gba/archive/refs/heads/main.zip
[dusk]: https://github.com/bmchtech/dusk
[gbadv]: https://github.com/sverx/GBAdv
[gba-hpp]: https://github.com/felixjones/gba-hpp
[gbt-player]: https://github.com/AntonioND/gbt-player
[heartlib]: https://github.com/Sterophonick/HeartLib
[libfat]: https://github.com/devkitPro/libfat
[libgba]: https://github.com/devkitPro/libgba
[libseven]: https://github.com/LunarLambda/sdk-seven
[libsysgba]: https://github.com/AntonioND/libugba
[libtonc]: https://github.com/devkitPro/libtonc
[libugba]: https://github.com/AntonioND/libugba
[maxmod]: https://github.com/devkitPro/maxmod
[meson-build]: https://mesonbuild.com/index.html
[meson-compiler]: https://mesonbuild.com/Reference-manual_returned_compiler.html
[meson-options]: https://mesonbuild.com/Build-options.html#using-build-options
[minrt]: https://github.com/LunarLambda/sdk-seven
[mmutil]: https://github.com/GValiente/mmutil
[msys2-dkp]: https://devkitpro.org/wiki/Getting_Started#Windows
[msys2-official]: https://www.msys2.org
[posprintf]: http://danposluns.com/gbadev/posprintf/index.html
[sdk-seven]: https://github.com/LunarLambda/sdk-seven
[superfamiconv]: https://github.com/Optiroc/SuperFamiconv
