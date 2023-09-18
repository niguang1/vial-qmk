#include QMK_KEYBOARD_H

#ifdef QUANTUM_PAINTER_ENABLE
#include "qp.h"
#endif

#include "print.h"

#ifndef HSV_SOFT_RED
    #define HSV_SOFT_RED  0, 240, 160 // Define custom "soft red" color
#endif

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* LAYER 0
 * ,-------------------------------------------------.
 * | KC_MPLY |                             | KC_MSTP |
 * ,-------------------------------------------------.
 * |    /    |  KC_7   |  KC_8   |  KC_9   |         |
 * |---------------------------------------- KC_PLUS |
 * |    *    |  KC_4   |  KC_5   |  KC_6   |         |
 * |-------------------------------------------------|
 * |    -    |  KC_1   |  KC_2   |  KC_3   |         |
 * |---------------------------------------- KC_ENT  |
 * | FN/DEL  |        KC_0       |  KC_DOT |         |
 * `-------------------------------------------------'
 */
[0] = LAYOUT(
  KC_MPLY,                                  KC_MSTP,
  KC_SLSH,  KC_7,       KC_8,      KC_9,    
  KC_ASTR,  KC_4,       KC_5,      KC_6,    KC_PLUS,
  KC_MINS,  KC_1,       KC_2,      KC_3,    
  LT(1, KC_DEL),       KC_0,      KC_DOT,    KC_ENT
),

/* LAYER 1
 * ,-------------------------------------------------.
 * | QK_BOOT |                             | KC_MSTP |
 * ,-------------------------------------------------.
 * |    /    |  KC_7   |  KC_8   |  KC_9   |         |
 * |---------------------------------------- KC_PLUS |
 * |    *    | KC_BTN1 |    ↑    | KC_BTN2 |         |
 * |-------------------------------------------------|
 * |    -    |    ←    |    ↓    |    →    |         |
 * |---------------------------------------- KC_ENT  |
 * | FN/DEL |        KC_0       |  KC_DOT |         |
 * `-------------------------------------------------'
 */
[1] = LAYOUT(
  KC_MPLY,                                KC_MSTP,
  KC_SLSH,  KC_7,     KC_8,     KC_9,     
  KC_ASTR,  KC_BTN1,  KC_MS_U,  KC_BTN2,  KC_PLUS,
  KC_MINS,  KC_MS_L,  KC_MS_D,  KC_MS_R,  
  LT(1, KC_DEL),    KC_0,       KC_DOT,   KC_ENTER
)

};

#ifdef QUANTUM_PAINTER_ENABLE
painter_device_t lcd;

static void set_angle(void* obj, int32_t v) {
    lv_arc_set_value(obj, v);
    dprintf("arc:%d\n", (int)v);
}

void lv_example_arc_2(void) {
    /*Create an Arc*/
    lv_obj_t* arc = lv_arc_create(lv_scr_act());
    lv_arc_set_rotation(arc, 270);
    lv_arc_set_bg_angles(arc, 0, 360);
    lv_obj_remove_style(arc, NULL, LV_PART_KNOB);  /*Be sure the knob is not displayed*/
    lv_obj_clear_flag(arc, LV_OBJ_FLAG_CLICKABLE); /*To not allow adjusting by click*/
    lv_obj_set_size(arc, 80, 80);
    lv_obj_center(arc);

    static lv_anim_t a;
    lv_anim_init(&a);
    lv_anim_set_var(&a, arc);
    lv_anim_set_exec_cb(&a, set_angle);
    lv_anim_set_time(&a, 1000);
    lv_anim_set_repeat_count(&a, LV_ANIM_REPEAT_INFINITE); /*Just for the demo*/
    lv_anim_set_repeat_delay(&a, 500);
    lv_anim_set_values(&a, 0, 100);
    lv_anim_start(&a);
}


// void keyboard_post_init_kb(void) {
//     debug_enable   = true;
//     debug_matrix   = true;
//     debug_keyboard = true;
    
//     setPinOutput(DISPLAY_CS_PIN);
//     setPinOutput(DISPLAY_DC_PIN);
//     setPinOutput(DISPLAY_RST_PIN);

//     keyboard_post_init_user();
// }

#endif

int enc_diff = 0;

void encoder_read(lv_indev_drv_t * drv, lv_indev_data_t*data){
  if(enc_diff != 0)
  {
    data->enc_diff = enc_diff;
    enc_diff = 0;
  }

  if(enc_pressed()) data->state = LV_INDEV_STATE_PRESSED;
  else data->state = LV_INDEV_STATE_RELEASED;
}

void keyboard_post_init_user(void) {

    wait_ms(1500);
    wait_ms(1500);
    wait_ms(1500);

    // Customise these values to desired behaviour
    debug_enable=true;
    debug_matrix=true;
    debug_keyboard=true;
    //debug_mouse=true;

#ifdef QUANTUM_PAINTER_ENABLE
    lcd = qp_st7735_make_spi_device(80, 160, LCD_CS_PIN, LCD_DC_PIN, LCD_RST_PIN, 8, 0);
    qp_init(lcd, QP_ROTATION_270);
    qp_set_viewport_offsets (lcd, 1, 26);

    static lv_indev_drv_t indev_drv;
    lv_indev_t *indev_encoder;
    lv_indev_drv_init(&indev_drv);
    indev_drv.type = LV_INDEV_TYPE_ENCODER;
    indev_drv.read_cb = encoder_read;
    indev_encoder = lv_indev_drv_register(&indev_drv);

    lv_group_t * group = lv_group_create();
    lv_indev_set_group(indev_encoder, group);
    lv_group_set_default(group);

    if (qp_lvgl_attach(lcd)) {
        // lv_example_arc_2();
         /*Create a container with ROW flex direction*/
        lv_obj_t * cont_row = lv_obj_create(lv_scr_act());
        lv_obj_set_size(cont_row, 160, 80);
        lv_obj_align(cont_row, LV_ALIGN_TOP_MID, 0, 0);
        lv_obj_set_flex_flow(cont_row, LV_FLEX_FLOW_ROW);

        int i;
        for(i = 0; i < 10; i++) {
            lv_obj_t * obj;
            lv_obj_t * label;

            /*Add items to the row*/
            obj= lv_btn_create(cont_row);
            lv_obj_set_size(obj, 48, 48);

            label = lv_label_create(obj);
            lv_label_set_text_fmt(label, "Item: %d", i);
            lv_obj_center(label);
        }
    }
#endif 
}


//层切换处理
// layer_state_t layer_state_set_user(layer_state_t state) {
//     switch (get_highest_layer(state)) {
//     case _RAISE:
//         rgblight_setrgb (0x00,  0x00, 0xFF);
//         break;
//     case _LOWER:
//         rgblight_setrgb (0xFF,  0x00, 0x00);
//         break;
//     case _PLOVER:
//         rgblight_setrgb (0x00,  0xFF, 0x00);
//         break;
//     case _ADJUST:
//         rgblight_setrgb (0x7A,  0x00, 0xFF);
//         break;
//     default: //  for any other layers, or the default layer
//         rgblight_setrgb (0x00,  0xFF, 0xFF);
//         break;
//     }
//   return state;
// }



bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) { /* First encoder */
        if (clockwise) {
            tap_code(KC_PGDN);
        } else {
            tap_code(KC_PGUP);
        }
    }else if(index == 1)
    {
        if (clockwise) {
            dprint("-----------------\r\n");
            // tap_code(KC_PGDN);
            enc_diff = 1;
        } else {
            // tap_code(KC_PGUP);
            enc_diff = -1;
        }
    }
    
    return false;
}


void matrix_init_user(void) {  }

#ifdef RGB_MATRIX_ENABLE
// led_config_t g_led_config = { {
//     { 1, NO_LED, NO_LED, NO_LED, 0     },
// 	{ 2, 3,  4,  5,  NO_LED },
// 	{ 10, 9,  8,  7,  6  },
// 	{ 11, 12,  13,  14,  NO_LED },
// 	{ 18, 17,  NO_LED, 16,  15  }
// }, {
//     {0  ,  0}, {75 ,  0}, {149,  0}, {224,  0},
//     {0  , 21}, {75 , 21}, {149, 21}, {224, 21},
//     {0  , 43}, {75 , 43}, {149, 43}, {224, 43},
//     {0  , 64}, {75 , 64}, {149, 64}, {224, 64},
// }, {
//     4, 4,
//     4, 4, 4, 4,
//     4, 4, 4, 4, 4,
//     4, 4, 4, 4,
//     4, 4, 4, 4,
// } };
led_config_t g_led_config = { {
    { 1, NO_LED, NO_LED, NO_LED, NO_LED     },
	{ NO_LED, NO_LED,  NO_LED,  NO_LED,  NO_LED },
	{ NO_LED, NO_LED,  NO_LED,  NO_LED,  NO_LED  },
	{ NO_LED, NO_LED,  NO_LED,  NO_LED,  NO_LED },
	{ NO_LED, NO_LED,  NO_LED, NO_LED,  NO_LED  }
}, {
    {0  ,  0}
}, {
    1
} };
#endif