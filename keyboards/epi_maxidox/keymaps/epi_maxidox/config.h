/*
This is the c configuration file for the keymap

Copyright 2012 Jun Wako <wakojun@gmail.com>
Copyright 2015 Jack Humbert

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef CONFIG_USER_H
#define CONFIG_USER_H

#include "../../config.h"

//#define USE_SERIAL

//#define EE_HANDS
//#define TAPPING_TERM 200
#pragma once
#define AUTO_SHIFT_TIMEOUT 250

/* ws2812 RGB LED */
#define RGB_DI_PIN C6
//#define RGB_DI_PIN D5


#undef RGBLIGHT_ANIMATIONS
#define RGBLIGHT_LAYERS_RETAIN_VAL
// #define RGB_DISABLE_WHEN_USB_SUSPENDED
#undef RGBLED_NUM
#define RGBLED_NUM 8   // Number of LEDs
#define RGBLIGHT_LIMIT_VAL 200
#define TAPPING_TOGGLE 2



// #define RGBLIGHT_HUE_STEP 10
// #define RGBLIGHT_SAT_STEP 17
// #define RGBLIGHT_VAL_STEP 20
//#define RGBLIGHT_SLEEP
//#define RGBLIGHT_LAYERS
//#define RGBLIGHT_LAYERS_OVERRIDE_RGB_OFF
//#define RGBLIGHT_LAYER_BLINK

#endif
