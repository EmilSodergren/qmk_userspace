#include QMK_KEYBOARD_H
#include <stdio.h>

enum layers {
    _BASE,
    _MOVEMENT,
    _NUMPAD,
    _FUNCTIONS
};

const uint16_t PROGMEM esc_combo[] = {KC_GRV, KC_1, COMBO_END};

combo_t key_combos[] = {
    COMBO(esc_combo, KC_ESC),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    //# .-----------------------------------------------.                                             .-----------------------------------------------.
    //# |   `   |   1   |   2   |   3   |   4   |   5   |                                             |   6   |   7   |   8   |   9   |   0   |   -   |
    //# |-------+-------+-------+-------+-------+-------|                                             |-------+-------+-------+-------+-------+-------|
    //# |  TAB  |   Q   |   W   |   E   |   R   |   T   |                                             |   Y   |   U   |   I   |   O   |   P   |   =   |
    //# |-------+-------+-------+-------+-------+-------|                                             |-------+-------+-------+-------+-------+-------|
    //# |   ⇧   |   A   |   S   |   D   |   F   |   G   |-------.                             .-------|   H   |   J   |   K   |   L   |   :   |   '   |
    //# |-------+-------+-------+-------+-------+-------|   [   |                             |   ]   |-------+-------+-------+-------+-------+-------|
    //# |   ^   |   Z   |   X   |   C   |   V   |   B   |-------|                             |-------|   N   |   M   |   ,   |   .   |   /   |   |   |
    //# .-------+-------+-------+-------+-------+-------/       /                             \       \-------+-------+-------+-------+-------+-------.
    //#                      |   ⎇   |   ⌘   | MENT) | /       /                               \   ⏎   \  |   ⌫   | IONS) |   ⌦   |
    //#                      |       |       |       |/       /                                 \       \ |       |       |       |
    //#                      .-------+-------+-------+-------.                                    .------++-------+-------+-------.
  [_BASE] = LAYOUT(
      KC_GRV,   KC_1,     KC_2,     KC_3,    KC_4,    KC_5,                                  KC_6,    KC_7,           KC_8,    KC_9,     KC_0,     KC_MINS,
      KC_TAB,   KC_Q,     KC_W,     KC_E,    KC_R,    KC_T,                                  KC_Y,    KC_U,           KC_I,    KC_O,     KC_P,     KC_EQL,
      KC_LSFT,  KC_A,     KC_S,     KC_D,    KC_F,    KC_G,                                  KC_H,    KC_J,           KC_K,    KC_L,     KC_SCLN,  KC_QUOT,
      KC_LCTL,  KC_Z,     KC_X,     KC_C,    KC_V,    KC_B,          KC_LBRC,      KC_RBRC,  KC_N,    KC_M,           KC_COMM, KC_DOT,   KC_SLSH,  KC_PIPE,
                                    KC_LALT, KC_LGUI, MO(_MOVEMENT), KC_SPC,       KC_ENT,   KC_BSPC, MO(_FUNCTIONS), KC_DEL
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
    //#                      |       | MPAD) |       | /       /                               \       \  |       |   ⍉   |       |
    //#                      |       |       |       |/       /                                 \       \ |       |       |       |
    //#                      .-------+-------+-------+-------.                                    .------++-------+-------+-------.
  [_MOVEMENT] = LAYOUT(
      KC_TRANS, KC_TRANS, KC_TRANS, KC_TRANS, KC_TRANS,    KC_TRANS,                         KC_TRANS, KC_TRANS, KC_TRANS, KC_TRANS, KC_TRANS, KC_TRANS,
      KC_TRANS, KC_TRANS, KC_TRANS, KC_TRANS, KC_TRANS,    KC_TRANS,                         KC_TRANS, KC_PGDN,  KC_PGUP,  KC_TRANS, KC_TRANS, KC_TRANS,
      KC_GRV,   KC_EXLM,  KC_AT,    KC_HASH,  KC_DLR,      KC_PERC,                          KC_LEFT,  KC_DOWN,  KC_UP,    KC_RIGHT, KC_END,   KC_TRANS,
      KC_TRANS, KC_TRANS, KC_TRANS, KC_TRANS, KC_TRANS,    KC_TRANS, KC_TRANS,     KC_HOME,  KC_NO,    KC_UNDS,  KC_PLUS,  KC_LCBR,  KC_RCBR,  KC_TRANS,
                                    KC_TRANS, MO(_NUMPAD), KC_TRANS, KC_TRANS,     KC_TRANS, KC_TRANS, KC_NO,    KC_TRANS
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
      KC_TRANS, KC_TRANS, KC_TRANS, KC_TRANS, KC_TRANS, KC_TRANS,                         KC_NO,    KC_7,     KC_8,     KC_9,     KC_PSLS,  KC_TRANS,
      KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,                             KC_NO,    KC_4,     KC_5,     KC_6,     KC_PAST,  KC_TRANS,
      KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,                            KC_NO,    KC_1,     KC_2,     KC_3,     KC_PMNS,  KC_TRANS,
      KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   KC_TRANS,     KC_TRANS, KC_PLUS,  KC_0,     KC_DOT,   KC_COMM,  KC_PPLS,  KC_PENT,
                                    KC_TRANS, KC_TRANS, KC_TRANS, KC_TRANS,     KC_TRANS, KC_TRANS, KC_TRANS, KC_TRANS
          ),

    //# .-----------------------------------------------.                                             .-----------------------------------------------.
    //# |   ~   |   !   |   @   |   #   |   $   |   %   |                                             |   ^   |   &   |   *   |   (   |   )   |   _   |
    //# |-------+-------+-------+-------+-------+-------|                                             |-------+-------+-------+-------+-------+-------|
    //# |       |   F1  |   F2  |   F3  |   F4  |   F5  |                                             |   F6  |   F7  |   F8  |   F9  |  F10  |       |
    //# |-------+-------+-------+-------+-------+-------|                                             |-------+-------+-------+-------+-------+-------|
    //# |       |  F11  |  F12  | B_HUI | B_SAI | B_VAI |-------.                             .-------|   ⍉   |   ⍉   |   ⍉   |   ⍉   |   ⍉   |       |
    //# |-------+-------+-------+-------+-------+-------|   ⍉   |                             |   ⍉   |-------+-------+-------+-------+-------+-------|
    //# |       | B_TOG | B_MOD | B_HUD | B_SAD | B_VAD |-------|                             |-------|   ⍉   |   ⍉   |   ⍉   |   ⍉   |   ⍉   |   ⍉   |
    //# .-------+-------+-------+-------+-------+-------/       /                             \       \-------+-------+-------+-------+-------+-------.
    //#                      |       |       |       | /       /                               \       \  |       |       |       |
    //#                      |       |       |       |/       /                                 \       \ |       |       |       |
    //#                      .-------+-------+-------+-------.                                    .------++-------+-------+-------.
  [_FUNCTIONS] = LAYOUT(
      KC_TILD,  KC_EXLM,  KC_AT,    KC_HASH,  KC_DLR,   KC_PERC,                          KC_CIRC,  KC_AMPR,  KC_ASTR,  KC_LPRN,  KC_RPRN,  KC_UNDS,
      KC_TRANS, KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,                            KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_TRANS,
      KC_TRANS, KC_F11,   KC_F12,   RGB_HUI,  RGB_SAI,  RGB_VAI,                          KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_TRANS,
      KC_TRANS, RGB_TOG,  RGB_MOD,  RGB_HUD,  RGB_SAD,  RGB_VAD,  KC_NO,        KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,
                                    KC_TRANS, KC_TRANS, KC_TRANS, KC_TRANS,     KC_TRANS, KC_TRANS, KC_TRANS, KC_TRANS
          ),

};
/*
  [15] = LAYOUT(
      KC_TRANS, KC_TRANS, KC_TRANS, KC_TRANS, KC_TRANS, KC_TRANS,                         KC_TRANS, KC_TRANS, KC_TRANS, KC_TRANS, KC_TRANS, KC_TRANS,
      KC_TRANS, KC_TRANS, KC_TRANS, KC_TRANS, KC_TRANS, KC_TRANS,                         KC_TRANS, KC_TRANS, KC_TRANS, KC_TRANS, KC_TRANS, KC_TRANS,
      KC_TRANS, KC_TRANS, KC_TRANS, KC_TRANS, KC_TRANS, KC_TRANS,                         KC_TRANS, KC_TRANS, KC_TRANS, KC_TRANS, KC_TRANS, KC_TRANS,
      KC_TRANS, KC_TRANS, KC_TRANS, KC_TRANS, KC_TRANS, KC_TRANS, KC_TRANS,     KC_TRANS, KC_TRANS, KC_TRANS, KC_TRANS, KC_TRANS, KC_TRANS, KC_TRANS,
                                    KC_TRANS, KC_TRANS, KC_TRANS, KC_TRANS,     KC_TRANS, KC_TRANS, KC_TRANS, KC_TRANS
         )
*/

/*
qmk-keyboard-format:json:begin
{
    "name": "lily58",
    "numkeys": 58,
    "svg": "lily58.svg",
    "rows": [
                [-3, 0  , 1  , 2  , 3  , 4  , 5  , -1 ,  -2,  -1 , 6  , 7  , 8  , 9  , 10 , 11],
                [-3, 12 , 13 , 14 , 15 , 16 , 17 , -1 ,  -2,  -1 , 18 , 19 , 20 , 21 , 22 , 23],
                [-3, 24 , 25 , 26 , 27 , 28 , 29 , -1 ,  -2,  -1 , 30 , 31 , 32 , 33 , 34 , 35],
                [-3, 36 , 37 , 38 , 39 , 40 , 41 , 42 ,  -2,  43 , 44 , 45 , 46 , 47 , 48 , 49],
                [-3, -1 ,-1 ,  -1 , 50 , 51 , 52 , 53 ,  -2,  54 , 55 , 56 , 57 , -1 , -1 ,-1 ]
            ],
    "spacing": [
        0,
        8,
        2,
        4
    ],
    "vizcellwidth": 5,
    "vizemits": [
        { "line": "[_BASE] = LAYOUT(", "layer": "_BASE" },
        { "line": "[_MOVEMENT] = LAYOUT(", "layer": "_MOVEMENT" },
        { "line": "[_NUMPAD] = LAYOUT(", "layer": "_NUMPAD" },
        { "line": "[_FUNCTIONS] = LAYOUT(", "layer": "_FUNCTIONS" }
    ],
    "vizline": "//#",
    "vizboard": [
        "    //# .-----------------------------------------------.                                             .-----------------------------------------------.",
        "    //# | _000_ | _001_ | _002_ | _003_ | _004_ | _005_ |                                             | _006_ | _007_ | _008_ | _009_ | _010_ | _011_ |",
        "    //# |-------+-------+-------+-------+-------+-------|                                             |-------+-------+-------+-------+-------+-------|",
        "    //# | _012_ | _013_ | _014_ | _015_ | _016_ | _017_ |                                             | _018_ | _019_ | _020_ | _021_ | _022_ | _023_ |",
        "    //# |-------+-------+-------+-------+-------+-------|                                             |-------+-------+-------+-------+-------+-------|",
        "    //# | _024_ | _025_ | _026_ | _027_ | _028_ | _029_ |-------.                             .-------| _030_ | _031_ | _032_ | _033_ | _034_ | _035_ |",
        "    //# |-------+-------+-------+-------+-------+-------| _042_ |                             | _043_ |-------+-------+-------+-------+-------+-------|",
        "    //# | _036_ | _037_ | _038_ | _039_ | _040_ | _041_ |-------|                             |-------| _044_ | _045_ | _046_ | _047_ | _048_ | _049_ |",
        "    //# .-------+-------+-------+-------+-------+-------/       /                             \\       \\-------+-------+-------+-------+-------+-------.",
        "    //#                      | _050_ | _051_ | _052_ | / _053_ /                               \\ _054_ \\  | _055_ | _056_ | _057_ |                  ",
        "    //#                      |       |       |       |/       /                                 \\       \\ |       |       |       |                  ",
        "    //#                      .-------+-------+-------+-------.                                    .------++-------+-------+-------.                    "

    ],
    "vizsymbols": {
        "KC_TRANS": "     ",
        "KC_NO": "  ⍉  ",
        "KC_TRANS": "     ",
        "KC_0": "  0  " ,
        "KC_1": "  1  " ,
        "KC_2": "  2  " ,
        "KC_3": "  3  " ,
        "KC_4": "  4  " ,
        "KC_5": "  5  " ,
        "KC_6": "  6  " ,
        "KC_7": "  7  " ,
        "KC_8": "  8  " ,
        "KC_9": "  9  " ,
        "KC_A": "  A  " ,
        "KC_B": "  B  " ,
        "KC_C": "  C  " ,
        "KC_D": "  D  " ,
        "KC_E": "  E  " ,
        "KC_F": "  F  " ,
        "KC_G": "  G  " ,
        "KC_H": "  H  " ,
        "KC_I": "  I  " ,
        "KC_J": "  J  " ,
        "KC_K": "  K  " ,
        "KC_L": "  L  " ,
        "KC_M": "  M  " ,
        "KC_N": "  N  " ,
        "KC_O": "  O  " ,
        "KC_P": "  P  " ,
        "KC_Q": "  Q  " ,
        "KC_R": "  R  " ,
        "KC_S": "  S  " ,
        "KC_T": "  T  " ,
        "KC_U": "  U  " ,
        "KC_V": "  V  " ,
        "KC_W": "  W  " ,
        "KC_X": "  X  " ,
        "KC_Y": "  Y  " ,
        "KC_Z": "  Z  " ,
        "KC_F1": "  F1 " ,
        "KC_F2": "  F2 " ,
        "KC_F3": "  F3 " ,
        "KC_F4": "  F4 " ,
        "KC_F5": "  F5 " ,
        "KC_F6": "  F6 " ,
        "KC_F7": "  F7 " ,
        "KC_F8": "  F8 " ,
        "KC_F9": "  F9 " ,
        "KC_F10": " F10 " ,
        "KC_F11": " F11 " ,
        "KC_F12": " F12 " ,
        "KC_COMMA": "  ,  ",
        "KC_COMM": "  ,  ",
        "KC_DOT": "  .  ",
        "KC_SCOLON": "  ;  ",
        "KC_SCLN": "  :  ",
        "KC_SLASH": "  \/  ",
        "KC_SLSH": "  \/  ",
        "KC_PSLS": "  \/  ",
        "KC_BSLS": "  \\  ",
        "KC_EXLM": "  !  ",
        "KC_PIPE": "  |  ",
        "KC_QUOT": "  '  ",
        "KC_HASH": "  #  ",
        "KC_AMPR": "  &  ",
        "KC_PERC": "  %  ",
        "KC_AT": "  @  ",
        "KC_DLR": "  $  ",
        "KC_CIRC": "  ^  ",
        "KC_EQL": "  =  ",
        "KC_EQUAL": "  =  ",
        "KC_ASTR": "  *  ",
        "KC_KP_ASTERISK": "  *  ",
        "KC_PAST": "  *  ",
        "KC_LABK": "  <  ",
        "KC_RABK": "  >  ",
        "KC_BSLASH": "  \\  ",
        "KC_MINS": "  -  ",
        "KC_MINUS": "  -  ",
        "KC_PMNS": "  -  ",
        "KC_UNDS": "  _  ",
        "KC_PLUS": "  +  ",
        "KC_PPLS": "  +  ",
        "KC_LCBR": "  {  ",
        "KC_RCBR": "  }  ",
        "KC_LPRN": "  (  ",
        "KC_RPRN": "  )  ",
        "KC_GRV": "  `  ",
        "KC_GRAVE": "  `  ",
        "KC_LBRC": "  [  ",
        "KC_LBRACKET": "  [  ",
        "KC_RBRC": "  ]  ",
        "KC_RBRACKET": "  ]  ",
        "KC_TILD": "  ~  ",
        "KC_ESC": "  ⎋  " ,
        "KC_ESCAPE": "  ⎋  " ,
        "RESET_LAYER_AND_ESCAPE": "MCR ⎋" ,
        "KC_CUT": " CUT " ,
        "KC_UNDO": " UNDO" ,
        "KC_REDO": " REDO" ,
        "KC_VOLU": " VOLU" ,
        "KC_VOLD": " VOLD" ,
        "KC_MUTE":   " MUTE" ,
        "KC_TAB": " TAB " ,
        "KC_MENU": "  𝌆  " ,
        "KC_LEFT": "  ←  " ,
        "KC_UP": "  ↑  " ,
        "KC_RIGHT": "  →  " ,
        "KC_DOWN": "  ↓  " ,
        "KC_CAPSLOCK": "  ⇪  " ,
        "KC_NUMLK": "  ⇭  " ,
        "KC_SCRLK": "  ⇳  " ,
        "KC_PRSCR": "  ⎙  " ,
        "KC_PAUSE": "  ⎉  " ,
        "KC_BREAK": "  ⎊  " ,
        "KC_ENT": "  ⏎  " ,
        "KC_PENT": "  ⏎  " ,
        "KC_BSPC": "  ⌫  " ,
        "KC_SPC": "     " ,
        "KC_DEL": "  ⌦  " ,
        "KC_INSERT": "  ⎀  " ,
        "KC_HOME": "  ⇤  " ,
        "KC_END": "  ⇥  " ,
        "KC_PGUP": "  ⇞  " ,
        "KC_PGDN": "  ⇟  " ,
        "KC_LSFT": "  ⇧  " ,
        "KC_RSFT": "  ⇧  " ,
        "KC_LCTL": "  ^  " ,
        "KC_RCTL": "  ^  " ,
        "KC_LALT": "  ⎇  " ,
        "KC_RALT": "  ⎇  " ,
        "KC_HYPER": "  ✧  " ,
        "KC_LGUI": "  ⌘  " ,
        "KC_RGUI": "  ⌘  ",
        "OPT_T(KC_S)": "S(⎇) ",
        "OPT_T(KC_E)": "E(⎇) ",
        "CMD_T(KC_T)": "T(⌘) ",
        "CMD_T(KC_N)": "N(⌘) ",
        "OSM(KC_LSHIFT)": "SHIFT"
    }
}
qmk-keyboard-format:json:end
*/



