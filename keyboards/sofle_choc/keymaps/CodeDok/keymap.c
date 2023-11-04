/* Copyright 2023 Brian Low
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
#include "sendstring_german.h"

#define BASE 0
#define SYMB 1
#define MACRO 2
#define GAME 3
#define FUNC 4

/* ----------- MACROS -----------*/

enum custom_keycodes {
    SHOW_WINDOWS = SAFE_RANGE,
    TEST
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    return true;
}


/* ----------- ENCODERS ----------- */

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [BASE] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(LCTL(LSFT(KC_TAB)), LCTL(KC_TAB))},
    [SYMB] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(LCTL(LSFT(KC_TAB)), LCTL(KC_TAB))},
    [MACRO] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(LCTL(LSFT(KC_TAB)), LCTL(KC_TAB))},
    [GAME] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(LCTL(LSFT(KC_TAB)), LCTL(KC_TAB))},
    [FUNC] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(LCTL(LSFT(KC_TAB)), LCTL(KC_TAB))},
};
#endif


/* ----------- LAYOUT ----------- */

/*

Template:
    [Layer] = LAYOUT(
        KC_NO,   KC_NO,   KC_NO,   KC_NO,    KC_NO,    KC_NO,                     KC_NO,  KC_NO,   KC_NO,  KC_NO,  KC_NO,  KC_NO,
        KC_NO,   KC_NO,   KC_NO,   KC_NO,    KC_NO,    KC_NO,                     KC_NO,  KC_NO,   KC_NO,  KC_NO,  KC_NO,  KC_NO,
        KC_NO,   KC_NO,   KC_NO,   KC_NO,    KC_NO,    KC_NO,                     KC_NO,  KC_NO,   KC_NO,  KC_NO,  KC_NO,  KC_NO,
        KC_NO,   KC_NO,   KC_NO,   KC_NO,    KC_NO,    KC_NO,   KC_NO,   KC_NO,   KC_NO,  KC_NO,   KC_NO,  KC_NO,  KC_NO,  KC_NO,
                          KC_NO,   KC_NO,    KC_NO,    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,  KC_NO,  KC_NO
    )
*/

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    /* BASE */
    [BASE] = LAYOUT(
            KC_ESC,         KC_1,           KC_2,               KC_3,           KC_4,           KC_5,                                           KC_6,           KC_7,           KC_8,           KC_9,           KC_0,           KC_MINS,
            KC_TAB,         KC_Q,           KC_W,               KC_E,           KC_R,           KC_T,                                           DE_Z,           KC_U,           KC_I,           KC_O,           KC_P,           KC_RBRC,
            KC_LSFT,        KC_A,           KC_S,               KC_D,           KC_F,           KC_G,                                           KC_H,           KC_J,           KC_K,           KC_L,           DE_LPRN,        DE_RPRN,
            KC_NUBS,        DE_Y,           KC_X,               KC_C,           KC_V,           KC_B,           TO(3),          KC_MUTE,        KC_N,           KC_M,           KC_COMM,        KC_DOT,         KC_SLSH,        KC_RALT,
                                            KC_LGUI,            KC_LALT,        KC_LCTL,        KC_SPC,         MO(SYMB),       KC_ENT,         KC_BSPC,        KC_RSFT,        MO(FUNC),       TT(1)
    ),

    /*SYMB*/
    [SYMB] = LAYOUT(
            KC_NO,          KC_GRV,         KC_NO,              KC_NO,          KC_NO,          KC_NO,                                          KC_NO,          KC_NO,           KC_NO,         KC_NO,          KC_NO,          KC_NO,
            KC_NO,          KC_NO,          KC_NO,              DE_LCBR,        DE_RCBR,        KC_NO,                                          KC_NO,          KC_LBRC,         KC_UP,         KC_SCLN,        KC_EQL,         KC_NO,
            KC_LSFT,        KC_QUOT,        LSFT(KC_MINS),      DE_SLSH,        DE_BSLS,        KC_NO,                                          KC_NO,          KC_LEFT,         KC_DOWN,       KC_RIGHT,       KC_MINS,        KC_RSFT,
            KC_LCTL,        KC_NO,          DE_PIPE,            KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,           KC_RBRC,       KC_BSLS,        KC_NO,          KC_NO,
                                            KC_TRNS,            KC_NO,          KC_NO,          KC_NO,          KC_TRNS,        KC_NO,          KC_LGUI,        KC_TRNS,         KC_NO,         KC_TRNS
    ),

    /* MACRO */
    [MACRO] = LAYOUT(
            KC_NO,          KC_NO,          KC_NO,              KC_NO,          KC_NO,          KC_NO,                                          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,
            KC_NO,          KC_NO,          KC_NO,              KC_NO,          KC_NO,          KC_NO,                                          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,
            KC_NO,          KC_NO,          LGUI(LSFT(KC_S)),   KC_NO,          KC_NO,          KC_NO,                                          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,
            KC_NO,          KC_NO,          KC_NO,              KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,
                                            KC_NO,              KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO
    ),

    /* GAME */
    [GAME] = LAYOUT(
            KC_NO,          KC_ESC,         KC_1,               KC_2,           KC_3,           KC_4,                                           TO(BASE),       KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,
            KC_F1,          KC_TAB,         KC_Q,               KC_W,           KC_E,           KC_R,                                           DE_Z,           KC_U,           KC_I,           KC_O,           KC_P,           KC_NO,
            KC_F2,          KC_LSFT,        KC_A,               KC_S,           KC_D,           KC_F,                                           KC_H,           KC_J,           KC_K,           KC_L,           KC_NO,          KC_NO,
            KC_F3,          KC_LCTL,        DE_Y,               KC_X,           KC_C,           KC_V,           KC_TRNS,        KC_NO,          KC_N,           KC_M,           KC_NO,          KC_NO,          KC_NO,          KC_NO,
                                            KC_LGUI,            KC_LALT,        KC_G,           KC_SPC,         KC_B,           MO(FUNC),       KC_NO,          KC_NO,          KC_NO,          KC_NO
    ),

    /* FUNC */
    [FUNC] = LAYOUT(
            KC_NO,          KC_NO,          KC_NO,              KC_NO,          KC_NO,          KC_NO,                                          KC_NO,          KC_NO,          KC_PSLS,        KC_PAST,        C_PMNS,         KC_NO,
            KC_NO,          KC_F1,          KC_F2,              KC_F3,          KC_F4,          KC_NO,                                          KC_NO,          KC_P7,          KC_P8,          KC_P9,          C_PPLS,         KC_NO,
            KC_NO,          KC_F5,          KC_F6,              KC_F7,          KC_F8,          KC_NO,                                          KC_PDOT,        KC_P4,          KC_P5,          KC_P6,          KC_PCMM,        KC_NO,
            KC_NO,          KC_F9,          KC_F10,             KC_F11,         KC_F12,         KC_NO,          KC_NO,          KC_NO,          KC_P0,          KC_P1,          KC_P2,          KC_P3,          KC_PEQL,        KC_NO,
                                            KC_NO,              KC_TRNS,        KC_TRNS,        KC_NO,          KC_NO,          KC_TRNS,        KC_NO,          KC_NO,          KC_TRNS,        KC_PENT
    )

};
