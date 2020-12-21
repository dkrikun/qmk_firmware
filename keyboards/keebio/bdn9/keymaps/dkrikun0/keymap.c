#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
        G(KC_Q),     G(C(KC_SPACE)), TG(1),
        G(KC_ENTER), G(KC_K),        G(KC_C),
        G(KC_H),     G(KC_J),        G(KC_L)
    ),
    [1] = LAYOUT(
        _______,    G(KC_F),    _______,
        G(KC_TAB),  G(S(KC_K)), G(KC_I),
        G(S(KC_H)), G(S(KC_J)), G(S(KC_L))
    )
};

int layer=0;

void encoder_update_user(uint8_t index, bool clockwise) {
    if(layer == 0)
        tap_code16(G(clockwise? KC_RIGHT : KC_LEFT));
    else
        tap_code16(G(S(clockwise? KC_COMMA : KC_DOT)));
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

