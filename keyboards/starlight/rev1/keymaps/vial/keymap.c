#include QMK_KEYBOARD_H

#include "print.h"

enum my_keycodes {
  RGB_MY = SAFE_RANGE,
};

typedef union{
    uint32_t raw;
    struct{
        bool RGB_amin:1;
    };
}user_config_t;

user_config_t user_config;

enum layer_names {
    _BL,
    _FL
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Keymap _BL: (Base Layer) Default Layer
     * ,-----------------------------------------------------------.
     * |Esc~| 1|  2|  3|  4|  5|  6|  7|  8|  9|  0|  -|  =|Backsp |
     * |-----------------------------------------------------------|
     * |Tab  |  Q|  W|  E|  R|  T|  Y|  U|  I|  O|  P|  [|  ]|  \  |
     * |-----------------------------------------------------------|
     * |CAPS   |  A|  S|  D|  F|  G|  H|  J|  K|  L|  ;|  '|Return |
     * |-----------------------------------------------------------|
     * |Shift   |  Z|  X|  C|  V|  B|  N|  M|  ,|  .|  /|Shift     |
     * |-----------------------------------------------------------|
     * |Ctrl|Gui |Alt | FN |  Space | FN |    |Alt |Gui |FN  |Ctrl |
     * `-----------------------------------------------------------'
     */
[_BL] = LAYOUT(
    QK_GESC, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_GRV, KC_BSPC,
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,
    KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_DEL , KC_UP,   KC_RSFT,
    KC_LCTL, KC_LGUI, KC_LALT, LT(_FL, KC_SPC),                   KC_SPC,           LT(_FL, KC_SPC), KC_RALT, KC_APP, KC_LEFT, KC_DOWN, KC_RIGHT
),
/* Keymap _FL: Function Layer
     */
[_FL] = LAYOUT(
    KC_GRV,   KC_F1 ,  KC_F2 ,  KC_F3 ,  KC_F4 ,  KC_F5 ,  KC_F6 ,  KC_F7 ,  KC_F8 ,  KC_F9 ,  KC_F10,  KC_F11,  KC_F12, QK_BOOT, KC_DEL,
    _______,  _______, KC_INS,  KC_DEL, _______, _______, _______, _______, _______, RGB_VAD, RGB_VAI, RGB_RMOD,RGB_MOD, RGB_MY,
    _______, _______, KC_PGUP, KC_PGDN, _______, _______, _______, _______, _______, KC_PGUP, KC_PGDN, _______,         _______,
    _______, _______, KC_HOME,  KC_END, _______, _______, _______, _______, KC_HOME, KC_END,  _______, KC_BTN1, KC_MS_U, KC_BTN2,
    _______, _______, _______, LT(_FL, KC_SPC),          EE_CLR,          LT(_FL, KC_SPC), _______, _______, KC_MS_L, KC_MS_D , KC_MS_R
)

};



void eeconfig_init_user(void) {  // EEPROM is getting reset!
  user_config.raw = 0;
  user_config.RGB_amin = true; // We want this enabled by default
  eeconfig_update_user(user_config.raw); // Write default value to EEPROM now

}


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case RGB_MY:
      if (record->event.pressed) {
        // Do something when pressed
        user_config.RGB_amin ^= 1;
        eeconfig_update_user(user_config.raw);
      } else {
        // Do something else when release
      }
      return false; // Skip all further processing of this key
    default:
      return true; // Process all other keycodes normally
  }
}
// void keyboard_post_init_kb(void) {
//     //防止第一颗灯异常
//     rgblight_reload_from_eeprom();
// }
void keyboard_post_init_user(void) {
#if 0
    wait_ms(1500);
    wait_ms(1500);
    wait_ms(1500);

    // Customise these values to desired behaviour
    debug_enable=true;
    debug_matrix=true;
    debug_keyboard=true;
    //debug_mouse=true;

    wait_ms(1500);
#endif
    user_config.raw = eeconfig_read_user();

}

bool rgb_matrix_indicators_kb(void) {
    if (!rgb_matrix_indicators_user()) {
        return false;
    }

    if(user_config.RGB_amin == 0)
    {
        rgb_matrix_set_color_all(0x00,0x00,0x00);
    }

    if( 1 == host_keyboard_led_state().caps_lock )
    {
        rgb_matrix_set_color(29, 0xFF,0x00,0x00);
    }
    
#if 0
    if ( 0 == get_highest_layer(layer_state) )
    {
        rgb_matrix_set_color(1, 0xFF,0x00,0x00);
    }
# endif
    if ( 1 == get_highest_layer(layer_state) )
    {
        rgb_matrix_set_color(2, 0xFF,0x00,0x00);
    }
    return true;
}


//{0,0},{1,0},{2,0},{3,0},{4,0},{5,0},{6,0},{7,0},{8,0},{9,0},{10,0},{11,0},{12,0},{13,0},{14,0}
//{0.25,1},{1.5,1},{2.5,1},{3.5,1},{4.5,1},{5.5,1},{6.5,1},{7.5,1},{8.5,1},{9.5,1},{10.5,1},{11.5,1},{12.5,1},{13.75,1}
//{0.375,2},{1.75,2},{2.75,2},{3.75,2},{4.75,2},{5.75,2},{6.75,2},{7.75,2},{8.75,2},{9.75,2},{10.75,2},{11.75,2},{13.375,2}
//{0.5,3},{2,3},{3,3},{4,3},{5,3},{6,3},{7,3},{8,3},{9,3},{10,3},{11,3},{12,3},{13,3},{14,3}
//{0.375,4},{1.85,4},{3.125,4},{4.375,4},{6.5,4},{8.625,4},{9.85,4},{11,4},{12,4},{13,4},{14,4}

//{0,0},{16,0},{32,0},{48,0},{64,0},{80,0},{96,0},{112,0},{128,0},{144,0},{160,0},{176,0},{192,0},{208,0},{224,0}
//{4,16},{24,16},{40,16},{56,16},{72,16},{88,16},{104,16},{120,16},{136,16},{152,16},{168,16},{184,16},{200,16},{220,16}
//{6,32},{28,32},{44,32},{60,32},{76,32},{92,32},{108,32},{124,32},{140,32},{156,32},{172,32},{188,32},{214,32}
//{8,48},{32,48},{48,48},{64,48},{80,48},{96,48},{112,48},{128,48},{144,48},{160,48},{176,48},{192,48},{208,48},{224,48}
//{6,64},{30,64},{50,64},{70,64},{104,64},{138,64},{158,64},{176,64},{192,64},{208,64},{224,64}
//{27.587÷19.05×16=23,(76.2-66.5)÷19.05×16=8},{60.587÷19.05×16=51,8},{93.587÷19.05×16=79,8},{126.587÷19.05×16=106,8},{159.587÷19.05×16=134,8},{192.587÷19.05×16=162,8},{225.587÷19.05×16=189,8},{258.587÷19.05×16=217,8},
//{9.25÷19.05×16=8,(31.525-9.398)÷19.05×16=56},{31.525÷19.05×16=26,56},{64.525÷19.05×16=54,56},{91.2÷19.05×16=77,56},{131.25÷19.05×16=110,56},{159.675÷19.05×16=134,56},{192.675÷19.05×16=162,56},{225.675÷19.05×16=190,56},{258.675÷19.05×16=217,56},

#ifdef RGB_MATRIX_ENABLE
led_config_t g_led_config = { {
    {     0,     1,     2,     3,     4,     5,     6,     7,     8,     9,    10,    11,    12,    13,    14},
    {    28,    27,    26,    25,    24,    23,    22,    21,    20,    19,    18,    17,    16,    15,NO_LED},
    {    29,    30,    31,    32,    33,    34,    35,    36,    37,    38,    39,    40,NO_LED,    41,NO_LED},
    {    55,    54,    53,    52,    51,    50,    49,    48,    47,    46,    45,    44,    43,    42,NO_LED},
    {    56,    57,    58,    59,NO_LED,NO_LED,    60,NO_LED,    61,    62,    63,    64,    65,    66,NO_LED}
}, {
    {0,0},{16,0},{32,0},{48,0},{64,0},{80,0},{96,0},{112,0},{128,0},{144,0},{160,0},{176,0},{192,0},{208,0},{224,0},
    {4,16},{24,16},{40,16},{56,16},{72,16},{88,16},{104,16},{120,16},{136,16},{152,16},{168,16},{184,16},{200,16},{220,16},
    {6,32},{28,32},{44,32},{60,32},{76,32},{92,32},{108,32},{124,32},{140,32},{156,32},{172,32},{188,32},{214,32},
    {8,48},{32,48},{48,48},{64,48},{80,48},{96,48},{112,48},{128,48},{144,48},{160,48},{176,48},{192,48},{208,48},{224,48},
    {6,64},{30,64},{50,64},{70,64},{104,64},{138,64},{158,64},{176,64},{192,64},{208,64},{224,64},
    {23,8},{51,8},{79,8},{106,8},{134,8},{162,8},{189,8},{217,8},
    {8,56},{26,56},{54,56},{77,56},{110,56},{134,56},{162,56},{190,56},{217,56}
}, 
{
    4,12,12,12,4,4,4,4,4,4,4,4,4,4,4,
	4,4,4,4,4,4,4,4,4,4,4,4,4,4,
    4,4,4,4,4,4,4,4,4,4,4,4,4,
    4,4,4,4,4,4,4,4,4,4,4,4,4,4,
    4,4,4,4,4,4,4,4,4,4,4,
    2,2,2,2,2,2,2,2,
    2,2,2,2,2,2,2,2,2
}
 };
#endif