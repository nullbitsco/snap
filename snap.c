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
#include QMK_KEYBOARD_H

// Macro variables
bool is_alt_tab_active = false;
uint16_t alt_tab_timer = 0;
bool muted = false;

typedef struct PACKED {
    uint8_t r;
    uint8_t c;
} encodermap_t;

// Map encoders to their respective virtual matrix entry
// Allows for encoder control using VIA
const encodermap_t encoder_map[2][2] = {
    {{0, 8}, {1, 8}},  // Left encoder matrix location
    {{6, 8}, {7, 8}},  // Right encoder matrix location
};

static void process_encoder_matrix(encodermap_t pos) {
    action_exec((keyevent_t){
        .key = (keypos_t){.row = pos.r, .col = pos.c}, .pressed = true, .time = (timer_read() | 1) /* time should not be 0 */
    });
#if TAP_CODE_DELAY > 0
    wait_ms(TAP_CODE_DELAY);
#endif
    action_exec((keyevent_t){
        .key = (keypos_t){.row = pos.r, .col = pos.c}, .pressed = false, .time = (timer_read() | 1) /* time should not be 0 */
    });
}

bool encoder_update_kb(uint8_t index, bool clockwise) {
    #ifdef ENCODER_ENABLE
    if (!encoder_update_user(index, clockwise)) return false;
    #endif
    process_encoder_matrix(encoder_map[index][clockwise ? 0 : 1]);
    return true;
}

void matrix_init_kb(void) {
    set_bitc_LED(LED_OFF);
    matrix_init_remote_kb();
    matrix_init_user();
}

void keyboard_post_init_kb(void) {
    #ifdef CONSOLE_ENABLE
    debug_enable = true;
    debug_matrix = true;
    #endif
    keyboard_post_init_user();
}

void matrix_scan_kb(void) {
    matrix_scan_remote_kb();
    matrix_scan_user();

    if (is_alt_tab_active) {
        if (timer_elapsed(alt_tab_timer) > 1000) {
            unregister_code(KC_LALT);
            is_alt_tab_active = false;
        }
    }
}

// Use Bit-C LED to show CAPS LOCK and NUM LOCK status
bool led_update_kb(led_t led_state) {
    bool res = led_update_user(led_state);
    if (res) {
        if (is_keyboard_master()) set_bitc_LED(led_state.caps_lock ? LED_DIM : LED_OFF);
    }
    return res;
}

bool process_record_kb(uint16_t keycode, keyrecord_t *record) {
    // If console is enabled, it will print the matrix position and status of each key pressed
    #ifdef CONSOLE_ENABLE
    dprintf("kc: 0x%04X, col: %u, row: %u, pressed: %b, time: %u\n", keycode, record->event.key.col, record->event.key.row, record->event.pressed, record->event.time);
    #endif

    process_record_remote_kb(keycode, record);
    if (!process_record_user(keycode, record)) return false;

    switch (keycode) {
        case RESET:
            if (record->event.pressed && is_keyboard_master()) {
                set_bitc_LED(LED_DIM);
                #ifdef RGBLIGHT_ENABLE
                rgblight_disable_noeeprom();
                #endif
                #ifdef OLED_ENABLE
                oled_off();
                #endif
                bootloader_jump();  // jump to bootloader
            }
            return false;

        case DISC_MUTE:
            if (record->event.pressed) {
                tap_code(KC_F23);
                #ifdef RGBLIGHT_ENABLE
                if (!rgblight_is_enabled()) break;

                if (muted) {
                    rgblight_enable_noeeprom();
                } else {
                    rgblight_timer_disable();
                    uint8_t val = rgblight_get_val();
                    rgblight_sethsv_range(255, 255, val, 1, 5);
                }
                #endif
                muted = !muted;
            }
            break;

        case SUPER_ALT_TAB:
            if (record->event.pressed) {
                if (!is_alt_tab_active) {
                    is_alt_tab_active = true;
                    register_code(KC_LALT);
                }
                alt_tab_timer = timer_read();
                register_code(KC_TAB);
            } else {
                unregister_code(KC_TAB);
            }
            break;

        default:
            break;
    }

    return true;
}

// Workaround for sleep issues
void suspend_power_down_kb(void) {
    suspend_power_down_user();

    // Turn off underglow
#    if defined(RGBLIGHT_SLEEP) && defined(RGBLIGHT_ENABLE)
    rgblight_suspend();
#    endif
    // Turn off OLED
#    ifdef OLED_ENABLE
    oled_off();
#    endif
    // Hack: force one last sync
    matrix_post_scan();
}

void suspend_wakeup_init_kb(void) {
    suspend_wakeup_init_user();

    // Wake up underglow
#if defined(RGBLIGHT_SLEEP) && defined(RGBLIGHT_ENABLE)
    rgblight_wakeup();
#endif
}
