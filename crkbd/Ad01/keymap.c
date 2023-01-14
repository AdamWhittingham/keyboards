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

const uint16_t CMDENT = CMD_T(KC_ENT);
const uint16_t SFTESC = SFT_T(KC_ESC);
const uint16_t PLYNXT = MT(KC_MPLY, KC_MNXT);

// Rectangle window sizing
const uint16_t WINL = LAG(KC_LEFT);
const uint16_t WINR = LAG(KC_RIGHT);
const uint16_t WINU = LAG(KC_UP);
const uint16_t WIND = LAG(KC_DOWN);
const uint16_t WINF = LAG(KC_F);

// Window switching
const uint16_t WINN = LCMD(KC_GRV);
const uint16_t WINP = LSG(KC_GRV);

// App switching
const uint16_t WEB = MEH(KC_W);
const uint16_t CAL = MEH(KC_C);
const uint16_t NOTES = MEH(KC_N);
const uint16_t TERM = MEH(KC_T);
const uint16_t SLACK = MEH(KC_S);
const uint16_t ZOOM = MEH(KC_Z);
const uint16_t ALFRED = LCMD(KC_SPC);
const uint16_t ONEPASS = LCMD(KC_BSLS);

// Tab switching
const uint16_t TAB_N = LCTL(KC_TAB);
const uint16_t TAB_P = LCTL(LSFT(KC_TAB));

#define L_QWERTY 0
#define L_NUM 1
#define L_CMD 2
#define L_OSL 3

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  // QWERTY Layer - normal typing
  [L_QWERTY] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,  KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                         KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_QUOT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,  SFTESC,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                           OSL(3),   MO(2),  CMDENT,     KC_SPC,   MO(1),  KC_LALT
                                      //`--------------------------'  `--------------------------'
  ),

  // NUMSYM Layer - Numbers and symbols
  [L_NUM] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_GRV,   KC_1 ,   KC_2 ,   KC_3 ,   KC_4 ,   KC_5 ,                        KC_6 ,   KC_7 ,   KC_8 ,   KC_9 ,    KC_0,  KC_DEL,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, KC_LALT, KC_LSFT, XXXXXXX, XXXXXXX, KC_LBRC,                      KC_RBRC, KC_MINS,  KC_EQL, KC_BSLS, XXXXXXX, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,    _______, _______, _______
                                      //`--------------------------'  `--------------------------'
  ),

  // CONTROL Layer - PC & Keyboard controls
  [L_CMD] = LAYOUT_split_3x6_3(
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
  [L_OSL] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                        KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,  KC_F12,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
         ZOOM,     CAL,     WEB,   NOTES,    TERM,   SLACK,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, QK_BOOT,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                            TO(0),   TO(0), _______,     ALFRED,   TO(0), _______
                                      //`--------------------------'  `--------------------------'
  )
};
// clang-format on

#ifdef COMBO_ENABLE
enum combos {
    JK_ESC,
    DF_TAB,
};

const uint16_t PROGMEM jk_combo[] = {KC_J, KC_K, COMBO_END};
const uint16_t PROGMEM df_combo[] = {KC_D, KC_F, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
    [JK_ESC] = COMBO(jk_combo, KC_ESC),
    [DF_TAB] = COMBO(df_combo, KC_TAB)
};
#endif // COMBO_ENABLE

#ifdef OLED_ENABLE

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    return OLED_ROTATION_270;
}

void oled_osl_logo(void) {
    static const char PROGMEM font_logo[16] = {0x80, 0x81, 0x82, 0x83, 0x84, 0xA0, 0xA1, 0xA2, 0xA3, 0xA4, 0xC0, 0xC1, 0xC2, 0xC3, 0xC4, 0};
    oled_write_P(font_logo, false);
};

void oled_qwerty_logo(void) {
    static const char PROGMEM font_logo[16] = {0x85, 0x86, 0x87, 0x88, 0x89, 0xA5, 0xA6, 0xA7, 0xA8, 0xA9, 0xC5, 0xC6, 0xC7, 0xC8, 0xC9, 0};
    oled_write_P(font_logo, false);
};

void oled_cmd_logo(void) {
    static const char PROGMEM font_logo[16] = {0x8A, 0x8B, 0x8C, 0x8D, 0x8E, 0xAA, 0xAB, 0xAC, 0xAD, 0xAE, 0xCA, 0xCB, 0xCC, 0xCD, 0xCE, 0};
    oled_write_P(font_logo, false);
};

void oled_numsym_logo(void) {
    static const char PROGMEM font_logo[16] = {0x8F, 0x90, 0x91, 0x92, 0x93, 0xAF, 0xB0, 0xB1, 0xB2, 0xB3, 0xCF, 0xD0, 0xD1, 0xD2, 0xD3, 0};
    oled_write_P(font_logo, false);
};

void oled_spacer(void) {
    static const char PROGMEM font_logo[6] = {0x00, 0x00, 0x00, 0x00, 0x00, 0};
    oled_write_P(font_logo, false);
};

void oled_render_layer_state(void) {
    switch(get_highest_layer(layer_state|default_layer_state)) {
        case L_QWERTY:
            oled_qwerty_logo();
            break;
        case L_NUM:
            oled_numsym_logo();
            break;
        case L_CMD:
            oled_cmd_logo();
            break;
        case L_OSL:
            oled_osl_logo();
            break;
    }
    oled_spacer();
    oled_write_P(PSTR("\n"), false);
}

void oled_render_modifier_states(void){
    uint8_t mod = get_mods() | get_oneshot_mods();
    if (mod & MOD_MASK_GUI) {
        oled_write_ln_P(PSTR(" CMD "), true);
    }else{
        oled_write_ln_P(PSTR("     "), false);
    }
    if (mod & MOD_MASK_SHIFT) {
        oled_write_ln_P(PSTR(" SHF "), true);
    }else{
        oled_write_ln_P(PSTR("     "), false);
    }
    if (mod & MOD_MASK_ALT) {
        oled_write_ln_P(PSTR(" ALT "), true);
    }else{
        oled_write_ln_P(PSTR("     "), false);
    }
    if (mod & MOD_MASK_CTRL) {
        oled_write_ln_P(PSTR(" CTL "), true);
    }else{
        oled_write_ln_P(PSTR("     "), false);
    }
}

bool oled_task_user(void) {
    oled_render_layer_state();
    if (is_keyboard_master()) {
        oled_render_modifier_states();
    }

#ifdef WPM_ENABLE
    oled_write_P(PSTR("WPM: "), false);
    oled_write(get_u8_str(get_current_wpm(), ' '), false);
#endif
    return false;
}
#endif // OLED_ENABLE

// Keyboard LEDs
// 24  23  18  17  10  9          36  37  44  45  50  51
// 25  22  19  16  11  8          35  38  43  46  49  52
// 26  21  20  15  12  7          34  39  42  47  48  53
//            14  13  6            33  40  41
//
// Underglow LEDs
//            2   1   0       27  28  29
//            3   4   5       32  31  30

#ifdef RGBLIGHT_ENABLE
const rgblight_segment_t PROGMEM layer_qwerty[] = RGBLIGHT_LAYER_SEGMENTS(
    {36, 3, HSV_GOLD}
);

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
        layer_qwerty,
        layer_numsym_lights,
        layer_ctl_lights,
        layer_oneshot_lights
    );

void keyboard_post_init_user(void) {
    rgblight_layers = my_rgb_layers;
}

// Activate the rgb layer according to the active keyboard layer
layer_state_t layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(0, layer_state_cmp(state, 0));
    rgblight_set_layer_state(1, layer_state_cmp(state, 1));
    rgblight_set_layer_state(2, layer_state_cmp(state, 2));
    rgblight_set_layer_state(3, layer_state_cmp(state, 3));
    return state;
}
#endif // RGBLIGHT_ENABLE

#ifdef RGB_MATRIX_ENABLE
// Keyboard LEDs
// 24  23  18  17  10  9          36  37  44  45  50  51
// 25  22  19  16  11  8          35  38  43  46  49  52
// 26  21  20  15  12  7          34  39  42  47  48  53
//            14  13  6            33  40  41
//
// Underglow LEDs
//            2   1   0       27  28  29
//            3   4   5       32  31  30

const uint8_t num_row[] = {23, 18, 17, 10, 9, 36, 37, 44, 45, 50};

bool rgb_matrix_indicators_user(void) {
    switch(get_highest_layer(layer_state|default_layer_state)) {
        case L_QWERTY: //QWERTY
            //rgb_matrix_set_color_all(20, 20, 120);
            rgb_matrix_set_color_all(20, 20, 20);
            break;
        case L_NUM:
            rgb_matrix_set_color_all(0, 0, 0);
            for (uint8_t i = 0; i < sizeof(num_row); i++) {
                rgb_matrix_set_color(num_row[i], RGB_CYAN);
            }
            rgb_matrix_set_color(8, 128, 128, 128); // [
            rgb_matrix_set_color(35, 128, 128, 128); // ]
            break;
        case L_CMD:
            rgb_matrix_set_color_all(0, 0, 0);

            // Arrow keys
            rgb_matrix_set_color(44, RGB_GOLD); // up
            rgb_matrix_set_color(43, RGB_GOLD); // down
            rgb_matrix_set_color(38, RGB_GOLD); // left
            rgb_matrix_set_color(46, RGB_GOLD); // right

            // Media keys
            rgb_matrix_set_color(34, 0, 128, 32); // Play/Pause
            rgb_matrix_set_color(39, 0, 128, 128); // Next
            break;
        case L_OSL:
            rgb_matrix_set_color_all(0, 0, 0);
            for (uint8_t i = 0; i < sizeof(num_row); i++) {
                rgb_matrix_set_color(num_row[i], RGB_GOLD);
            }

            // App keys
            rgb_matrix_set_color(25, 45,  140, 255);   // Zoom
            rgb_matrix_set_color(22, 200, 200, 200);   // Calendar
            rgb_matrix_set_color(19, 255, 149, 0);     // Firefox
            rgb_matrix_set_color(16, 126, 29,  250);   // Obsidian
            rgb_matrix_set_color(11, 64,  64,  128);   // Kitty
            rgb_matrix_set_color(8,  46,  182, 125);   // Slack

            // Kbd control keys
            rgb_matrix_set_color(53, 127, 0, 0); // RESET
            break;
    }
    return true;
}

#endif // RG
