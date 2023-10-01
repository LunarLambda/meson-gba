# meson-gba - Modern GBA Development with Meson

This project provides [Meson][meson-build] build files for various Game Boy
Advance libraries and tools.

## Development Notice

This project is still very much in alpha. Things are still messy, but are
continuously being updated and improved. Things might break unexpectedly,
and things are developed with the latest versions of meson and GCC/devkitARM
in mind, so make sure your tools are as up-to-date as can be.

## What's Included

Versions are generally of the format `[<tag>.]r<number of commits>.g<git commit hash>`. Projects
that don't use git are annotated with the latest file date present in the source archive.

- Development Libraries:
    - [agbabi] v2.1.5
    - [butano] 13.1.1
    - [dusk] v0.1.7.r3.g131f14e
    - [gba-hpp] r176.993fbb1
    - [gba-link-connection] v5.0.2
    - [gbfs] 2002-02-07
    - [gbt-player] v4.4.1
    - [heartlib] r280.1977aba
    - [libfat] v1.1.5.r2.g69543f0 (requires devkitARM)
    - [libgba] r136.0d46fc9
    - [libseven] v0.17.2
    - [libtonc] r15.cc862ce
    - [libugba] v0.3.0
    - [maxmod] v1.0.15
    - [posprintf] 2008-10-11
- Runtime Libraries:
    - [libsysgba] v0.3.0
    - [minrt] v0.8.0
- Build Tools:
    - From [gbt-player]:
        - mod2gbt
        - s3m2gbt
        - s3msplit
    - From [grit] \(requires FreeImage\):
        - grit v0.9.2
    - From [mmutil]:
        - mmutil v1.10.1
    - From [sdk-seven]:
        - gbafix-py
        - bin2s-py
        - makerom
    - From [SuperFamiconv]:
        - superfamiconv v0.9.2.r16.ga5027f3

## Installation

As all the libraries and tools are compiled from source, the only things you
need to have installed and in your PATH are:

- meson (at least version 0.60.0, ideally 1.0.0 or later)
- git
- A compiler for your system (`cl.exe`, `gcc`, etc.)
- A compiler for the GBA (`arm-none-eabi-gcc`)

## Compiling

Once you have everything, `git clone` or [download] this repository, then
navigate to the directory in a terminal (or "command-line") window, and run the
following commands:

```sh
meson subprojects download
meson setup --cross-file=meson/gba.ini build
```

If you want to use devkitPro (for example, if you want to use libfat), use the
following command to generate a suitable cross file:

Windows, using Powershell (not recommended):

```powershell
$f = gc meson/gba.ini; $f[1] = "path = '$Env:DEVKITARM/bin'"; sc dkarm.ini $f
```

Windows, using MSYS2:

```sh
sed "2cpath = '$(cygpath -m $DEVKITARM/bin)'" meson/gba.ini > dkarm.ini
```

Windows, using WSL / Linux / MacOS:

```sh
sed "2cpath = '$DEVKITARM/bin'" meson/gba.ini > dkarm.ini
```

Then run

```sh
meson setup --cross-file=dkarm.ini build
```

for the setup step.

To build, run:

```sh
ninja -C build
```

The built ROMs (.elf, .gba) will be in the `build` directory.

Check out the `examples` branch for some example projects.

## Windows

For development on Windows, the easiest method is to use MSYS2, either using
the [official installer][msys2-official], or the [devkitPro installer][msys2-dkp].

Install everything needed like so:

```sh
pacman -S mingw-w64-ucrt-x86_64-meson git mingw-w64-ucrt-x86_64-gcc
```

And if using the non-devkitPro compiler (recommended!):

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

cc_ver = run_command(cc, '--version', capture: true, check: false)

have_devkitarm = cc_ver.stdout().to_lower().contains('devkitarm')
```

See the [Meson compiler API][meson-compiler] for other things you can test for.

## License

This project is licensed under the zlib license.\
See [LICENSE.txt](./LICENSE.txt) for more information.

[agbabi]: https://github.com/felixjones/agbabi
[butano]: https://github.com/GValiente/butano
[devkitARM]: https://github.com/devkitPro/devkitarm-crtls
[download]: https://github.com/LunarLambda/meson-gba/archive/refs/heads/main.zip
[dusk]: https://github.com/bmchtech/dusk
[gba-hpp]: https://github.com/felixjones/gba-hpp
[gba-link-connection]: https://github.com/rodri042/gba-link-connection
[gbfs]: https://pineight.com/gba/#gbfs
[gbt-player]: https://github.com/AntonioND/gbt-player
[grit]: https://github.com/devkitPro/grit
[heartlib]: https://github.com/Sterophonick/HeartLib
[libfat]: https://github.com/devkitPro/libfat
[libgba]: https://github.com/gbadev-org/libgba
[libseven]: https://github.com/LunarLambda/sdk-seven
[libsysgba]: https://github.com/AntonioND/libugba
[libtonc]: https://github.com/gbadev-org/libtonc
[libugba]: https://github.com/AntonioND/libugba
[maxmod]: https://github.com/devkitPro/maxmod
[meson-build]: https://mesonbuild.com/index.html
[meson-compiler]: https://mesonbuild.com/Reference-manual_returned_compiler.html
[meson-options]: https://mesonbuild.com/Build-options.html#using-build-options
[minrt]: https://github.com/LunarLambda/sdk-seven
[mmutil]: https://github.com/devkitPro/mmutil
[msys2-dkp]: https://devkitpro.org/wiki/Getting_Started#Windows
[msys2-official]: https://www.msys2.org
[posprintf]: http://danposluns.com/gbadev/posprintf/index.html
[sdk-seven]: https://github.com/LunarLambda/sdk-seven
[superfamiconv]: https://github.com/Optiroc/SuperFamiconv
