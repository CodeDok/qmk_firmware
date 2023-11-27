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

enum tap_dance {
    TD_END,
    TD_HOME
};

enum custom_keycodes {
	SCREENSHOT = SAFE_RANGE,
	AMD_FULL,
	AMD_OVERLAY,
	STEAM_OVERLAY,
	DISCORD_OVERLAY,
	INTELLIJ_MOVE_FORWARD,
	INTELLIJ_MOVE_BACKWARD,
    INTELLIJ_SHOW_IN_EXPLORER,
    INTELLIJ_PIN_TAB,
    LINUX_INSERT,
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case SCREENSHOT:
            if (record->event.pressed) {
                // SEND_STRING(SS_TAP(LGUI(LSFT(X_S))));
                SEND_STRING(SS_DOWN(X_LGUI));
                SEND_STRING(SS_DOWN(X_LSFT));
                SEND_STRING(SS_TAP(X_S));
                SEND_STRING(SS_UP(X_LGUI));
                SEND_STRING(SS_UP(X_LSFT));
            } else {}
            break;

		case AMD_FULL:
			if (record->event.pressed) {
				SEND_STRING(SS_LALT("r"));
			} else {}
			break;

		case AMD_OVERLAY:
			if (record->event.pressed) {
				SEND_STRING(SS_DOWN(X_LCTL));
                SEND_STRING(SS_DOWN(X_LSFT));
                SEND_STRING(SS_TAP(X_O));
                SEND_STRING(SS_UP(X_LCTL));
                SEND_STRING(SS_UP(X_LSFT));
			} else {}
			break;

		case STEAM_OVERLAY:
			if (record->event.pressed) {
				SEND_STRING(SS_DOWN(X_LSFT));
                SEND_STRING(SS_TAP(X_F1));
                SEND_STRING(SS_UP(X_LSFT));
			} else {}
			break;

		case DISCORD_OVERLAY:
			if (record->event.pressed) {
				SEND_STRING(SS_DOWN(X_LCTL));
                SEND_STRING(SS_DOWN(X_LSFT));
                SEND_STRING(SS_TAP(X_HOME));
                SEND_STRING(SS_UP(X_LCTL));
                SEND_STRING(SS_UP(X_LSFT));
			} else {}
			break;
		case INTELLIJ_MOVE_FORWARD:
			if (record->event.pressed) {
				SEND_STRING(SS_DOWN(X_LALT));
				SEND_STRING(SS_DOWN(X_LSFT));
                SEND_STRING(SS_TAP(X_RIGHT));
                SEND_STRING(SS_UP(X_LSFT));
                SEND_STRING(SS_UP(X_LALT));
			} else {}
            break;
        case INTELLIJ_MOVE_BACKWARD:
            if (record->event.pressed) {
                SEND_STRING(SS_DOWN(X_LALT));
				SEND_STRING(SS_DOWN(X_LSFT));
                SEND_STRING(SS_TAP(X_LEFT));
                SEND_STRING(SS_UP(X_LSFT));
                SEND_STRING(SS_UP(X_LALT));
            } else {}
            break;
        case INTELLIJ_SHOW_IN_EXPLORER:
            if (record->event.pressed) {
                SEND_STRING(SS_DOWN(X_LALT));
                SEND_STRING(SS_TAP(X_F1));
                SEND_STRING(SS_UP(X_LALT));
                SEND_STRING(SS_TAP(X_1));
            } else {}
            break;
        case INTELLIJ_PIN_TAB: 
            if (record->event.pressed) {
                SEND_STRING(SS_DOWN(X_LCTL));
				SEND_STRING(SS_DOWN(X_LSFT));
                SEND_STRING(SS_TAP(X_LBRC)); // ü
                SEND_STRING(SS_UP(X_LSFT));
                SEND_STRING(SS_UP(X_LCTL));
            } else {}
            break;
        case LINUX_INSERT:
            if (record->event.pressed) {
                SEND_STRING(SS_DOWN(X_LSFT));
                SEND_STRING(SS_TAP(X_INS)); // ü
                SEND_STRING(SS_UP(X_LSFT));
            } else {}
            break;
    }
	return true;
}


bool caps_word_press_user(uint16_t keycode) {
    switch (keycode) {
        // Keycodes that continue Caps Word, with shift applied.
        case KC_A ... KC_Z:
		case DE_MINS:
        case KC_MINS:
            add_weak_mods(MOD_BIT(KC_LSFT));  // Apply shift to next key.
            return true;
        // Keycodes that continue Caps Word, without shifting.
        case KC_1 ... KC_0:
        case KC_BSPC:
        case KC_DEL:
        case KC_UNDS:
            return true;

        default:
            return false;  // Deactivate Caps Word.
    }
}

tap_dance_action_t tap_dance_actions[] = {
    [TD_HOME] = ACTION_TAP_DANCE_DOUBLE(KC_HOME, LCTL(KC_HOME)),
    [TD_END] = ACTION_TAP_DANCE_DOUBLE(KC_END, LCTL(KC_END)),
};


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
			KC_ESC,         KC_1,           KC_2,               KC_3,           KC_4,           KC_5,                                           KC_6,           KC_7,           KC_8,           KC_9,           KC_0,           DE_SS,
			KC_NUBS,        KC_Q,           KC_W,               KC_E,           KC_R,           KC_T,                                           DE_Z,           KC_U,           KC_I,           KC_O,           KC_P,           DE_PLUS,
			KC_LSFT,        KC_A,           KC_S,               KC_D,           KC_F,           KC_G,                                           KC_H,           KC_J,           KC_K,           KC_L,           DE_HASH,        KC_RSFT,
			KC_TAB,         DE_Y,           KC_X,               KC_C,           KC_V,           KC_B,           KC_MUTE,        KC_MUTE,        KC_N,           KC_M,           KC_COMM,        KC_DOT,         DE_MINS,        KC_RALT,
                                            KC_LGUI,            KC_LALT,        KC_LCTL,        KC_SPC,         MO(SYMB),       KC_ENT,         KC_BSPC,        MO(FUNC),       MO(MACRO),      TO(3)
	),

	/*SYMB*/
	[SYMB] = LAYOUT(
			KC_NO,          KC_NO,          KC_NO,              KC_NO,          KC_NO,          KC_NO,                                          KC_NO,          KC_NO,           KC_NO,         KC_NO,          KC_NO,          KC_NO,
            KC_NO,          KC_ESC,         DE_QUOT,            DE_LPRN,        DE_RPRN,        KC_INS,                                         KC_ESC,         DE_UDIA,         KC_UP,         DE_ODIA,        DE_EQL,         DE_ACUT,
			KC_LSFT,        DE_ADIA,        DE_SS,              DE_LCBR,        DE_RCBR,        DE_SLSH,                                        TD(TD_HOME),    KC_LEFT,         KC_DOWN,       KC_RIGHT,       TD(TD_END),     KC_RSFT,
			KC_LCTL,        DE_CIRC,        DE_PIPE,            DE_LBRC,        DE_RBRC,        DE_BSLS,        KC_NO,          KC_NO,          DE_ASTR,        DE_PLUS,         KC_BSLS,       DE_EXLM,        DE_QUES,        KC_RCTL,
											KC_TRNS,            KC_TRNS,        KC_NO,          KC_NO,          KC_TRNS,        KC_LALT,        KC_DEL,         KC_TRNS,         KC_NO,         KC_LGUI
	),

	/* MACRO */
	[MACRO] = LAYOUT(
			KC_NO,          KC_NO,          KC_NO,              KC_NO,          KC_NO,          KC_NO,                                          KC_NO,          KC_NO,                      KC_NO,                      KC_NO,                      KC_NO,          KC_NO,
			KC_NO,          KC_NO,          KC_NO,              KC_NO,          KC_NO,          KC_NO,                                          KC_NO,          KC_NO,                      KC_NO,                      KC_NO,                      KC_NO,          KC_NO,
			KC_NO,          KC_NO,          SCREENSHOT,   		KC_NO,          KC_NO,          KC_NO,                                          KC_NO,          INTELLIJ_MOVE_BACKWARD,     INTELLIJ_SHOW_IN_EXPLORER,  INTELLIJ_MOVE_FORWARD,      KC_NO,          KC_NO,
			KC_NO,          KC_NO,          KC_NO,              KC_NO,          LINUX_INSERT,   KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,                      KC_NO,                      KC_NO,                      KC_NO,          KC_NO,
											KC_NO,              KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,                      KC_NO,                      KC_NO
	),

	/* GAME */
	[GAME] = LAYOUT(
			KC_LGUI,        KC_NO,          KC_1,               KC_2,           KC_3,           KC_4,                                           KC_MPRV,        KC_MPLY,        KC_MNXT,        KC_NO,          KC_NO,          KC_ESC,
			KC_F1,          KC_TAB,         KC_Q,               KC_W,           KC_E,           KC_R,                                           DE_Z,           KC_U,           KC_I,           KC_O,           KC_P,           AMD_FULL,
			KC_F2,          KC_LSFT,        KC_A,               KC_S,           KC_D,           KC_F,                                           KC_H,           KC_J,           KC_K,           KC_L,           STEAM_OVERLAY,  AMD_OVERLAY,
			KC_F3,          KC_LCTL,        DE_Y,               KC_X,           KC_C,           KC_V,           KC_TRNS,        KC_NO,          KC_N,           KC_M,           KC_NO,          KC_NO,          DISCORD_OVERLAY,KC_NO,
											KC_5,            	KC_LALT,        KC_B,           KC_SPC,         KC_G,           KC_ENT,         MO(FUNC),       KC_NO,          KC_NO,          TO(BASE)
	),

	/* FUNC */
	[FUNC] = LAYOUT(
			KC_NO,          KC_NO,          KC_NO,              KC_NO,          KC_NO,          KC_NO,                                          KC_NO,          KC_NO,          KC_PSLS,        KC_PAST,        KC_PMNS,        KC_NO,
			KC_NO,          KC_F1,          KC_F2,              KC_F3,          KC_F4,          KC_NO,                                          KC_NO,          KC_P7,          KC_P8,          KC_P9,          KC_PPLS,        KC_NO,
			KC_LSFT,        KC_F5,          KC_F6,              KC_F7,          KC_F8,          KC_NO,                                          KC_P0,          KC_P4,          KC_P5,          KC_P6,          KC_PCMM,        KC_LSFT,
			KC_NO,          KC_F9,          KC_F10,             KC_F11,         KC_F12,         KC_NO,          KC_NO,          KC_NO,          KC_PDOT,        KC_P1,          KC_P2,          KC_P3,          KC_PEQL,        KC_NO,
											KC_NO,              KC_TRNS,        KC_TRNS,        KC_NO,          KC_NO,          KC_TRNS,        KC_NO,          KC_TRNS,        KC_TRNS,        KC_PENT
	)

};
