#include QMK_KEYBOARD_H

#define ______ KC_TRNS

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  LAYOUT_directional(
      KC_GESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, ______, KC_BSPC,
      KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_RBRC, KC_BSLS,
      MO(1), KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_ENT,
      KC_LSFT,         KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT, KC_UP, KC_DEL,
      KC_LCTL, KC_LGUI, KC_LALT, XXXXXXX, RSFT_T(KC_SPC), XXXXXXX, KC_RALT, MO(1), KC_LEFT, KC_DOWN, KC_RIGHT
      ),

  LAYOUT_directional(
      KC_GRV, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10, KC_F11, KC_F12, KC_TRNS, RESET,
      ______, KC_HOME, KC_PGUP, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______,
      ______, KC_END, KC_PGDN, ______, ______, KC_BSPC, KC_ENT, ______, ______, ______, ______, ______,
      KC_CAPS, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, KC_BTN1, KC_MS_U, KC_BTN2,
      ______, ______, ______, XXXXXXX, KC_ESC, XXXXXXX, ______, ______, KC_MS_L, KC_MS_D, KC_MS_R
      ),
};
