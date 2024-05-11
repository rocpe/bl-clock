#pragma once
/*
 * No functionality is here implemented. It is used to suppress linker warning.
 * See https://stackoverflow.com/questions/73742774/gcc-arm-none-eabi-11-3-is-not-implemented-and-will-always-fail for more info
 */
void _close(void) { }
void _lseek(void) { }
void _read(void) { }
void _write(void) { }
