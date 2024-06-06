// qmk-keymap-format.json
#include QMK_KEYBOARD_H

enum layers {
    _BASE,
    _MOVEMENT,
    _NUMPAD,
    _FUNCTIONS
};

const uint16_t PROGMEM esc_combo[] = {KC_GRV, KC_1, COMBO_END};
const uint16_t PROGMEM esc_combo2[] = {KC_J, KC_K, COMBO_END};

combo_t key_combos[] = {
    COMBO(esc_combo, KC_ESC),
    COMBO(esc_combo2, KC_ESC),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    //# .-----------------------------------------------.                                             .-----------------------------------------------.
    //# |   `   |   1   |   2   |   3   |   4   |   5   |                                             |   6   |   7   |   8   |   9   |   0   |   -   |
    //# |-------+-------+-------+-------+-------+-------|                                             |-------+-------+-------+-------+-------+-------|
    //# |  TAB  |   Q   |   W   |   E   |   R   |   T   |                                             |   Y   |   U   |   I   |   O   |   P   |   =   |
    //# |-------+-------+-------+-------+-------+-------|                                             |-------+-------+-------+-------+-------+-------|
    //# |   ⇧   |   A   |   S   |   D   |   F   |   G   |-------.                             .-------|   H   |   J   |   K   |   L   |   :   | QUOT) |
    //# |-------+-------+-------+-------+-------+-------|   [   |                             |   ]   |-------+-------+-------+-------+-------+-------|
    //# |   ^   |   Z   |   X   |   C   |   V   |   B   |-------|                             |-------|   N   |   M   |   ,   |   .   |   /   | BSLS) |
    //# .-------+-------+-------+-------+-------+-------/       /                             \       \-------+-------+-------+-------+-------+-------.
    //#                      |   ⌘   |   ⎇   | MENT) | /       /                               \   ⏎   \  |   ⌫   | IONS) |   ⌦   |
    //#                      |       |       |       |/       /                                 \       \ |       |       |       |
    //#                      .-------+-------+-------+-------.                                    .------++-------+-------+-------.
  [_BASE] = LAYOUT(
      KC_GRV,   KC_1,     KC_2,     KC_3,    KC_4,    KC_5,                                  KC_6,    KC_7,           KC_8,    KC_9,     KC_0,     KC_MINS,
      KC_TAB,   KC_Q,     KC_W,     KC_E,    KC_R,    KC_T,                                  KC_Y,    KC_U,           KC_I,    KC_O,     KC_P,     KC_EQL,
      KC_LSFT,  KC_A,     KC_S,     KC_D,    KC_F,    KC_G,                                  KC_H,    KC_J,           KC_K,    KC_L,     KC_SCLN,  RSFT_T(KC_QUOT),
      KC_LCTL,  KC_Z,     KC_X,     KC_C,    KC_V,    KC_B,          KC_LBRC,      KC_RBRC,  KC_N,    KC_M,           KC_COMM, KC_DOT,   KC_SLSH,  RCTL_T(KC_BSLS),
                                    KC_LGUI, KC_LALT, MO(_MOVEMENT), KC_SPC,       KC_ENT,   KC_BSPC, MO(_FUNCTIONS), KC_DEL
                                    ),

    //# .-----------------------------------------------.                                             .-----------------------------------------------.
    //# |       |       |       |       |       |       |                                             |       |       |       |       |       |       |
    //# |-------+-------+-------+-------+-------+-------|                                             |-------+-------+-------+-------+-------+-------|
    //# |       |       |       |       |       |       |                                             |       |   ⇟   |   ⇞   |       |       |       |
    //# |-------+-------+-------+-------+-------+-------|                                             |-------+-------+-------+-------+-------+-------|
    //# |   `   |   !   |   @   |   #   |   $   |   %   |-------.                             .-------|   ←   |   ↓   |   ↑   |   →   |   ⇥   |       |
    //# |-------+-------+-------+-------+-------+-------|       |                             |   ⇤   |-------+-------+-------+-------+-------+-------|
    //# |       |       |       |       |       |       |-------|                             |-------|   ⍉   |   _   |   +   |   {   |   }   |       |
    //# .-------+-------+-------+-------+-------+-------/       /                             \       \-------+-------+-------+-------+-------+-------.
    //#                      | MPAD) |       |       | /       /                               \       \  |       |   ⍉   |       |
    //#                      |       |       |       |/       /                                 \       \ |       |       |       |
    //#                      .-------+-------+-------+-------.                                    .------++-------+-------+-------.
  [_MOVEMENT] = LAYOUT(
      _______,  _______,  _______,  _______,     _______, _______,                         _______, _______, _______, _______,  _______,  _______,
      _______,  _______,  _______,  _______,     _______, _______,                         _______, KC_PGDN, KC_PGUP, _______,  _______,  _______,
      KC_GRV,   KC_EXLM,  KC_AT,    KC_HASH,     KC_DLR,  KC_PERC,                         KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT, KC_END,   _______,
      _______,  _______,  _______,  _______,     _______, _______, _______,      KC_HOME,  KC_NO,   KC_UNDS, KC_PLUS, KC_LCBR,  KC_RCBR,  _______,
                                    MO(_NUMPAD), _______, _______, _______,      _______,  _______, KC_NO,   _______
          ),

    //# .-----------------------------------------------.                                             .-----------------------------------------------.
    //# |       |       |       |       |       |       |                                             |   ⍉   |   7   |   8   |   9   |   /   |       |
    //# |-------+-------+-------+-------+-------+-------|                                             |-------+-------+-------+-------+-------+-------|
    //# |   `   |   1   |   2   |   3   |   4   |   5   |                                             |   ⍉   |   4   |   5   |   6   |   *   |       |
    //# |-------+-------+-------+-------+-------+-------|                                             |-------+-------+-------+-------+-------+-------|
    //# |   F1  |   F2  |   F3  |   F4  |   F5  |   F6  |-------.                             .-------|   ⍉   |   1   |   2   |   3   |   -   |       |
    //# |-------+-------+-------+-------+-------+-------|       |                             |       |-------+-------+-------+-------+-------+-------|
    //# |   F7  |   F8  |   F9  |  F10  |  F11  |  F12  |-------|                             |-------|   +   |   0   |   .   |   ,   |   +   |   ⏎   |
    //# .-------+-------+-------+-------+-------+-------/       /                             \       \-------+-------+-------+-------+-------+-------.
    //#                      |       |       |       | /       /                               \       \  |       |       |       |
    //#                      |       |       |       |/       /                                 \       \ |       |       |       |
    //#                      .-------+-------+-------+-------.                                    .------++-------+-------+-------.
  [_NUMPAD] = LAYOUT(
      _______,  _______,  _______,  _______, _______, _______,                         KC_NO,   KC_7,    KC_8,    KC_9,     KC_PSLS,  _______,
      KC_GRV,   KC_1,     KC_2,     KC_3,    KC_4,    KC_5,                            KC_NO,   KC_4,    KC_5,    KC_6,     KC_PAST,  _______,
      KC_F1,    KC_F2,    KC_F3,    KC_F4,   KC_F5,   KC_F6,                           KC_NO,   KC_1,    KC_2,    KC_3,     KC_PMNS,  _______,
      KC_F7,    KC_F8,    KC_F9,    KC_F10,  KC_F11,  KC_F12,  _______,      _______,  KC_PLUS, KC_0,    KC_DOT,  KC_COMM,  KC_PPLS,  KC_PENT,
                                    _______, _______, _______, _______,      _______,  _______, _______, _______
          ),

    //# .-----------------------------------------------.                                             .-----------------------------------------------.
    //# |   ~   |   !   |   @   |   #   |   $   |   %   |                                             |   ^   |   &   |   *   |   (   |   )   |  VOLU |
    //# |-------+-------+-------+-------+-------+-------|                                             |-------+-------+-------+-------+-------+-------|
    //# |       |   F1  |   F2  |   F3  |   F4  |   F5  |                                             |   F6  |   F7  |   F8  |   F9  |  F10  |  VOLD |
    //# |-------+-------+-------+-------+-------+-------|                                             |-------+-------+-------+-------+-------+-------|
    //# |       |  F11  |  F12  | B_HUI | B_SAI | B_VAI |-------.                             .-------|   ⍉   |   ⍉   |   ⍉   |   ⍉   |   ⍉   |  MUTE |
    //# |-------+-------+-------+-------+-------+-------|   ⍉   |                             | _TOGG |-------+-------+-------+-------+-------+-------|
    //# |       | B_TOG | B_MOD | B_HUD | B_SAD | B_VAD |-------|                             |-------|   ⍉   |   ⍉   |   ⍉   | C_NUM |   ⍉   |   ⍉   |
    //# .-------+-------+-------+-------+-------+-------/       /                             \       \-------+-------+-------+-------+-------+-------.
    //#                      |       |       |       | /       /                               \       \  |       |       |       |
    //#                      |       |       |       |/       /                                 \       \ |       |       |       |
    //#                      .-------+-------+-------+-------.                                    .------++-------+-------+-------.
  [_FUNCTIONS] = LAYOUT(
      KC_TILD,  KC_EXLM,  KC_AT,    KC_HASH, KC_DLR,  KC_PERC,                         KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN,  KC_RPRN,  KC_VOLU,
      _______,  KC_F1,    KC_F2,    KC_F3,   KC_F4,   KC_F5,                           KC_F6,   KC_F7,   KC_F8,   KC_F9,    KC_F10,   KC_VOLD,
      _______,  KC_F11,   KC_F12,   RGB_HUI, RGB_SAI, RGB_VAI,                         KC_NO,   KC_NO,   KC_NO,   KC_NO,    KC_NO,    KC_MUTE,
      _______,  RGB_TOG,  RGB_MOD,  RGB_HUD, RGB_SAD, RGB_VAD, KC_NO,        AC_TOGG,  KC_NO,   KC_NO,   KC_NO,   KC_NUM,   KC_NO,    KC_NO,
                                    _______, _______, _______, _______,      _______,  _______, _______, _______
          ),

};
/*
  [15] = LAYOUT(
      _______, _______, _______, _______, _______, _______,                         _______, _______, _______, _______, _______, _______,
      _______, _______, _______, _______, _______, _______,                         _______, _______, _______, _______, _______, _______,
      _______, _______, _______, _______, _______, _______,                         _______, _______, _______, _______, _______, _______,
      _______, _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______, _______,
                                    _______, _______, _______, _______,     _______, _______, _______, _______
         )
*/
void keyboard_pre_init_user(void){
    setPinOutput(24);
    writePinHigh(24);
}

#ifdef OLED_ENABLE
void my_render_space(void) {
    oled_write_P(PSTR("     "), false);
}

void my_render_logo(void) {
    static const char PROGMEM aurora_logo[] = {
        0x00, 0x00, 0x00, 0xe0, 0x00, 0xf8, 0xc0, 0xf8, 0xe0, 0xc0, 0xfc, 0x00, 0x7e, 0x18, 0x00, 0x80,
        0x00, 0x02, 0x80, 0xf0, 0x00, 0xc0, 0x80, 0xf8, 0xc0, 0xe0, 0x70, 0x60, 0x3c, 0x38, 0x3c, 0x1c,
        0x00, 0x3f, 0x0c, 0x0f, 0x1f, 0x03, 0x07, 0x01, 0xc3, 0x00, 0xe0, 0x80, 0x00, 0xe0, 0x80, 0xf8,
        0x80, 0xc0, 0xf7, 0xc7, 0x6f, 0x7b, 0x39, 0x30, 0x00, 0x80, 0x00, 0xc0, 0x00, 0xc0, 0xc2, 0xe0,
        0x00, 0x40, 0x38, 0x30, 0x38, 0x1e, 0x18, 0x1e, 0x0f, 0x0c, 0x07, 0x07, 0x07, 0x03, 0x03, 0x21,
        0x21, 0x31, 0x30, 0x18, 0x18, 0x1c, 0x08, 0x0c, 0x0e, 0x07, 0x06, 0x07, 0x03, 0xc3, 0x03, 0x01,
        0x4c, 0xcc, 0xc2, 0xc2, 0x41, 0x49, 0x09, 0x2b, 0x2a, 0x6a, 0x6e, 0x24, 0x24, 0x04, 0x92, 0x92,
        0xb1, 0xf1, 0xf1, 0xf2, 0xe6, 0xa4, 0xa4, 0x04, 0x04, 0x28, 0x28, 0x28, 0x28, 0x28, 0x28, 0x28
    };
    oled_write_raw_P(aurora_logo, sizeof(aurora_logo));
    oled_set_cursor(0, 4);
}

void my_render_logo_text(void) {
    oled_write_P(PSTR("lily "), false);
}

void my_render_kb_LED_state(void) {
    // Host Keyboard LED Status
    led_t led_usb_state = host_keyboard_led_state();
    bool ac = autocorrect_is_enabled();
    oled_write_P(led_usb_state.num_lock ? PSTR("N ") : PSTR("  "), false);
    oled_write_P(ac ? PSTR("A ") : PSTR("  "), false);
    oled_write_P(led_usb_state.scroll_lock ? PSTR("S ") : PSTR("  "), false);
}

void my_render_layer_state(void) {
    static const char PROGMEM default_layer[] = {
        0x20, 0x94, 0x95, 0x96, 0x20,
        0x20, 0xb4, 0xb5, 0xb6, 0x20,
        0x20, 0xd4, 0xd5, 0xd6, 0x20, 0};
    static const char PROGMEM raise_layer[] = {
        0x20, 0x97, 0x98, 0x99, 0x20,
        0x20, 0xb7, 0xb8, 0xb9, 0x20,
        0x20, 0xd7, 0xd8, 0xd9, 0x20, 0};
    static const char PROGMEM lower_layer[] = {
        0x20, 0x9a, 0x9b, 0x9c, 0x20,
        0x20, 0xba, 0xbb, 0xbc, 0x20,
        0x20, 0xda, 0xdb, 0xdc, 0x20, 0};
    static const char PROGMEM adjust_layer[] = {
        0x20, 0x9d, 0x9e, 0x9f, 0x20,
        0x20, 0xbd, 0xbe, 0xbf, 0x20,
        0x20, 0xdd, 0xde, 0xdf, 0x20, 0};

    switch (get_highest_layer(layer_state | default_layer_state)) {
        case _MOVEMENT:
            oled_write_P(lower_layer, false);
            break;
        case _FUNCTIONS:
            oled_write_P(raise_layer, false);
            break;
        case _NUMPAD:
            oled_write_P(adjust_layer, false);
            break;
        default:
            oled_write_P(default_layer, false);
    }
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        my_render_logo();
        my_render_space();
        my_render_logo_text();
        my_render_space();
        my_render_layer_state();
        my_render_space();
        my_render_kb_LED_state();
        return false;
    } else {
        return true;
    }
}
#endif
