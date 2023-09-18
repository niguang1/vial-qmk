

MCU = STM32F103
BOARD = STM32_F103_STM32DUINO
# "development_board": "bluepill",

BOOTLOADER = stm32duino

# Build Options
#   change yes to no to disable
#
COMMAND_ENABLE = no        # Commands for debug and configuration
BACKLIGHT_ENABLE = no      # Enable keyboard backlight functionality
AUDIO_ENABLE = yes           # Audio output
UNICODE_ENABLE = yes         # Unicode

RGBLIGHT_ENABLE = yes        # Enable WS2812 RGB underlight.
RGBLIGHT_DRIVER = WS2812

# RGB_MATRIX_DRIVER = WS2812
WS2812_DRIVER = pwm

ENCODER_ENABLE = yes

AUDIO_DRIVER = dac_additive

VIA_ENABLE = yes
