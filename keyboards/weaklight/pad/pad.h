#pragma once

#include "quantum.h"

#define KEYMAP( \
	K000,                   K004, \
	K100, K101, K102, K103,       \
	K200, K201, K202, K203, K204, \
	K300, K301, K302, K303,       \
	K400, K401,       K403, K404  \
) { \
	{ K000, KC_NO, KC_NO, KC_NO, K004  }, \
	{ K100, K101,  K102,  K103,  KC_NO }, \
	{ K200, K201,  K202,  K203,  K204  }, \
	{ K300, K301,  K302,  K303,  KC_NO }, \
	{ K400, K401,  KC_NO, K403,  K404  }  \
}

