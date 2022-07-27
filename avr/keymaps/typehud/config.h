/* Copyright 2022 Chris Tanaka <https://github.com/christanaka>
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

#pragma once

// Old configuration
#define OLED_BRIGHTNESS 128
#define OLED_TIMEOUT 30000
#define OLED_UPDATE_INTERVAL 200

// Selectively define RGB modes to save some space
// VIA support won't fit otherwise
#ifdef RGBLIGHT_ENABLE
// clang-format off
#undef RGBLIGHT_LED_MAP
#undef RGBLIGHT_ANIMATIONS
// #define RGBLIGHT_EFFECT_BREATHING
#define RGBLIGHT_EFFECT_RAINBOW_SWIRL
#define RGBLIGHT_EFFECT_STATIC_GRADIENT
// clang-format on
#endif

// Split configuration
#define SPLIT_TRANSPORT_MIRROR
#define SPLIT_WPM_ENABLE

// Typehud configuration
#define TYPEHUD_FILLGRAPH
#define TYPEHUD_MATRIX_COLS 16
// #define TYPEHUD_MASTER
// #define TYPEHUD_MATRIX_ROTATE_90
// #define TYPEHUD_MATRIX_ROTATE_180
// #define TYPEHUD_MATRIX_ROTATE_270
