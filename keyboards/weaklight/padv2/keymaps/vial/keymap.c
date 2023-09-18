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

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [0] =   { ENCODER_CCW_CW(KC_MS_WH_UP, KC_MS_WH_DOWN), ENCODER_CCW_CW(KC_VOLD, KC_VOLU)  },
    [1] =   { ENCODER_CCW_CW(RGB_HUD, RGB_HUI),           ENCODER_CCW_CW(RGB_SAD, RGB_SAI)  },
    //                  Encoder 1                                     Encoder 2
};
#endif


void matrix_init_user(void) {  }

