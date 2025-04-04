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
#define FUNC 3
#define MOUSE 4



/* ----------- Macros / Custom Keycodes -----------*/
enum custom_keycodes {
	INTELLIJ_MOVE_FORWARD = SAFE_RANGE,
	INTELLIJ_MOVE_BACKWARD,
    INTELLIJ_SHOW_IN_EXPLORER,
    INTELLIJ_PIN_TAB,
    INTELLIJ_LINE_UP,
    INTELLIJ_LINE_DOWN,
    INTELLIJ_COMMENT_LINE,
    INTELLIJ_ACTION_SEARCH,
    INTELLIJ_SHOW_USAGE,
    INTELLIJ_LAST_EDIT,
    POWERTOYS_TEXT_INSERT,
    VIVALDI_MOVE_WORKSPACE,
    WINDOWS_TASK_MANAGER
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
		case INTELLIJ_MOVE_FORWARD:
			if (record->event.pressed) {
				SEND_STRING(SS_DOWN(X_LALT));
				SEND_STRING(SS_DOWN(X_LCTL));
                SEND_STRING(SS_TAP(X_RIGHT));

			} else {
                SEND_STRING(SS_UP(X_LCTL));
                SEND_STRING(SS_UP(X_LALT));
            }
            break;
        case INTELLIJ_MOVE_BACKWARD:
            if (record->event.pressed) {
                SEND_STRING(SS_DOWN(X_LALT));
				SEND_STRING(SS_DOWN(X_LCTL));
                SEND_STRING(SS_TAP(X_LEFT));

            } else {
                SEND_STRING(SS_UP(X_LCTL));
                SEND_STRING(SS_UP(X_LALT));
            }
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

            } else {
                SEND_STRING(SS_UP(X_LSFT));
                SEND_STRING(SS_UP(X_LCTL));
            }
            break;
        case INTELLIJ_LINE_UP:
            if (record->event.pressed) {
                register_code16(KC_LALT);
				register_code16(KC_LSFT);
                tap_code16(KC_UP);

            } else {
                unregister_code16(KC_LSFT);
                unregister_code16(KC_LALT);
            }
            break;
        case INTELLIJ_LINE_DOWN:
            if (record->event.pressed) {
                register_code16(KC_LALT);
				register_code16(KC_LSFT);
                tap_code16(KC_DOWN);

            } else {
                unregister_code16(KC_LSFT);
                unregister_code16(KC_LALT);
            }
            break;
        case INTELLIJ_COMMENT_LINE:
            if (record->event.pressed) {
                SEND_STRING(SS_DOWN(X_LCTL));
                SEND_STRING(SS_TAP(X_SLASH));

            } else {
                SEND_STRING(SS_UP(X_LCTL));
            }
            break;
        case INTELLIJ_ACTION_SEARCH:
            if (record->event.pressed) {
                SEND_STRING(SS_DOWN(X_LCTL));
                SEND_STRING(SS_DOWN(X_LSFT));
                SEND_STRING(SS_TAP(X_A));

            } else {
                SEND_STRING(SS_UP(X_LSFT));
                SEND_STRING(SS_UP(X_LCTL));
            }
            break;
        case INTELLIJ_SHOW_USAGE:
            if (record->event.pressed) {
                SEND_STRING(SS_DOWN(X_LCTL));
                SEND_STRING(SS_DOWN(X_LALT));
                SEND_STRING(SS_TAP(X_F7));

            } else {
                SEND_STRING(SS_UP(X_LALT));
                SEND_STRING(SS_UP(X_LCTL));
            }
            break;
        case INTELLIJ_LAST_EDIT:
            if (record->event.pressed) {
                SEND_STRING(SS_DOWN(X_LCTL));
                SEND_STRING(SS_DOWN(X_LSFT));
                SEND_STRING(SS_TAP(X_BSPC));

            } else {
                SEND_STRING(SS_UP(X_LSFT));
                SEND_STRING(SS_UP(X_LCTL));
            }
            break;
        case POWERTOYS_TEXT_INSERT:
            if(record->event.pressed) {
                SEND_STRING(SS_DOWN(X_LCTL));
                SEND_STRING(SS_DOWN(X_LALT));
                SEND_STRING(SS_DOWN(X_LGUI));
                SEND_STRING(SS_TAP(X_V));
            } else {
                SEND_STRING(SS_UP(X_LGUI));
                SEND_STRING(SS_UP(X_LALT));
                SEND_STRING(SS_UP(X_LCTL));

            }
        case VIVALDI_MOVE_WORKSPACE:
            if (record->event.pressed) {
                SEND_STRING(SS_DOWN(X_LCTL));
                SEND_STRING(SS_DOWN(X_LSFT));
                SEND_STRING(SS_TAP(X_APP));
                SEND_STRING(SS_TAP(X_M));
                SEND_STRING(SS_TAP(X_W));

            } else {
                SEND_STRING(SS_UP(X_LCTL));
                SEND_STRING(SS_UP(X_LSFT));
            }
            break;
        case WINDOWS_TASK_MANAGER:
            if (record->event.pressed) {
                SEND_STRING(SS_DOWN(X_LCTL));
				SEND_STRING(SS_DOWN(X_LSFT));
                SEND_STRING(SS_TAP(X_ESC)); // ü

            } else {
                SEND_STRING(SS_UP(X_LSFT));
                SEND_STRING(SS_UP(X_LCTL));
            }
            break;
    }
	return true;
}





/* ----------- Caps Word -----------*/
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





/* ----------- Tap Dance -----------*/


enum tap_dance {
    TD_END,
    TD_HOME
};

tap_dance_action_t tap_dance_actions[] = {
    [TD_HOME] = ACTION_TAP_DANCE_DOUBLE(KC_HOME, LCTL(KC_HOME)),
    [TD_END] = ACTION_TAP_DANCE_DOUBLE(KC_END, LCTL(KC_END))
};



/* ----------- Leader Key -----------*/
void leader_end_user(void) {
    if (leader_sequence_two_keys(KC_S, KC_T)) {
        SEND_STRING(SS_DOWN(X_LGUI));
        SEND_STRING(SS_DOWN(X_LSFT));
        SEND_STRING(SS_TAP(X_S));      
        SEND_STRING(SS_UP(X_LGUI));
        SEND_STRING(SS_UP(X_LSFT));                                                                                                                                          
    }
}

 

/* ----------- Combos -----------*/
const uint16_t PROGMEM leader_combo[] = {KC_F, KC_D, COMBO_END};
const uint16_t PROGMEM escape_combo[] = {KC_S, KC_D, COMBO_END};
const uint16_t PROGMEM app_combo[] = {KC_RIGHT, KC_LEFT, COMBO_END};

combo_t key_combos[] = {
    COMBO(leader_combo, QK_LEAD),
    COMBO(escape_combo, KC_ESC),
    COMBO(app_combo, KC_APP),
};

/* ----------- Key Override ----------- */
// Define dummy key overrides
const key_override_t quotes_override = ko_make_basic(MOD_MASK_SHIFT, DE_QUOT, DE_DQUO);

// Array of key overrides
const key_override_t *key_overrides[] = {
    &quotes_override,
    NULL // Always terminate the array with NULL
};


/* ----------- ENCODERS ----------- */
#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
	[BASE] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(LCTL(LSFT(KC_TAB)), LCTL(KC_TAB))},
	[SYMB] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(LCTL(LSFT(KC_TAB)), LCTL(KC_TAB))},
	[MACRO] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(LCTL(LSFT(KC_TAB)), LCTL(KC_TAB))},
	[FUNC] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(LCTL(LSFT(KC_TAB)), LCTL(KC_TAB))},
    [MOUSE] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(LCTL(LSFT(KC_TAB)), LCTL(KC_TAB))},
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
			KC_ESC,         KC_1,           KC_2,               KC_3,           KC_4,           KC_5,                                               KC_6,           KC_7,           KC_8,           KC_9,                       KC_0,           DE_SS,
			KC_NUBS,        KC_Q,           KC_W,               KC_E,           KC_R,           KC_T,                                               DE_Z,           KC_U,           KC_I,           KC_O,                       KC_P,           DE_PLUS,
			KC_LSFT,        KC_A,           KC_S,               KC_D,           KC_F,           KC_G,                                               KC_H,           KC_J,           KC_K,           KC_L,                       DE_HASH,        KC_RSFT,
			KC_TAB,         DE_Y,           KC_X,               KC_C,           KC_V,           KC_B,           KC_MUTE,            KC_MUTE,        KC_N,           KC_M,           KC_COMM,        KC_DOT,                     DE_MINS,        KC_RALT,
                                            KC_LGUI,            KC_LALT,        KC_LCTL,        KC_SPC,         TL_LOWR,            KC_ENT,         KC_BSPC,        TL_UPPR,       MO(MACRO),       DM_PLY1
	),  // TL_LOWR = SYMB, TL_UPPR = FUNC

	/*SYMB*/
	[SYMB] = LAYOUT(
			KC_NO,                      KC_NO,          KC_NO,              KC_NO,          KC_INS,         KC_PSCR,                                        KC_NO,          KC_NO,           WINDOWS_TASK_MANAGER,          KC_NO,          KC_NO,          KC_NO,
            VIVALDI_MOVE_WORKSPACE,     KC_ESC,         DE_QUOT,            DE_LPRN,        DE_RPRN,        DE_TILD,                                        DE_AT,          DE_UDIA,         KC_UP,                         DE_ODIA,        DE_EQL,         DE_ACUT,
			KC_LSFT,                    DE_ADIA,        DE_SS,              DE_LCBR,        DE_RCBR,        DE_SLSH,                                        TD(TD_HOME),    KC_LEFT,         KC_DOWN,                       KC_RIGHT,       TD(TD_END),     KC_RSFT,
			KC_LCTL,                    DE_CIRC,        DE_PIPE,            DE_LBRC,        DE_RBRC,        DE_BSLS,        KC_NO,          KC_NO,          DE_ASTR,        DE_PLUS,         KC_BSLS,                       DE_EXLM,        DE_QUES,        KC_RCTL,
							            				KC_TRNS,            KC_TRNS,        KC_NO,          KC_NO,          KC_TRNS,        KC_LALT,        KC_DEL,         KC_TRNS,         KC_TRNS,                       DM_REC1
	),

	/* MACRO */
	[MACRO] = LAYOUT(
			KC_MUTE,          KC_NO,                      KC_NO,              KC_NO,          KC_NO,                  KC_NO,                                          KC_NO,              KC_NO,                      KC_NO,                      KC_NO,                      KC_NO,          KC_NO,
			KC_MNXT,          KC_NO,                      KC_NO,              KC_PGUP,        KC_NO,                  KC_NO,                                          KC_NO,              INTELLIJ_LAST_EDIT,         INTELLIJ_LINE_UP,           INTELLIJ_SHOW_USAGE,        KC_NO,          KC_NO,
			KC_MPLY,          INTELLIJ_ACTION_SEARCH,     KC_NO,              KC_PGDN,        POWERTOYS_TEXT_INSERT,  KC_NO,                                          INTELLIJ_PIN_TAB,   INTELLIJ_MOVE_BACKWARD,     INTELLIJ_LINE_DOWN,         INTELLIJ_MOVE_FORWARD,      KC_NO,          KC_NO,
			KC_MPRV,          KC_NO,                      KC_NO,              KC_NO,          KC_NO,                  KC_NO,          KC_NO,          KC_NO,          KC_NO,              INTELLIJ_COMMENT_LINE,      INTELLIJ_SHOW_IN_EXPLORER,  KC_NO,                      KC_NO,          KC_NO,
											              KC_TRNS,            KC_TRNS,        KC_TRNS,                KC_TRNS,        KC_TRNS,        KC_NO,          KC_NO,              KC_TRNS,                    KC_TRNS,                      KC_NO
	),


	[MOUSE] = LAYOUT(
		KC_NO,      KC_NO,      KC_NO,                    KC_NO,                  KC_NO,                  KC_NO,                                            KC_NO,      KC_NO,                      KC_NO,                  KC_NO,                  KC_NO,      KC_NO,
		KC_NO,      KC_NO,      QK_MOUSE_WHEEL_LEFT,      QK_MOUSE_WHEEL_UP,      QK_MOUSE_WHEEL_RIGHT,   KC_NO,                                            KC_NO,      KC_NO,                      QK_MOUSE_CURSOR_UP,     KC_NO,                  KC_NO,      KC_NO,
		KC_PGUP,    MS_ACL0,    MS_BTN1,                  QK_MOUSE_WHEEL_DOWN,    MS_BTN2,                MS_ACL1,                                          KC_NO,      QK_MOUSE_CURSOR_LEFT,       QK_MOUSE_CURSOR_DOWN,   QK_MOUSE_CURSOR_RIGHT,  MS_ACL1,      KC_NO,
		KC_NO,      KC_PGDN,    KC_NO,                    MS_BTN3,                KC_NO,                  KC_NO,               KC_NO,      KC_NO,      KC_NO,      KC_NO,                      KC_NO,                  KC_NO,                  KC_NO,      KC_NO,
					            KC_TRNS,                  KC_TRNS,                KC_TRNS,                KC_TRNS,                  KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,                    KC_TRNS,                KC_TRNS
	),

	/* FUNC */
	[FUNC] = LAYOUT(
			KC_NO,          KC_NO,          KC_NO,              KC_NO,          KC_NO,          KC_NO,                                              KC_NO,          KC_NO,          KC_PSLS,        KC_PAST,        KC_NO,        KC_NO,
			KC_NO,          KC_F1,          KC_F2,              KC_F3,          KC_F4,          KC_NO,                                              KC_PPLS,        KC_7,           KC_8,           KC_9,           KC_PMNS,        KC_NO,
			KC_LSFT,        KC_F5,          KC_F6,              KC_F7,          KC_F8,          KC_NO,                                              KC_DOT,         KC_4,           KC_5,           KC_6,           KC_0,           KC_LSFT,
			KC_LCTL,        KC_F9,          KC_F10,             KC_F11,         KC_F12,         KC_NO,          KC_NO,              KC_NO,          KC_PDOT,        KC_1,           KC_2,           KC_3,           KC_PEQL,        KC_LCTL,
											KC_TRNS,            KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,            KC_TRNS,        KC_NO,          KC_TRNS,        KC_TRNS,        KC_PENT
	)

};
