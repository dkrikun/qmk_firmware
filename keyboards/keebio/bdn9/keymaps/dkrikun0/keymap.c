#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
        LGUI(KC_Q), KC_F7, TG(1),
        KC_F4, KC_F5, KC_F6,
        KC_F1, KC_F2, KC_F3
    ),
    [1] = LAYOUT(
        _______, KC_F14, _______,
        KC_F11, KC_F12, KC_F13,
        KC_F8, KC_F9, KC_F10
    )
};

int layer=0;

void encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        if (clockwise) {
            tap_code16(LGUI(KC_COMMA));
        } else {
            tap_code16(LGUI(KC_DOT));
        }
    }
}

layer_state_t layer_state_set_user(layer_state_t state) {
    switch (get_highest_layer(state)) {
        case 0:
            layer=0;
            backlight_disable();
            break;
        case 1:
            layer=1;
            backlight_enable();
            break;
    }
   return state;
}

