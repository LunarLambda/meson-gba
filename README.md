# meson-gba - Modern GBA Development with Meson

This project provides [Meson][meson-build] build files for various Game Boy
Advance libraries and tools. Everything is compiled from source as needed (see
[dependency()][meson-dependency] and [find\_program()][meson-findprogram]).

## What's Included

- Basic `arm-none-eabi-gcc` cross file (`cross/arm7tdmi.txt`)
- Example build code, with comments (`meson.build`)
- Development Libraries:
    - [agbabi]
    - [gba-hpp]
    - [gba-minrt]
    - [libgba]
    - [libseven]
    - [libtonc]
    - [maxmod]
    - [posprintf]
- Build Tools:
    - From [sdk-seven]:
        - makerom
    - From [general-tools]:
        - bin2s
        - bmp2bin
        - padbin
        - raw2c
    - From [gba-tools]:
        - gbafix
        - gbalzss
        - gbfs
        - insgbfs
        - lsgbfs
        - ungbfs
    - From [mmutil]:
        - mmutil
    - From [SuperFamiconv]:
        - superfamiconv

## Installation

As all the libraries and tools are compiled from source, the only things you
really need to have installed and in your PATH are:

- meson
- git
- A compiler for your system (`cl.exe`, `gcc`, etc.)
- A compiler for the GBA (`arm-none-eabi-gcc`)

Once you have those, `git clone` or [download] this repository, then navigate
to the directory in a terminal (or "command-line") window, and run the
following commands:

```sh
meson subprojects download
meson setup --cross-file=cross/arm7tdmi.txt build
```

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

Install meson, git, and gcc with `pacman -Syu meson git gcc`, and if using
the official installer, install `mingw-w64-x86_64-arm-none-eabi-toolchain` too.

## Compiler Support

This toolchain works both with devkitARM, and "standard" arm-none-eabi-gcc
distributions. When reporting problems, please specify which compiler you're
using, and what version (output of `arm-none-eabi-gcc --version`), as well
as the output of `meson setup` / `meson reconfigure`.

If you wish to detect the devkitARM compiler specifically in meson.build,
you can do something like this:

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
appropriate compiler flags (C/C++). See `src/libgba-hello.c` for an example.

You can specify the following [Meson build options][meson-options]:

Option                 | Type    | Description                       | Default
-----------------------|---------|-----------------------------------|---------
`buildtheworld`        | boolean | Build all bundled subprojects     | false
`agbabi:use_devkitarm` | boolean | Build for devkitARM's newlib      | false
`libgba:dkp_console`   | feature | Enable devkitARM console features | auto
`libtonc:dkp_console`  | feature | Enable devkitARM console features | auto

## License

This project is licensed under the zlib license.\
See [LICENSE.txt](./LICENSE.txt) for more information.

[agbabi]: https://github.com/felixjones/agbabi
[download]: https://github.com/LunarLambda/meson-gba/archive/refs/heads/main.zip
[gba-hpp]: https://github.com/felixjones/gba-hpp
[gba-minrt]: https://github.com/LunarLambda/gba-minrt
[gba-tools]: https://github.com/devkitPro/gba-tools
[general-tools]: https://github.com/devkitPro/general-tools
[libgba]: https://github.com/devkitPro/libgba
[libseven]: https://github.com/LunarLambda/libseven
[libtonc]: https://github.com/devkitPro/libtonc
[maxmod]: https://github.com/devkitPro/maxmod
[meson-build]: https://mesonbuild.com/index.html
[meson-compiler]: https://mesonbuild.com/Reference-manual_returned_compiler.html
[meson-dependency]: https://mesonbuild.com/Dependencies.html
[meson-findprogram]: https://mesonbuild.com/Reference-manual_functions.html#find_program
[meson-options]: https://mesonbuild.com/Build-options.html#using-build-options
[mmutil]: https://github.com/GValiente/mmutil
[msys2-dkp]: https://devkitpro.org/wiki/Getting_Started#Windows
[msys2-official]: https://www.msys2.org
[posprintf]: http://danposluns.com/gbadev/posprintf/index.html
[sdk-seven]: https://github.com/LunarLambda/sdk-seven
[superfamiconv]: https://github.com/Optiroc/SuperFamiconv
