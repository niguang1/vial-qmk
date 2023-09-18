#pragma once

#include "quantum.h"

#define KEYMAP( \
	K000, K001, K002, K003, \
	K100, K101, K102, K103, \
	K200, K201, K202,       \
	K300, K301, K302, K303  \
	K400,       K402        \
) { \
	{ K000, K001,  K002, K003  }, \
	{ K100, K101,  K102, K103 }, \
	{ K200, K201,  K202, KC_NO  }, \
	{ K300, K301,  K302, K303  }, \
	{ K400, KC_NO, K402, KC_NO }  \
}

