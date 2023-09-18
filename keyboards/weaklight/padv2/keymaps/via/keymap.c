#include QMK_KEYBOARD_H


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* LAYER 0
 * ,---------------------------------------.
 * | KC_MPLY |  KC_/   |  KC_*   | KC_MSTP |
 * ,---------------------------------------.
 * |  KC_7   |  KC_8   |  KC_9   |         |
 * |------------------------------ KC_PLUS |
 * |  KC_4   |  KC_5   |  KC_6   |         |
 * |---------------------------------------|
 * |  KC_1   |  KC_2   |  KC_3   |         |
 * |------------------------------ KC_PENT |
 * |        KC_0       | KC_PDOT |         |
 * `---------------------------------------'
 */
[0] = LAYOUT(
  KC_MPLY,    KC_PSLS,   KC_PAST, RGB_TOG,
  KC_7,       KC_8,      KC_9,    KC_PPLS,
  KC_4,       KC_5,      KC_6,    
  KC_1,       KC_2,      KC_3,    LT(1, KC_PENT),
  KC_0,                  KC_PDOT
),

/* LAYER 1
 * ,---------------------------------------.
 * | KC_MPLY |  KC_/   |  KC_*   | KC_MSTP |
 * ,---------------------------------------.
 * |  KC_7   |  KC_8   |  KC_9   |         |
 * |------------------------------ KC_PMNS |
 * | KC_BTN1 |    ↑    | KC_BTN2 |         |
 * |---------------------------------------|
 * |    ←    |    ↓    |    →    |         |
 * |------------------------------ KC_PENT |
 * |        KC_0       | KC_PDOT |         |
 * `---------------------------------------'
 */
[1] = LAYOUT(
  KC_MPLY,  KC_PSLS,  KC_PAST,  KC_MSTP,
  KC_7,     KC_8,     KC_9,     KC_PMNS,
  KC_BTN1,  KC_MS_U,  KC_BTN2,  
  KC_MS_L,  KC_MS_D,  KC_MS_R,  LT(1, KC_PENT),
  KC_0,               KC_PDOT
)

};

void keyboard_post_init_user(void) {
    
    dacPutChannelX(&DACD2, 1, (dacsample_t)0);
}

//wait_ms(ms)

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
            rgblight_increase();
        } else {
            tap_code(KC_AUDIO_VOL_DOWN);
        }
    }
    
    return false;
}


void matrix_init_user(void) {  }


#ifdef RGB_MATRIX_ENABLE
led_config_t g_led_config = { {
    { 1, NO_LED, NO_LED, NO_LED     },
	{ NO_LED, NO_LED,  NO_LED,  NO_LED },
	{ NO_LED, NO_LED,  NO_LED,  NO_LED },
	{ NO_LED, NO_LED,  NO_LED,  NO_LED },
    { NO_LED, NO_LED,  NO_LED,  NO_LED }
}, {
    {0  ,  0}
}, {
    1
} };
#endif