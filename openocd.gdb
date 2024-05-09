target extended-remote :3333

# only debug version
file build/debug/bl-clock.elf
# because libopencm3 is installed globally with no debug symbols gdb won't be able to print its sources

# print demangled symbols
set print asm-demangle on

# set backtrace limit to not have infinite backtrace loops
set backtrace limit 32

break main
load

# start the process but immediately halt the processor
stepi
