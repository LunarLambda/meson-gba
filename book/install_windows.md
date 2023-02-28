# Installation (Windows)

Before we can get started, there is a few things we need to install. Mainly, we need:

- The meson build system
- The git version control system
- A compiler for your machine
- A compiler for the GBA
- (optional) [An emulator for running your game](./emulators.md)

Compiling software on Windows has always been notoriously difficult to set up due to every program kind of arbitrarily picking its own spot to hang out in, and it can be quite tricky to get all of them to talk to each other.

This is why we will use MSYS2, a software development platform for Windows that provides a simple, unix-like environment with a package manager that makes everything much easier.

However, this also means that we'll be doing a lot of the setup in the terminal, or "command prompt", that funny black window you can type do all sorts of arcane things with. Not to worry, we'll walk you through everything you need to do, and later on you can integrate everything nicely into an IDE like [VS Code]() <sup>todo</sup>

First, download the [MSYS2 installer](https://www.msys2.org/#installation).

Note, if you've done GBA homebrew development before, you may already have a version of MSYS2 installed, using the devkitPro installer. If you wish to use this installation rather than a fresh one, read the chapter [setting up devkitPro's MSYS]() <sup>todo</sup>.

Once you have MSYS2 installed, you'll want to open the `MSYS UCRT64` shell from your start menu.

**Important**: unless specified otherwise, we will *always* use the UCRT64 shell. See [Appendix: MSYS2]() <sup>todo</sup> for why.

**Note**: "shell" is the term used for the program that runs inside a terminal and reads commands as input. Windows comes with two shells, cmd (Command Prompt) and Powershell. MSYS2 gives us the bash shell, which has many more features.

Once you open it, you should be greeted by a prompt that looks a little like this:

<pre style="background-color:rgb(12,12,12)">
<span style="color:rgb(19,161,14)">user@computer</span> <span style="color:rgb(136,23,152)">UCRT64</span> <span style="color:rgb(193,156,0)">~</span>
<span style="color:rgb(204,204,204)">$</span>
</pre>

Now, the first thing we'll wanna do is make sure we can install packages, and update everything:

```sh
pacman -Syu
```
When it asks you if you want to proceed with the installation, press enter.

It will most likely say something like
```
:: To complete this update all MSYS2 processes including this terminal will be closed. Confirm to proceed [Y/n]
```
Press enter again, then open the UCRT64 shell.

Update the remaining packages with the following command:
```sh
pacman -Su
```

Now that we're all up to date, we can install everything you need, using this slightly magical incantation (you can press `Shift+Insert` to paste into the MSYS2 terminal):

```sh
pacman -S ${MINGW_PACKAGE_PREFIX}-{meson,gcc,arm-none-eabi-toolchain,freeimage} git
```

When it asks you which members to install, just hit enter.

Once that's done, run the following commands to verify everything is working:

```sh
meson --version
ninja --version
git --version
python3 --version
gcc --version
arm-none-eabi-gcc --version
```

If all of those commands run without problems, you're good to go!