# meson-gba - Modern GBA Development with Meson

This project provides [Meson][meson-build] build files for various Game Boy
Advance libraries and tools.

## Development Notice

This project is still very much in alpha. Things are still messy, but are
continuously being updated and improved. Things might break unexpectedly,
and things are developed with the latest versions of meson and GCC/devkitARM
in mind, so make sure your tools are as up-to-date as can be.

[Projects made with meson-gba](./PROJECTS.md)

## What's Included

Dependencies (libraries, runtimes) can be accessed using the [`dependency`][meson-dependency] function.\
Programs can be accessed using the [`find_program`][meson-find_program] function.

Project               | Version            | Dependencies               | Programs
----------------------|--------------------|----------------------------|---------
[agbabi]              | 2.1.5              | `agbabi`                   |
[butano]              | 15.7.0             | `butano`                   |
[dusk]                | 0.1.7.r3.g131f14e  | `dusk`                     |
[gba-hpp]             | r176.993fbb1       | `gba-hpp`                  |
[gba-link-connection] | 5.0.2              | `gba-link-connection`      |
[gbfs]                | 2002-02-07         | `gbfs`                     | `gbfs`, `insgbfs`, `lsgbfs`, `ungbfs`
[gbt-player]          | 4.4.1              | `gbt-player`               | `mod2gbt`, `s3m2gbt`, `s3msplit`
[grit]                | 0.9.2              |                            | `grit`
[heartlib]            | r280.1977aba       | `heartlib`                 |
[libfat]              | 1.1.5.r2.g69543f0  | `libfat`                   |
[libgba]              | r136.0d46fc9       | `libgba`                   |
[libseven]            | 0.22.3             | `libseven`                 |
[libtonc]             | r15.cc862ce        | `libtonc`                  |
[libugba/libsysgba]   | 0.3.0              | `libugba`, `libsysgba`     |
[libutil]             | r1.743f5d1         | `libutil`                  |
[maxmod]              | 1.0.15             | `maxmod`                   |
[minrt]               | 0.12.0             | `minrt`, `minrt-multiboot` | `makerom`, `gbafix-py`, `bin2s-py`
[mmutil]              | 1.10.1             |                            | `mmutil`
[posprintf]           | sdk-seven fork     | `posprintf`                |
[superfamiconv]       | 0.9.2.r16.ga5027f3 |                            | `superfamiconv`

## Installation and Usage

As all the libraries and tools are compiled from source, the only things you
need to have installed and in your PATH are:

- meson (at least version 0.60.0, ideally 1.0.0 or later)
- git
- A compiler for your system (`cl.exe`, `gcc`, etc.)
- A compiler for the GBA (`arm-none-eabi-gcc`)

See the [meson gba book](https://lunarlambda.github.io/meson-gba-book/) for more information.

## Using devkitPro

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

meson-gba is licensed under the zlib license.\
See [LICENSE.txt](./LICENSE.txt) for more information.

See the homepages of the bundled projects for their respective licensing.

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
[libseven]: https://github.com/sdk-seven/libseven
[libsysgba]: https://github.com/AntonioND/libugba
[libtonc]: https://github.com/gbadev-org/libtonc
[libugba]: https://github.com/AntonioND/libugba
[libutil]: https://github.com/sdk-seven/libutil
[maxmod]: https://github.com/devkitPro/maxmod
[meson-build]: https://mesonbuild.com/index.html
[meson-compiler]: https://mesonbuild.com/Reference-manual_returned_compiler.html
[meson-dependency]: https://mesonbuild.com/Reference-manual_functions.html#dependency
[meson-find_program]: https://mesonbuild.com/Reference-manual_functions.html#find_program
[meson-options]: https://mesonbuild.com/Build-options.html#using-build-options
[minrt]: https://github.com/sdk-seven/runtime
[mmutil]: https://github.com/devkitPro/mmutil
[msys2-dkp]: https://devkitpro.org/wiki/Getting_Started#Windows
[msys2-official]: https://www.msys2.org
[posprintf]: https://github.com/sdk-seven/posprintf
[superfamiconv]: https://github.com/Optiroc/SuperFamiconv
