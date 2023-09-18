#include QMK_KEYBOARD_H

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
     * |Ctrl|Gui |Alt |      Space            |Alt |Gui |FN  |Ctrl |
     * `-----------------------------------------------------------'
     */
// [_BL] = LAYOUT(
//     QK_GESC, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,
//     KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,
//     KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,
//     KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,                   KC_RSFT,
//     KC_LCTL, KC_LGUI, KC_LALT, KC_C,          KC_SPC,                             MO(_FL), KC_RALT, KC_RGUI, KC_RCTL, MO(_FL)
// ),
[_BL] = LAYOUT(
    QK_GESC, RGB_TOG,    RGB_MOD,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,
    KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,                   KC_RSFT,
    KC_LCTL, KC_LGUI, KC_LALT, MO(_FL),          KC_SPC,                             MO(_FL), KC_RALT, KC_RGUI, KC_RCTL, MO(_FL)
),
/* Keymap _FL: Function Layer
     */
[_FL] = LAYOUT(
    KC_GRV,   KC_F1 ,  KC_F2 ,  KC_F3 ,  KC_F4 ,  KC_F5 ,  KC_F6 ,  KC_F7 ,  KC_F8 ,  KC_F9 ,  KC_F10,  KC_F11,  KC_F12, QK_BOOT,
    _______,  KC_INS,  KC_DEL, _______, _______, _______, _______, _______, _______, RGB_RMOD, RGB_MOD, RGB_VAD,RGB_VAI, RGB_TOG,
    _______, KC_PGUP, KC_PGDN, _______, _______, _______, _______, _______, _______, _______, _______, _______,          RGB_TOG,
    _______, KC_HOME,  KC_END, _______, _______, _______, _______, _______, _______, _______, _______,                   _______,
    _______, _______, _______, LT(_FL, KC_SPC),          _______,                            _______, _______, _______, _______, _______
)

};

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) { /* First encoder */
        if (clockwise) {
            tap_code(KC_BRIGHTNESS_UP);
        } else {
            tap_code(KC_BRIGHTNESS_DOWN);
        }
    }else if(index == 1)
    {
        if (clockwise) {
            // tap_code(KC_AUDIO_VOL_UP);
            // rgblight_increase();
        } else {
            tap_code(KC_AUDIO_VOL_DOWN);
        }
    }
    
    return false;
}


void matrix_init_user(void) {  }

bool rgb_matrix_indicators_kb(void) {
    if (!rgb_matrix_indicators_user()) {
        return false;
    }
    if( 1 == host_keyboard_led_state().caps_lock )
    {
        rgb_matrix_set_color(3, 0xFF,0x00,0x00);
    }
    
    if ( 0 == get_highest_layer(layer_state) )
    {
        rgb_matrix_set_color(1, 0xFF,0x00,0x00);
    }

    if ( 1 == get_highest_layer(layer_state) )
    {
        rgb_matrix_set_color(2, 0xFF,0x00,0x00);
    }
    return true;
}


//{0,0},{1,0},{2,0},{3,0},{4,0},{5,0},{6,0},{7,0},{8,0},{9,0},{10,0},{11,0},{12,0},{13.5,0}
//{0.25,1},{1.5,1},{2.5,1},{3.5,1},{4.5,1},{5.5,1},{6.5,1},{7.5,1},{8.5,1},{9.5,1},{10.5,1},{11.5,1},{12.5,1},{13.75,1}
//{0.375,2},{1.75,2},{2.75,2},{3.75,2},{4.75,2},{5.75,2},{6.75,2},{7.75,2},{8.75,2},{9.75,2},{10.75,2},{11.75,2},{13.375,2}
//{0.625,3},{2.25,3},{3.25,3},{4.25,3},{5.25,3},{6.25,3},{7.25,3},{8.25,3},{9.25,3},{10.25,3},{11.25,3},{13.125,3}
//{0.375,4},{1.85,4},{3.125,4},{4.375,4},{6.5,4},{8.5,4},{9.85,4},{11.125,4},{12.375,4},{13.75,4},

//{0,0},{17,0},{34,0},{52,0},{69,0},{86,0},{103,0},{121,0},{138,0},{155,0},{172,0},{190,0},{207,0},{233,0}
//{4,16},{26,16},{43,16},{60,16},{78,16},{95,16},{112,16},{129,16},{146,16},{164,16},{181,16},{198,16},{215,16},{237,16}
//{6,32},{30,32},{47,32},{65,32},{82,32},{99,32},{116,32},{134,32},{151,32},{168,32},{185,32},{202,32},{230,32}
//{11,48},{39,48},{56,48},{73,48},{90,48},{108,48},{125,48},{142,48},{159,48},{177,48},{194,48},{226,48}
//{6,64},{32,64},{54,64},{75,64},{112,64},{146,64},{170,64},{192,64},{213,64},{237,64},

#ifdef RGB_MATRIX_ENABLE
led_config_t g_led_config = { {
    {     0,     1,     2,     3,     4,     5,     6,     7,     8,     9,    10,    11,    12,    13},
    {    27,    26,    25,    24,    23,    22,    21,    20,    19,    18,    17,    16,    15,    14},
    {    28,    29,    30,    31,    32,    33,    34,    35,    36,    37,    38,    39,NO_LED,    40},
    {    52,    51,    50,    49,    48,    47,    46,    45,    44,    43,    42,NO_LED,NO_LED,    41},
    {    53,    54,    55,    56,NO_LED,    57,NO_LED,    58,    59,NO_LED,    60,    61,NO_LED,    62}
}, {
    {0,0},{17,0},{34,0},{52,0},{69,0},{86,0},{103,0},{121,0},{138,0},{155,0},{172,0},{190,0},{207,0},{233,0},
    {237,16},{215,16},{198,16},{181,16},{164,16},{146,16},{129,16},{112,16},{95,16},{78,16},{60,16},{43,16},{26,16},{4,16},
    {6,32},{30,32},{47,32},{65,32},{82,32},{99,32},{116,32},{134,32},{151,32},{168,32},{185,32},{202,32},{230,32},
    {226,48},{194,48},{177,48},{159,48},{142,48},{125,48},{108,48},{90,48},{73,48},{56,48},{39,48},{11,48},
    {6,64},{32,64},{54,64},{75,64},{112,64},{146,64},{170,64},{192,64},{213,64},{237,64}
}, 
{
    4,8,8,8,4,4,4,4,4,4,4,4,4,4,
	4,4,4,4,4,4,4,4,4,4,4,4,4,4,
    4,4,4,4,4,4,4,4,4,4,4,4,4,
    4,4,4,4,4,4,4,4,4,4,4,4,
    4,4,4,4,4,4,4,4,4,4
}
 };
#endif