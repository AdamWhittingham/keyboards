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

const uint16_t ESCCMD = CMD_T(KC_ESC);
const uint16_t SHFENT = MT(MOD_LSFT, KC_ENT);
const uint16_t PLYNXT = MT(KC_MPLY, KC_MNXT);
const uint16_t SPCCMD = MT(MOD_LGUI, KC_SPC);
const uint16_t ALFRED = LCMD(KC_SPC);
const uint16_t MODSFT = OSM(MOD_LSFT);

// Rectangle window sizing
const uint16_t WINL = LAG(KC_LEFT);
const uint16_t WINR = LAG(KC_RIGHT);
const uint16_t WINU = LAG(KC_UP);
const uint16_t WIND = LAG(KC_DOWN);
const uint16_t WINF = LAG(KC_F);
// MacOS Next/Prev window for app
const uint16_t WINN = LCMD(KC_GRV);
const uint16_t WINP = LSG(KC_GRV);

// App switching
const uint16_t WEB = MEH(KC_W);
const uint16_t CAL = MEH(KC_C);
const uint16_t NOTES = MEH(KC_N);
const uint16_t TERM = MEH(KC_T);
const uint16_t SLACK = MEH(KC_S);
const uint16_t ZOOM = MEH(KC_Z);

// Tab switching
const uint16_t TAB_N = LCTL(KC_TAB);
const uint16_t TAB_P = LCTL(LSFT(KC_TAB));

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  // QWERTY Layer - normal typing
  [0] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,  KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                         KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_QUOT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,  ESCCMD,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                           OSL(3),   MO(2),  SPCCMD,     SHFENT,   MO(1), KC_LALT
                                      //`--------------------------'  `--------------------------'
  ),

  // NUMSYM Layer - Numbers and symbols
  [1] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_GRV,   KC_1 ,   KC_2 ,   KC_3 ,   KC_4 ,   KC_5 ,                        KC_6 ,   KC_7 ,   KC_8 ,   KC_9 ,    KC_0,  KC_DEL,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_LBRC,                      KC_RBRC, KC_MINS,  KC_EQL, KC_BSLS, XXXXXXX, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       MODSFT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,    _______, _______, _______
                                      //`--------------------------'  `--------------------------'
  ),

  // CONTROL Layer - PC & Keyboard controls
  [2] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_GRV,    WINP,    WINN, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_HOME, KC_PGUP,   KC_UP, KC_PGDN,   TAB_N,  KC_DEL,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______,    WINL,    WIND,    WINU,    WINR,    WINF,                       KC_END, KC_LEFT, KC_DOWN,KC_RIGHT,   TAB_P, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_MUTE,  PLYNXT, KC_VOLD, KC_VOLU, XXXXXXX, _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,    _______, _______, _______
                                      //`--------------------------'  `--------------------------'
  ),

  // ONESHOT Layer - Quick access to keys often pressed once
  [3] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                        KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,  KC_F12,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
         ZOOM,     CAL,     WEB,   NOTES,    TERM,   SLACK,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,   RESET,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______,   TO(0), _______,     ALFRED,   TO(0), _______
                                      //`--------------------------'  `--------------------------'
  )
};

#define L_QWERTY 0
#define L_NUM 2
#define L_CTL 4
#define L_ONE 8

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
        case L_NUM:
            oled_write_P(PSTR("NUMSYM"), false);
            break;
        case L_CTL:
            oled_write_P(PSTR("CTRL"), false);
            break;
        case L_ONE:
            oled_write_P(PSTR("1-SHOT"), false);
            break;
        default:
            oled_write_P(PSTR("Normal"), false);
    }
    oled_write_P(PSTR("\n"), false);
    oled_write_P(PSTR("WPM: "), false);
    oled_write(get_u8_str(get_current_wpm(), ' '), false);
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
    } else {
        oled_render_logo();
    }
    return false;
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

const rgblight_segment_t PROGMEM layer_numsym_lights[] = RGBLIGHT_LAYER_SEGMENTS(
    {6, 1, HSV_CYAN},
    {13, 2, HSV_CYAN},
    {33, 1, HSV_CYAN},
    {40, 2, HSV_CYAN}
);

const rgblight_segment_t PROGMEM layer_ctl_lights[] = RGBLIGHT_LAYER_SEGMENTS(
    {6, 1,  220, 255, 255},
    {13, 2, 220, 255, 255},
    {33, 1, 220, 255, 255},
    {40, 2, 220, 255, 255}
);

const rgblight_segment_t PROGMEM layer_oneshot_lights[] = RGBLIGHT_LAYER_SEGMENTS(
    {6, 1, HSV_GOLD},
    {13, 2, HSV_GOLD},
    {33, 1, HSV_GOLD},
    {40, 2, HSV_GOLD}
);

const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    layer_numsym_lights,
    layer_ctl_lights,
    layer_oneshot_lights
);

void keyboard_post_init_user(void) {
    rgblight_layers = my_rgb_layers;
}

// Activate the rgb layer according to the active keyboard layer
layer_state_t layer_state_set_user(layer_state_t state) {
  rgblight_set_layer_state(0, layer_state_cmp(state, 1));
  rgblight_set_layer_state(1, layer_state_cmp(state, 2));
  rgblight_set_layer_state(2, layer_state_cmp(state, 3));
  return state;
}
#endif // RGBLIGHT_ENABLE
