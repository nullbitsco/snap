/* Copyright 2021 Jay Greco
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

/* This file is shared between AVR and RP2040 and contains defines common to both. */

#pragma once

#include "config_common.h"

/* USB Device descriptor parameter */
#define VENDOR_ID       0x6E61
#define PRODUCT_ID      0x6063
#define DEVICE_VER      0x0001
#define MANUFACTURER    nullbits
#define PRODUCT         SNAP

/* split config */
#define SPLIT_HAND_PIN_LOW_IS_LEFT

/* key matrix size */
#define MATRIX_ROWS 12
#define MATRIX_COLS 9
#define MATRIX_MUX_COLS 3

/* Set 0 if debouncing isn't needed */
#define DEBOUNCE 10

/* Optional SMT LED pins */
#define RGBLED_NUM 10
#define RGBLED_SPLIT { 5, 5 }
#define RGBLIGHT_LED_MAP { 8, 9, 0, 1, 2, 6, 7, 3, 4, 5 }  
#define RGBLIGHT_ANIMATIONS
#define RGBLIGHT_SLEEP

/* Optional split transactions */
#define SPLIT_OLED_ENABLE
