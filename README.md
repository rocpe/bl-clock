# bl-clock
Clock made on popular stm32 bluepill board.
# Setup
I assume you have git, meson. arm-none-eabi-g++(and others) and libopencm3 installed on your system.

Clone this repo with submodules:
```bash
git clone --recurse-submodules https://github.com/rocpe/bl-clock.git
```
Go to the root directory of the project and configure:
```bash
meson setup build/release --cross-file=cross-file.txt --buildtype=release
```
Or use build/debug and debugging symbols
```bash
meson setup build/debug --cross-file=cross-file.txt --buildtype=debugoptimized
```
You have to have installed libopencm3 globally on your system. ([package for Arch Linux](https://archlinux.org/packages/community/any/libopencm3/), [for other distros see this PKGBUILD file](https://github.com/archlinux/svntogit-community/blob/packages/libopencm3/trunk/PKGBUILD)). TODO: Add libopencm3 as submodule.

Then compile :
```bash
meson compile -C build/release
```
It should throw some linker warnings. Don't worry. As long as it compiles it's just fine.

You can compile with docs
```bash
meson compile -C build/release docs
```

Upload via st-link:
```bash
meson compile -C build/release flash
```
# Debugging
Run openocd in the root directory of the project and then run debugger
```bash
arm-none-eabi-gdb -q -x openocd.gdb
```
