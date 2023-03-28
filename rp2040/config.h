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

/* NOTE: This config file is specific to RP2040 builds. */

#pragma once

#include "config_common.h"

/* split config */
#define SOFT_SERIAL_PIN GP7
#define SPLIT_HAND_PIN GP21

/*
 * Keyboard Matrix Assignments
 * The snap uses a demultiplexer for the cols.
 * to free up more IOs for awesomeness!
 * See matrix.c for more details.
*/
// Left side
#define MATRIX_ROW_PINS { GP4, GP5, GP6, GP29, GP8, GP9 }
#define MATRIX_COL_MUX_PINS { GP26, GP27, GP28 }

//Right side
#define MATRIX_ROW_PINS_RIGHT { GP29, GP28, GP27, GP26, GP22, GP20 }
#define MATRIX_COL_MUX_PINS_RIGHT { GP6, GP5, GP4 }
#define MATRIX_EXT_PIN_RIGHT GP21

/* Optional SMT LED pins */
#define RGB_DI_PIN GP23

/* Optional encoder pins */
#define ENCODERS_PAD_A { GP20 }
#define ENCODERS_PAD_B { GP22 }
#define ENCODERS_PAD_A_RIGHT { GP8 }
#define ENCODERS_PAD_B_RIGHT { GP9 }

/* Optional speaker pin */
#define AUDIO_PIN GP21

/* RP2040-specific defines*/
#define RP2040_FLASH_W25X10CL
#define I2C1_SDA_PIN GP2
#define I2C1_SCL_PIN GP3
#define I2C_DRIVER I2CD2
#define RMKB_SIO_DRIVER SIOD0
#define RMKB_SIO_TX_PIN GP0
#define RMKB_SIO_RX_PIN GP1


// Needed for ARM platforms, as there is no PROGMEM
#ifndef pgm_read_byte_near
#define pgm_read_byte_near(addr) pgm_read_byte(addr)
#endif
