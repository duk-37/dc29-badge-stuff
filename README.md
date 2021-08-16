# DC29 Badge Stuff

## What's in the repo
+ Funny music code
+ Firmware used (in case of updates)

## Dumping/flashing the firmware
+ To access firmware: hold down bottom right button when plugging into USB - a drive with a UF2 file should appear
+ Use [uf2conv](https://github.com/microsoft/uf2/blob/master/utils/uf2conv.py) (also needs [this](https://github.com/microsoft/uf2/blob/master/utils/uf2families.json) json file in the same folder)
+ `python3 uf2conv.py DC29Human3.UF2` -> dump firmware
+ `python3 uf2conv.py flash.bin -o NEW.UF2` -> create new firmware
+ To reflash firmware: drag your new UF2 file back into the drive and it should automatically reboot

## Compiling
+ Run `make` to compile. Output file is in output/music.uf2
  + If you are on MacOS: use homebrew to install a full clang build (`brew install llvm`) as lld isn't a thing on the default clang for some fucking reason
  + If you are on linux - make sure lld is installed (sudo apt install lld)

## Usage
+ Run `make`
+ Reflash `output/music.uf2` over to the device 
+ Press buttons and have fun!
