

MCU = STM32F103
OPT_DEFS += -DBOOTLOADER_STM32DUINO
MCU_LDSCRIPT = STM32F103xB_stm32duino
BOARD = STM32_F103_STM32DUINO
BOOTLOADER_TYPE = stm32duino
DFU_ARGS = -d 1EAF:0003 -a 2 -R
DFU_SUFFIX_ARGS = -v 1EAF -p 0003

# Build Options
#   change yes to no to disable
#
COMMAND_ENABLE = no        # Commands for debug and configuration
BACKLIGHT_ENABLE = no      # Enable keyboard backlight functionality
UNICODE_ENABLE = yes         # Unicode

RGBLIGHT_ENABLE = yes        # Enable WS2812 RGB underlight.
RGBLIGHT_DRIVER = ws2812

RGB_MATRIX_DRIVER = ws2812
WS2812_DRIVER = pwm


