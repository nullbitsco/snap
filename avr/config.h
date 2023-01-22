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

/* NOTE: This config file is specific to AVR builds. */

#pragma once

#include "config_common.h"

/* Used to set host for remote KB if VUSB detect doesn't work. */
// #define KEYBOARD_HOST // Force host mode
// #define KEYBOARD_REMOTE // Force remote mode

// Workarounds for boot/sleep issues
#define USB_SUSPEND_WAKEUP_DELAY 250
#define NO_SUSPEND_POWER_DOWN

/* space savers */
// #define NO_ACTION_TAPPING // Waiting on QMK #11528
#define NO_ACTION_ONESHOT
#define IGNORE_MOD_TAP_INTERRUPT
#define TAPPING_FORCE_HOLD

/* split config */
// #define SPLIT_USB_DETECT // Enable if you have issues with USB
#define SOFT_SERIAL_PIN E6
#define SPLIT_HAND_PIN B6
#define DISABLE_SYNC_TIMER

/*
 * Keyboard Matrix Assignments
 * The snap uses a demultiplexer for the cols.
 * to free up more IOs for awesomeness!
 * See matrix.c for more details.
*/
// Left side
#define MATRIX_ROW_PINS { D4, C6, D7, F4, B4, B5 }
#define MATRIX_COL_MUX_PINS { F7, F6, F5 }

//Right side
#define MATRIX_ROW_PINS_RIGHT { F4, F5, F6, F7, B1, B3 }
#define MATRIX_COL_MUX_PINS_RIGHT { D7, C6, D4 }
#define MATRIX_EXT_PIN_RIGHT B6

/* Optional SMT LED pins */
#define RGB_DI_PIN B2

/* Optional encoder pins */
#define ENCODERS_PAD_A { B3 }
#define ENCODERS_PAD_B { B1 }
#define ENCODERS_PAD_A_RIGHT { B4 }
#define ENCODERS_PAD_B_RIGHT { B5 }

/* Optional speaker pin */
#define AUDIO_PIN B6
