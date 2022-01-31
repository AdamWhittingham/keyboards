/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

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
#include <stdio.h>

#define L_QWERTY 0
#define L_NUM 1
#define L_SYM 2
#define L_CTL 3

const uint16_t ESCCMD = MT(KC_LCMD, KC_ESC);
const uint16_t SHFENT = MT(MOD_LSFT, KC_ENT);

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [L_QWERTY] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,  KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                         KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_QUOT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,  ESCCMD,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LCMD,   MO(1),  KC_SPC,     SHFENT,   MO(2), KC_RALT
                                      //`--------------------------'  `--------------------------'

  ),

  [L_NUM] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_GRV,   KC_1 ,   KC_2 ,   KC_3 ,   KC_4 ,   KC_5 ,                        KC_6 ,   KC_7 ,   KC_8 ,   KC_9 ,    KC_0, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______,   KC_LT,   KC_GT, KC_LPRN, KC_RPRN,  KC_DQT,                      KC_EQL , KC_PLUS, KC_MINS, KC_ASTR, KC_SLSH, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_UNDS, XXXXXXX, XXXXXXX, XXXXXXX, KC_BSLS, _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,    _______,   MO(3), _______
                                      //`--------------------------'  `--------------------------'
  ),

  [L_SYM] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TAB, KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC,                      KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_MINS,  KC_EQL, KC_LBRC, KC_RBRC, KC_BSLS,  KC_GRV,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE, _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______,   MO(3), _______,    _______, _______, _______
                                      //`--------------------------'  `--------------------------'
  ),

  [L_CTL] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        RESET,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                        KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, XXXXXXX, XXXXXXX,                      XXXXXXX, KC_VOLU, KC_VOLD, KC_MUTE, XXXXXXX,  KC_F12,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD, XXXXXXX, XXXXXXX,                      XXXXXXX, KC_MPLY, KC_MNXT, KC_MPRV, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI, _______, _______,    _______, _______, _______
                                      //`--------------------------'  `--------------------------'
  )
};

#ifdef OLED_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (!is_keyboard_master()) {
    return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
  }
  return rotation;
}

void oled_render_layer_state(void) {
    oled_write_P(PSTR("Layer: "), false);
    switch (layer_state) {
        case 0: // L_QWERTY
            oled_write_ln_P(PSTR("QWERTY"), false);
            break;
        case 2: // L_NUM
            oled_write_ln_P(PSTR("NUMBER"), false);
            break;
        case 4: // L_SYM
            oled_write_ln_P(PSTR("SYMBOL"), false);
            break;
        case 8: // L_CTL
        case 8|2:
        case 8|4:
        case 8|4|2:
            oled_write_ln_P(PSTR("CONTROL"), false);
            break;
    }
}

char keylog_str[24] = {};

const char code_to_name[60] = {
    ' ', ' ', ' ', ' ', 'a', 'b', 'c', 'd', 'e', 'f',
    'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p',
    'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
    '1', '2', '3', '4', '5', '6', '7', '8', '9', '0',
    'R', 'E', 'B', 'T', '_', '-', '=', '[', ']', '\\',
    '#', ';', '\'', '`', ',', '.', '/', ' ', ' ', ' '};

void set_keylog(uint16_t keycode, keyrecord_t *record) {
  char name = ' ';
    if ((keycode >= QK_MOD_TAP && keycode <= QK_MOD_TAP_MAX) ||
        (keycode >= QK_LAYER_TAP && keycode <= QK_LAYER_TAP_MAX)) { keycode = keycode & 0xFF; }
  if (keycode < 60) {
    name = code_to_name[keycode];
  }

  // update keylog
  snprintf(keylog_str, sizeof(keylog_str), "%dx%d, k%2d : %c",
           record->event.key.row, record->event.key.col,
           keycode, name);
}

void oled_render_keylog(void) {
    oled_write(keylog_str, false);
}

void render_bootmagic_status(bool status) {
    /* Show Ctrl-Gui Swap options */
    static const char PROGMEM logo[][2][3] = {
        {{0x97, 0x98, 0}, {0xb7, 0xb8, 0}},
        {{0x95, 0x96, 0}, {0xb5, 0xb6, 0}},
    };
    if (status) {
        oled_write_ln_P(logo[0][0], false);
        oled_write_ln_P(logo[0][1], false);
    } else {
        oled_write_ln_P(logo[1][0], false);
        oled_write_ln_P(logo[1][1], false);
    }
}

void oled_render_logo(void) {
    static const char PROGMEM crkbd_logo[] = {
        0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8a, 0x8b, 0x8c, 0x8d, 0x8e, 0x8f, 0x90, 0x91, 0x92, 0x93, 0x94,
        0xa0, 0xa1, 0xa2, 0xa3, 0xa4, 0xa5, 0xa6, 0xa7, 0xa8, 0xa9, 0xaa, 0xab, 0xac, 0xad, 0xae, 0xaf, 0xb0, 0xb1, 0xb2, 0xb3, 0xb4,
        0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0xc5, 0xc6, 0xc7, 0xc8, 0xc9, 0xca, 0xcb, 0xcc, 0xcd, 0xce, 0xcf, 0xd0, 0xd1, 0xd2, 0xd3, 0xd4,
        0};
    oled_write_P(crkbd_logo, false);
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        oled_render_layer_state();
        //oled_render_keylog();
    } else {
        oled_render_logo();
    }
    return false;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    set_keylog(keycode, record);
  }
  return true;
}
#endif // OLED_ENABLE

#ifdef RGBLIGHT_ENABLE
// Underglow LEDs (Left side, viewed from above)
// 2   1   0
// 3   4   5
//
// Keyboard LEDs (Left side)
//  23  18  17  10  9
//  22  19  16  11  8
//  21  20  15  12  7
//           14  13  6
//
// LEDs 24, 25, and 26 don't exist.
//
// Underglow LEDs (Right side, viewed from above)
// 27  28  29
// 32  31  30
//
// Keyboard LEDs (Right side)
//   36  37  44  45  50
//   35  38  43  46  49
//   34  39  42  47  48
//  33  40  41

const rgblight_segment_t PROGMEM layer_num_lights[] = RGBLIGHT_LAYER_SEGMENTS(
    {6, 1, HSV_CYAN},
    {13, 2, HSV_CYAN},
    {33, 1, HSV_CYAN},
    {40, 2, HSV_CYAN}
);

const rgblight_segment_t PROGMEM layer_sym_lights[] = RGBLIGHT_LAYER_SEGMENTS(
    {6, 1, HSV_PURPLE},
    {13, 2, HSV_PURPLE},
    {33, 1, HSV_PURPLE},
    {40, 2, HSV_PURPLE}
);

const rgblight_segment_t PROGMEM layer_ctl_lights[] = RGBLIGHT_LAYER_SEGMENTS(
    {6, 1, HSV_GREEN},
    {13, 2, HSV_GREEN},
    {33, 1, HSV_GREEN},
    {40, 2, HSV_GREEN}
);

const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    layer_num_lights,
    layer_sym_lights,
    layer_ctl_lights
);

void keyboard_post_init_user(void) {
    rgblight_layers = my_rgb_layers;
}

// Activate the rgb layer according to the active keyboard layer
layer_state_t layer_state_set_user(layer_state_t state) {
  rgblight_set_layer_state(L_NUM, layer_state_cmp(state, L_NUM));
  rgblight_set_layer_state(L_SYM, layer_state_cmp(state, L_SYM));
  rgblight_set_layer_state(L_CTL, layer_state_cmp(state, L_CTL));

  switch (layer_state) {
      case L_NUM:
          break;
      case L_SYM:
          break;
      case L_CTL:
          break;
      default:
          break;
  }

  return state;
}
#endif // RGBLIGHT_ENABLE
