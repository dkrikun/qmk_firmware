/*
Copyright 2019 Ethan Durrant (emdarcher)

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

#include QMK_KEYBOARD_H


enum layers {
    BASE = 0,
    FN = 1,
    SPC = 2
};

#ifdef USE_SHPACE
#define XX_SPC RSFT_T(KC_SPC)
#else
#define XX_SPC KC_SPC
#endif

#define SHPACE RSFT_T(KC_SPC)
#ifdef SWITCH_CAPS_CTRL
#define XX_CAPS KC_LCTL
#define XX_LCTL MO(FN)
#else
#define XX_CAPS MO(FN)
#define XX_LCTL KC_LCTL
#endif

#ifdef SWITCH_BSPC_BSLS
#define XX_BSPC KC_BSLS
#define XX_BSLS KC_BSPC
#else
#define XX_BSPC KC_BSPC
#define XX_BSLS KC_BSLS
#endif

#ifdef SWITCH_GUI_ALT
#define XX_LGUI KC_LALT
#define XX_LALT KC_LGUI
#else
#define XX_LGUI KC_LGUI
#define XX_LALT KC_LALT
#endif

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [BASE] = LAYOUT_60_ansi(
        KC_GESC, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,   KC_6,     KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  XX_BSPC,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,   KC_Y,     KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, XX_BSLS,
        XX_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,   KC_H,     KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,   KC_N,     KC_M,    KC_COMM, KC_DOT,  KC_SLSH,                   KC_RSFT,
        XX_LCTL, XX_LGUI, XX_LALT,                   XX_SPC,                                      KC_RALT, KC_RGUI, MO(SPC), KC_RCTL
    ),
    [FN] = LAYOUT_60_ansi(
        KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______,
        _______, _______, KC_UP,   _______, _______, _______, _______, KC_HOME, KC_PGUP, _______, _______, _______, _______, _______,
        _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______, _______, KC_END,  KC_PGDN, _______, _______,          _______, _______,
        KC_CAPS, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,                   _______,
        _______, _______, _______,                   KC_ESC,                                      _______, _______, _______, _______
    ),
    [SPC] = LAYOUT_60_ansi(
        KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______,
        _______, _______, KC_UP,   _______, _______, _______, _______, KC_HOME, KC_PGUP, _______, _______, _______, _______, RESET,
        _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______, _______, KC_END,  KC_PGDN, _______, _______,          _______, _______,
        KC_CAPS, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,                   _______,
        _______, _______, _______,                   KC_ESC,                                      _______, _______, _______, _______
    ),
};

layer_state_t layer_state_set_user(layer_state_t state) {
    switch(biton(state)) {
        case BASE:
            backlight_disable();
            break;
        case FN:
        case SPC:
            backlight_level(4);
            backlight_enable();
            break;
    }

    return state;
}

