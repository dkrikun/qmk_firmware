/* Copyright 2019 Thomas Baart <thomas@splitkb.com>
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

#ifdef COMBO_ENABLE
enum combos {
    DSFT_CAPS = 0,
    HOME_END,
};

const uint16_t PROGMEM dsft_combo[] = { KC_LSFT, KC_RSFT, COMBO_END };
const uint16_t PROGMEM home_end_combo[] = { KC_HOME, KC_END, COMBO_END };

combo_t keycombos[COMBO_COUNT] = {
    [DSFT_CAPS] = COMBO(dsft_combo, KC_CAPSLOCK),
    [HOME_END] = COMBO(home_end_combo, KC_AUDIO_MUTE),
};
#endif

enum my_keycodes {
    KC_ACL_UP = SAFE_RANGE,
    KC_ACL_DN
};


#if 0
// cur_dance() by Daniel Gordon
enum {
  SINGLE_TAP = 1,
  SINGLE_HOLD = 2,
  DOUBLE_TAP = 3,
  DOUBLE_HOLD = 4,
  DOUBLE_SINGLE_TAP = 5, //send two single taps
  TRIPLE_TAP = 6,
  TRIPLE_HOLD = 7,
  OTHER = 8
};

int cur_dance (qk_tap_dance_state_t *state) {
  if (state->count == 1) {
    //If count = 1, and it has been interrupted - it doesn't matter if it is pressed or not: Send SINGLE_TAP
    if (state->interrupted) {
      return SINGLE_TAP;
    }
    else {
      if (!state->pressed) return SINGLE_TAP;
      else return SINGLE_HOLD;
    }
  }
  //If count = 2, and it has been interrupted - assume that user is trying to type the letter associated
  //with single tap.
  else if (state->count == 2) {
    if (state->interrupted) return DOUBLE_SINGLE_TAP;
    else if (state->pressed) return DOUBLE_HOLD;
    else return DOUBLE_TAP;
  }
  else if ((state->count == 3) && ((state->interrupted) || (!state->pressed))) return TRIPLE_TAP;
  else if (state->count == 3) return TRIPLE_HOLD;
  else return OTHER; //magic number. At some point this method will expand to work for more presses
}
#endif

enum tap_dances {
    TD_MINUS_UNDS = 0,
    TD_LEFT_PAR,
    TD_RGHT_PAR,
    TD_SLSH,
    TD_QUOTE,
    TD_DOT_COMMA,
    TD_SCLN,
    TD_EXCLAIM,
    TD_GTLT,
    TD_DHOME,
    TD_DEND,
};

qk_tap_dance_action_t tap_dance_actions[] = {
    [TD_MINUS_UNDS] = ACTION_TAP_DANCE_DOUBLE(KC_MINUS, KC_UNDERSCORE),
    [TD_LEFT_PAR] = ACTION_TAP_DANCE_DOUBLE(KC_LBRC, KC_LCBR),
    [TD_RGHT_PAR] = ACTION_TAP_DANCE_DOUBLE(KC_RBRC, KC_RCBR),
    [TD_SLSH] = ACTION_TAP_DANCE_DOUBLE(KC_SLASH, KC_BSLASH),
    [TD_QUOTE] = ACTION_TAP_DANCE_DOUBLE(KC_QUOTE, KC_DQUO),
    [TD_DOT_COMMA] = ACTION_TAP_DANCE_DOUBLE(KC_COMMA, KC_DOT),
    [TD_SCLN] = ACTION_TAP_DANCE_DOUBLE(KC_SCLN, KC_COLN),
    [TD_EXCLAIM] = ACTION_TAP_DANCE_DOUBLE(KC_EXLM, KC_QUES),
    [TD_GTLT] = ACTION_TAP_DANCE_DOUBLE(KC_LT, KC_GT),
    [TD_DHOME] = ACTION_TAP_DANCE_DOUBLE(KC_HOME, LCTL(KC_HOME)),
    [TD_DEND] = ACTION_TAP_DANCE_DOUBLE(KC_HOME, LCTL(KC_END)),
};

#define XX_MINS TD(TD_MINUS_UNDS)
#define XX_LPAR TD(TD_LEFT_PAR)
#define XX_RPAR TD(TD_RGHT_PAR)
#define XX_SLSH TD(TD_SLSH)
#define XX_QUOT TD(TD_QUOTE)
#define XX_DOT  TD(TD_DOT_COMMA)
#define XX_SCLN TD(TD_SCLN)
#define XX_EXLM TD(TD_EXCLAIM)
#define XX_GT   TD(TD_GTLT)
#define XX_HOME TD(TD_DHOME)
#define XX_END  TD(TD_DEND)

// TODO define double-tap on raise/lower to osl or win+layer
// TODO experiment with double-tap and hold
// TODO define oled behaviours
// TODO define backlight
// TODO map home-end combo
// TODO create windows/linux specific keymaps
// TODO think how to facilitate:
//  alt-tab, shift-alt-tab
//  <mod>-<number>

enum layers {
    _QWERTY = 0,
    _LOWER,
    _RAISE,
    _NAV,
    _MOUSE,
    _ADJUST,
};

#define XX_LSPC  LSFT_T(KC_SPC)
#define XX_RSPC  RSFT_T(KC_SPC)
#define XX_G   LT(_MOUSE, KC_G)
#define XX_F   LT(_NAV, KC_F)
#define XX_D    LGUI_T(KC_D)
#define XX_C    LCTL_T(KC_C)
#define XX_V    LALT_T(KC_V)
#define XX_B    LT(_RAISE, KC_B)
#define XX_N    LT(_LOWER, KC_N)
#define XX_M    RALT_T(KC_M)
#define XX_COMM RCTL_T(KC_COMM)
#define XX_K    RGUI_T(KC_K)
#define XX_F12  LGUI_T(KC_F12)
#define XX_F8   LGUI_T(KC_F8)
#define XX_PSCR LCTL_T(KC_PSCR)
#define XX_SLCK LALT_T(KC_SLCK)
#define YY_MINS LGUI_T(KC_MINS)
#define XX_PLUS RCTL_T(KC_PLUS)
#define XX_ASTR RGUI_T(KC_ASTR)
#define XX_8    RGUI_T(KC_8)
#define XX_RAI MO(_RAISE)
#define XX_LOW MO(_LOWER)
#define YY_QUOT RGUI_T(KC_QUOT)
#define YY_EXLM LGUI_T(KC_EXLM)
#define XX_DLR LALT_T(KC_DLR)


uint8_t macl = 0;

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {


 /* Base Layer: QWERTY
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * | Esc    |   Q  |   W  |   E  |   R  |   T  |                              |   Y  |   U  |   I  |   O  |   P  | PgUp   |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * | Tab    |   A  |   S  | ^ D  |   F* |   G* |                              |   H  |   J  | ^ K  |   L  | ;  : | PgDn   |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * | Ctrl   |   Z  |   X  | ^ C  | ^ V  |   B  |      | Esc  |  | Lead |      |   N  | ^ M  | ^ ,< |  .>  | /  ? | Del    |
 * `----------------------+------+------+------|      |------|  |------|      |------+------+------+----------------------'
 *                        | Home | Raise| Lower| Space| Enter|  | Bspc | Space| Lower| Raise| End  |
 *                        |      |      |      | Shift|      |  |      | Shift|      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_QWERTY] = LAYOUT(
      KC_ESC,  KC_Q,  KC_W,   KC_E,    KC_R,   KC_T,                                       KC_Y,   KC_U,   KC_I,    KC_O,    KC_P,     KC_PGUP,
      KC_TAB,  KC_A,  KC_S,   XX_D,    XX_F,   XX_G,                                       KC_H,   KC_J,   XX_K,    KC_L,    KC_SCLN,  KC_PGDN,
      KC_LCTL, KC_Z,  KC_X,   XX_C,    XX_V,   KC_B,   XXXXXXX, KC_ESC,  KC_LEAD, XXXXXXX, KC_N,   XX_M,   XX_COMM, KC_DOT,  XX_SLSH,  KC_DEL,
                              XX_HOME, XX_RAI, XX_LOW, XX_LSPC, KC_ENT,  KC_BSPC, XX_RSPC, XX_LOW, XX_RAI, XX_END
    ),
/*
 * Lower Layer: Symbols
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |      |      |  ~   |   #  |  %   |                              |  =   |  +   |  "   |      |      |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |      |  _   |  ^-  |   *  |  \   |                              |  /   |  |   |  ^'  | !    |      |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |      |      | Ctrl |  ^d  |  ^   |      |  [   |  |   ]  |      |  &   | Alt  | Ctrl |      |      |        |
 * `----------------------+------+------+------| (    |------|  |------|    ) |------+------+------+----------------------'
 *                        |      |      |      |      |  {   |  |   }  |      |      |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_LOWER] = LAYOUT(
      _______, _______, KC_DLR,  KC_TILD, KC_HASH, KC_PERC,                                     KC_EQL,  KC_PLUS, KC_DQUO, _______, _______, _______,
      _______, _______, KC_UNDS, YY_MINS, KC_ASTR, KC_BSLS,                                     KC_SLSH, KC_PIPE, YY_QUOT, KC_EXLM, _______, _______,
      _______, _______, _______, KC_LCTL, KC_LALT,  KC_CIRC, XXXXXXX, KC_LBRC, KC_RBRC, XXXXXXX, KC_AMPR, KC_RALT, KC_RCTL, _______, _______, _______,
                                 _______, _______, _______, KC_LPRN, KC_LCBR, KC_RCBR, KC_RPRN, _______, _______, _______
    ),
/*
 * Raise Layer: Number keys, function keys, misc. keys, media, arithmetic symbols
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        | F1   | F2   | F3   | F4   | F5   |                              |  1   |  2   |  3   |  4   |  5   |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        | F6   | F7   | ^F8  | F9   | F10  |                              |  6   |  7   |  ^8  |  9   |      |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        | F11  | F12  |^PrSc |^ScLk |Insert|      |      |  |      |      |  0   | Alt  | Ctrl |      |      |        |
 * `----------------------+------+------+------|      |------|  |------|      |------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_RAISE] = LAYOUT(
      _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                                       KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    _______,
      _______, KC_F6,   KC_F7,   XX_F8,   KC_F9,   KC_F10,                                      KC_6,    KC_7,    XX_8,    KC_9,    _______, _______,
      _______, KC_F11,  KC_F12,  XX_PSCR, XX_SLCK, KC_INS,  XXXXXXX, KC_PGUP, KC_HOME, XXXXXXX, KC_0,    KC_RALT, KC_RCTL, _______, _______, _______,
                                 _______, _______, _______, _______, KC_PGDN, KC_END,  _______, _______, _______, _______
    ),
/*
 * Navigation Layer
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |      |      |      |      |      |                              |      |      |      |      | Home | PgUp   |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |      |      | Gui  |      |      |                              |      |      | Up   |      | End  | PgDn   |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |      |      | Ctrl | Alt  |      |      |      |  |      |      |      | Left | Down | Right|      |        |
 * `----------------------+------+------+------|      |------|  |------|      |------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_NAV] = LAYOUT(
      _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, KC_HOME, KC_PGUP, _______,
      _______, _______, _______, KC_LGUI, _______, _______,                                     _______, _______, KC_UP,   KC_END,  KC_PGDN, _______,
      _______, _______, _______, KC_LCTL, KC_LALT, _______, XXXXXXX, _______, _______, XXXXXXX, _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______,
                                 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),
/*
 * Mouse Layer
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |                              |      |      | Up   |      |      |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      | AclUp|  | Wup  |      |      | Left | Down | Right|      |        |
 * `----------------------+------+------+------| BTN2 |------|  |------| BTN1 |------+------+------+----------------------'
 *                        |      |      |      |      | AclDn|  | Wdn  |      | BTN3 |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_MOUSE] = LAYOUT(
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                                       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
      XXXXXXX, XXXXXXX, XXXXXXX, KC_LGUI, XXXXXXX, XXXXXXX,                                       XXXXXXX, XXXXXXX, KC_MS_U, XXXXXXX, XXXXXXX, XXXXXXX,
      XXXXXXX, XXXXXXX, XXXXXXX, KC_LCTL, KC_LALT, XXXXXXX, XXXXXXX, KC_ACL_UP, KC_WH_U, XXXXXXX, XXXXXXX, KC_MS_L, KC_MS_D, KC_MS_R, XXXXXXX, XXXXXXX,
                                 XXXXXXX, XXXXXXX, XXXXXXX, KC_BTN1, KC_ACL_DN, KC_WH_D, KC_BTN2, KC_BTN3, XXXXXXX, XXXXXXX
    ),
/*
 * Adjust Layer: RGB, configuration, media
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |      |      |      | VAI  | TOG  |                              |      |      |      |      |      |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |      |      |      | VAD  |      |      |      |  |      |      |      |      |      |      |      |        |
 * `----------------------+------+------+------|      |------|  |------|      |------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_ADJUST] = LAYOUT(
      _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______,  _______,
      _______, _______, _______, _______, RGB_VAI, RGB_TOG,                                     _______, _______, _______, _______, _______,  _______,
      _______, _______, _______, _______, RGB_VAD, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                                 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),
};

layer_state_t layer_state_set_user(layer_state_t state) {
    switch(biton(state)) {
        case _LOWER:
            rgblight_sethsv_noeeprom_teal();
            break;
        case _RAISE:
            rgblight_sethsv_noeeprom_purple();
            break;
        case _NAV:
            rgblight_sethsv_noeeprom_gold();
            break;
        case _MOUSE:
            rgblight_sethsv_noeeprom_chartreuse();
            break;
        default:
            rgblight_sethsv_noeeprom_white();
    }

    return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

void keyboard_post_init_user(void) {
    rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_LIGHT);
    rgblight_sethsv_noeeprom_white();
}

#ifdef OLED_DRIVER_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    return OLED_ROTATION_180;
}

static void render_kyria_logo(void) {
    static const char PROGMEM kyria_logo[] = {
        0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,128,128,192,224,240,112,120, 56, 60, 28, 30, 14, 14, 14,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7, 14, 14, 14, 30, 28, 60, 56,120,112,240,224,192,128,128,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  0,  0,  0,  0,192,224,240,124, 62, 31, 15,  7,  3,  1,128,192,224,240,120, 56, 60, 28, 30, 14, 14,  7,  7,135,231,127, 31,255,255, 31,127,231,135,  7,  7, 14, 14, 30, 28, 60, 56,120,240,224,192,128,  1,  3,  7, 15, 31, 62,124,240,224,192,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  0,240,252,255, 31,  7,  1,  0,  0,192,240,252,254,255,247,243,177,176, 48, 48, 48, 48, 48, 48, 48,120,254,135,  1,  0,  0,255,255,  0,  0,  1,135,254,120, 48, 48, 48, 48, 48, 48, 48,176,177,243,247,255,254,252,240,192,  0,  0,  1,  7, 31,255,252,240,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,255,255,255,  0,  0,  0,  0,  0,254,255,255,  1,  1,  7, 30,120,225,129,131,131,134,134,140,140,152,152,177,183,254,248,224,255,255,224,248,254,183,177,152,152,140,140,134,134,131,131,129,225,120, 30,  7,  1,  1,255,255,254,  0,  0,  0,  0,  0,255,255,255,  0,  0,  0,  0,255,255,  0,  0,192,192, 48, 48,  0,  0,240,240,  0,  0,  0,  0,  0,  0,240,240,  0,  0,240,240,192,192, 48, 48, 48, 48,192,192,  0,  0, 48, 48,243,243,  0,  0,  0,  0,  0,  0, 48, 48, 48, 48, 48, 48,192,192,  0,  0,  0,  0,  0,
        0,  0,  0,255,255,255,  0,  0,  0,  0,  0,127,255,255,128,128,224,120, 30,135,129,193,193, 97, 97, 49, 49, 25, 25,141,237,127, 31,  7,255,255,  7, 31,127,237,141, 25, 25, 49, 49, 97, 97,193,193,129,135, 30,120,224,128,128,255,255,127,  0,  0,  0,  0,  0,255,255,255,  0,  0,  0,  0, 63, 63,  3,  3, 12, 12, 48, 48,  0,  0,  0,  0, 51, 51, 51, 51, 51, 51, 15, 15,  0,  0, 63, 63,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 48, 48, 63, 63, 48, 48,  0,  0, 12, 12, 51, 51, 51, 51, 51, 51, 63, 63,  0,  0,  0,  0,  0,
        0,  0,  0,  0, 15, 63,255,248,224,128,  0,  0,  3, 15, 63,127,255,239,207,141, 13, 12, 12, 12, 12, 12, 12, 12, 30,127,225,128,  0,  0,255,255,  0,  0,128,225,127, 30, 12, 12, 12, 12, 12, 12, 12, 13,141,207,239,255,127, 63, 15,  3,  0,  0,128,224,248,255, 63, 15,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  0,  0,  0,  0,  3,  7, 15, 62,124,248,240,224,192,128,  1,  3,  7, 15, 30, 28, 60, 56,120,112,112,224,224,225,231,254,248,255,255,248,254,231,225,224,224,112,112,120, 56, 60, 28, 30, 15,  7,  3,  1,128,192,224,240,248,124, 62, 15,  7,  3,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  1,  3,  7, 15, 14, 30, 28, 60, 56,120,112,112,112,224,224,224,224,224,224,224,224,224,224,224,224,224,224,224,224,112,112,112,120, 56, 60, 28, 30, 14, 15,  7,  3,  1,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0
    };
    oled_write_raw_P(kyria_logo, sizeof(kyria_logo));
}

#if 0
static void render_qmk_logo(void) {
  static const char PROGMEM qmk_logo[] = {
    0x80,0x81,0x82,0x83,0x84,0x85,0x86,0x87,0x88,0x89,0x8a,0x8b,0x8c,0x8d,0x8e,0x8f,0x90,0x91,0x92,0x93,0x94,
    0xa0,0xa1,0xa2,0xa3,0xa4,0xa5,0xa6,0xa7,0xa8,0xa9,0xaa,0xab,0xac,0xad,0xae,0xaf,0xb0,0xb1,0xb2,0xb3,0xb4,
    0xc0,0xc1,0xc2,0xc3,0xc4,0xc5,0xc6,0xc7,0xc8,0xc9,0xca,0xcb,0xcc,0xcd,0xce,0xcf,0xd0,0xd1,0xd2,0xd3,0xd4,0};

  oled_write_P(qmk_logo, false);
}
#endif

static void render_status(void) {
    oled_write_P(PSTR("Layer: "), false);
    switch (get_highest_layer(layer_state)) {
        case _QWERTY:
            oled_write_P(PSTR("QWE\n"), false);
            break;
        case _LOWER:
            oled_write_P(PSTR("SYM\n"), false);
            break;
        case _RAISE:
            oled_write_P(PSTR("NUM\n"), false);
            break;
        case _NAV:
            oled_write_P(PSTR("NAV\n"), false);
            break;
        case _MOUSE:
            oled_write_P(PSTR("MOU\n"), false);
            break;
        case _ADJUST:
            oled_write_P(PSTR("ADJ\n"), false);
            break;
        default:
            oled_write_P(PSTR("UND\n"), false);
    }

#if 0
    // Host Keyboard LED Status
    uint8_t led_usb_state = host_keyboard_leds();
    oled_write_P(IS_LED_ON(led_usb_state, USB_LED_NUM_LOCK) ? PSTR("NUMLCK ") : PSTR("       "), false);
    oled_write_P(IS_LED_ON(led_usb_state, USB_LED_CAPS_LOCK) ? PSTR("CAPLCK ") : PSTR("       "), false);
    oled_write_P(IS_LED_ON(led_usb_state, USB_LED_SCROLL_LOCK) ? PSTR("SCRLCK ") : PSTR("       "), false);
#endif

    oled_write_P(macl == 0? PSTR("M0\n") :
                 macl == 1? PSTR("M1\n") :
                            PSTR("M2\n"), false);
}

void oled_task_user(void) {
    if (is_keyboard_master()) {
        render_status();
    } else {
        render_kyria_logo();
    }
}
#endif

bool process_record_user(uint16_t keycode, keyrecord_t* record) {
    switch(keycode) {
        case KC_ACL_UP:
            if (record->event.pressed) {
                switch(macl) {
                    case 2: break;
                    case 0: macl = 1; tap_code(KC_ACL1); break;
                    case 1: macl = 2; tap_code(KC_ACL2); break;
                }
            }

            return false;
        case KC_ACL_DN:
            if (record->event.pressed) {
                switch(macl) {
                    case 0: break;
                    case 2: macl = 1; tap_code(KC_ACL1); break;
                    case 1: macl = 0; tap_code(KC_ACL0); break;
                }
            }
            return false;
    }

    return true;
}

LEADER_EXTERNS();

void matrix_scan_user(void) {
    LEADER_DICTIONARY() {
        leading = false;
        leader_end();

        SEQ_ONE_KEY(KC_C) {
            tap_code16(C(KC_C));
        }

        SEQ_ONE_KEY(KC_V) {
            tap_code16(C(KC_V));
        }

        SEQ_ONE_KEY(KC_X) {
            tap_code16(C(KC_X));
        }

        SEQ_ONE_KEY(KC_T) {
            tap_code16(C(KC_T));
        }

        SEQ_ONE_KEY(KC_A) {
            tap_code16(C(KC_A));
        }

        SEQ_TWO_KEYS(KC_A, KC_F) {
            tap_code16(C(KC_F4));
        }

        SEQ_THREE_KEYS(KC_C, KC_A, KC_D) {
            tap_code16(LCA(KC_DEL));
        }
    }
}

