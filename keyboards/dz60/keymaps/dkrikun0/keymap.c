#include QMK_KEYBOARD_H

#define _BL 0
#define _FL 1
#define _RGBL 2

#define XX_LSFT OSM(MOD_LSFT)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_BL] = LAYOUT(
        KC_GESC, KC_1,    KC_2,    KC_3,   KC_4,   KC_5,   KC_6,    KC_7,    KC_8,  KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_NO,  KC_BSPC,
        KC_TAB,  KC_Q,    KC_W,    KC_E,   KC_R,   KC_T,   KC_Y,    KC_U,    KC_I,  KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,
        MO(_FL), KC_A,    KC_S,    KC_D,   KC_F,   KC_G,   KC_H,    KC_J,    KC_K,  KC_L,    KC_SCLN, KC_QUOT, KC_ENT,
        XX_LSFT, KC_NO,   KC_Z,    KC_X,   KC_C,   KC_V,   KC_B,    KC_N,    KC_M,  KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, KC_NO,
        KC_LCTL, KC_LGUI, KC_LALT, KC_SPC, KC_SPC, KC_SPC, KC_RALT, TT(_FL), KC_NO, RGB_TOG, KC_RCTL),

    [_FL] = LAYOUT(
        KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,    KC_F10,  KC_F11,  KC_F12,  _______, KC_DEL,
        _______, KC_MINS, KC_EQL,  _______, _______, _______, _______, KC_PGUP, KC_UP,   KC_PGDN,  KC_PSCR, _______, KC_SLCK, RESET,
        _______, _______, _______, _______, _______, _______, KC_HOME, KC_LEFT, KC_DOWN, KC_RIGHT, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, KC_END,  _______,  _______, _______, KC_BSLS, _______, _______,
        _______, _______, _______, KC_BSPC, KC_BSPC, KC_BSPC, KC_BSPC, _______, _______, _______,  _______),

    #if 0
    [_RGBL] = LAYOUT(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD, _______, _______, _______, _______, RESET,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______),
    #endif
};

// static, white light by default
void keyboard_post_init_user(void) {
    rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_LIGHT);
    rgblight_sethsv_noeeprom_white();
}

// set red light upon reset upcode
bool process_record_user(uint16_t keycode, keyrecord_t* record) {
    switch(keycode) {
        case RESET:
            rgblight_sethsv_noeeprom_red();
            return true;

        default:
            return true;
    }
}


// change light color upon layer toggle
uint32_t layer_state_set_user(uint32_t state) {
    switch(biton32(state)) {
        case _FL:
            rgblight_sethsv_noeeprom_purple();
            break;
        default:
            rgblight_sethsv_noeeprom_white();

    }
    return state;
}

// leader, disabled
#if 0
LEADER_EXTERNS();

void matrix_scan_user(void) {
    LEADER_DICTIONARY() {
        leading = false;
        leader_end();
        SEQ_TWO_KEYS(KC_R, KC_R) {
            rgblight_toggle();
        }

        SEQ_THREE_KEYS(KC_R, KC_S, KC_T) {
            rgblight_enable_noeeprom();
            rgblight_mode_noeeprom(1);
            rgblight_sethsv_noeeprom(1, 255, 255);
            eeconfig_init();
            reset_keyboard();
        }

        SEQ_THREE_KEYS(KC_A, KC_N, KC_Y) {
            tap_random_base64();
        }
    }
}
#endif

