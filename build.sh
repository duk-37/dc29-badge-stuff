#!/bin/bash
set -x
clang -O2 -nostdlib -mthumb --target=armv6-none-eabi music.c -o music.out

llvm-objcopy --dump-section .text=target.bin music.out

python3 weld.py flash.bin target.bin

python3 uf2conv.py welded.out -o MUSIC.uf2

set +x
