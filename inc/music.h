#pragma once

#include <stdint.h>

#define BASE_ADDRESS 0x2000

#define REBASE(x) ((x) + (BASE_ADDRESS))

// thanks arm
#define THUMB(x) ((x) + 1)

// don't know what exactly these do but they seem to set up some sort of timer connected to the buzzer
#define FUNC_SETUP_TIMER ((void(*)(unsigned))THUMB(REBASE(0x99E6)))
#define FUNC_TRIGGER_TIMER ((void(*)(unsigned*, int, int))THUMB(REBASE(0x44C0)))

// this one just updates an LED with a one-based index and a byte array with [R, G, B]
#define FUNC_UPDATE_LED ((void(*)(int, uint8_t*))THUMB(REBASE(0x5114)))

// structure relevant to buzzer
#define DATA_BUZZER 0x20000E54

// gpio pins - same for most SAMD21 microcontrollers
#define GPIO_PINS 0x41004420

// keys on the badge
#define KEY1 0x10
#define KEY2 0x20
#define KEY3 0x40
#define KEY4 0x80
