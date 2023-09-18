

MCU = STM32F103

# Bootloader selection
# Cannot use `BOOTLOADER = stm32duino` due to the need to override
# `MCU_LDSCRIPT`, therefore all parameters need to be specified here manually.
OPT_DEFS += -DBOOTLOADER_STM32DUINO
MCU_LDSCRIPT = weaklight_f103
BOARD = STM32_F103_STM32DUINO
BOOTLOADER_TYPE = stm32duino
DFU_ARGS = -d 1EAF:0003 -a 2 -R
DFU_SUFFIX_ARGS = -v 1EAF -p 0003


# Build Options
#   change yes to no to disable
#
COMMAND_ENABLE = no        # Commands for debug and configuration
BACKLIGHT_ENABLE = no      # Enable keyboard backlight functionality
AUDIO_ENABLE = no           # Audio output
UNICODE_ENABLE = yes         # Unicode

ENCODER_ENABLE = yes

QUANTUM_PAINTER_ENABLE = yes
QUANTUM_PAINTER_DRIVERS += st7735_spi
QUANTUM_PAINTER_LVGL_INTEGRATION = yes

CONSOLE_ENABLE = yes
