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
#pragma once

// Enabling this option changes the startup behavior to listen for an
// active USB communication to delegate which part is master and which
// is slave. With this option enabled and theres’s USB communication,
// then that half assumes it is the master, otherwise it assumes it
// is the slave.
//
// I've found this helps with some ProMicros where the slave does not boot
// #define SPLIT_USB_DETECT
// #define SPLIT_USB_TIMEOUT 5000
// #define MASTER_LEFT


#define NO_MUSIC_MODE
#define NO_ACTION_ONESHOT
#define NO_ACTION_TAPPING
#undef LOCKING_SUPPORT_ENABLE
#undef LOCKING_RESYNC_ENABLE
#define LAYER_STATE_8BIT


// Caps Word
#define BOTH_SHIFTS_TURNS_ON_CAPS_WORD
#define CAPS_WORD_INVERT_ON_SHIFT
#define CAPS_WORD_IDLE_TIMEOUT 3000

// Tap Dance
#define TAPPING_TERM 200

// Leader
#define LEADER_PER_KEY_TIMING
#define LEADER_TIMEOUT 350

// Tri Layer
#define TRI_LAYER_LOWER_LAYER 1
#define TRI_LAYER_UPPER_LAYER 3
#define TRI_LAYER_ADJUST_LAYER 4

// Mouse 

// #define MK_COMBINED
// #define MOUSEKEY_DELAY 5
// #define MOUSEKEY_MAX_SPEED 3
// #define MOUSEKEY_MOVE_DELTA 4
// #define MOUSEKEY_TIME_TO_MAX 200
// #define MOUSEKEY_INTERVAL 6
// #define MOUSEKEY_FRICTION 40

// #define MK_KINETIC_SPEED
// #define MOUSEKEY_INTERVAL 8
// #define MOUSEKEY_MOVE_DELTA 8
// #define MOUSEKEY_INITIAL_SPEED 50
// #define MOUSEKEY_BASE_SPEED 2500
// #define MOUSEKEY_DECELERATED_SPEED 600
// #define MOUSEKEY_ACCELERATED_SPEED 250


#define MOUSEKEY_INERTIA
#define MOUSEKEY_TIME_TO_MAX 85
#define MOUSEKEY_MAX_SPEED 18
#define MOUSEKEY_DELAY 100
#define MOUSEKEY_INTERVAL 8
#define MOUSEKEY_FRICTION 32

// Combo
#define COMBO_TERM 50


// Dynamic Macro
#define DYNAMIC_MACRO_NO_NESTING 

// Key Override
#define DUMMY_MOD_NEUTRALIZER_KEYCODE KC_F18
#define MODS_TO_NEUTRALIZE { MOD_BIT(KC_LEFT_ALT), MOD_BIT(KC_LEFT_GUI), MOD_BIT(KC_RSFT) }


