# DC29 Badge Stuff

## What's in the repo
+ Funny music code
+ Firmware used

## Dumping/flashing the firmware
+ To access firmware: hold down bottom right button when pluggin into USB - a drive with a UF2 file should appear
+ Use [uf2conv](https://github.com/microsoft/uf2/blob/master/utils/uf2conv.py)
+ `python3 uf2conv.py DC29Human3.UF2` -> dump firmware
+ `python3 uf2conv.py flash.bin -o NEW.UF2` -> create new firmware
+ To reflash firmware: drag your new UF2 file back into the drive and it should automatically reboot

## Compiling
+ `clang -O2 -nostdlib -mthumb --target=armv6-none-eabi music.c`
+ `llvm-objcopy --dump-section .text=target.bin a.out`

## Usage
+ Open `target.bin` and `flash.bin` in a hex editor
+ Overwrite post-initialization main function in `flash.bin` with `target.bin` contents (file offset `0x1E8`) with your favorite hex editor of choice (make sure you *overwrite* bytes, not insert new ones)
+ Reflash over to the device 
+ Press buttons and have fun!
