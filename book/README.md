# Introduction

**meson-gba** is a toolkit for developing Game Boy Advance homebrew using the
[Meson](https://mesonbuild.com) build system. It aims to make building homebrew much simpler and
provides easy access to many different libraries and tools, making transitioning
from the existing Makefile-based setups easy.

The project is currently in beta state, and while everything has been tested
to at least compile successfully, you might run into various problems. Bug
reports are highly appreciated! You can also reach out in the `#sdk-seven`
channel in the [gbadev Discord](https://discord.io/gbadev) if you need help.

The **meson-gba** repository is set up such that the main branch acts as the
project template. Download dependencies with `meson subprojects download`,
and modify **game/meson.build** to suit your projects.