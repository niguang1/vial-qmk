
#pragma once

#define MATRIX_ROWS 5
#define MATRIX_COLS 5

#define TAPPING_TERM 200


#define MOUSEKEY_INTERVAL 20
#define MOUSEKEY_DELAY 0
#define MOUSEKEY_TIME_TO_MAX 60
#define MOUSEKEY_MAX_SPEED 7
#define MOUSEKEY_WHEEL_DELAY 0


/* spi config for ST7735 */
#define SPI_DRIVER                           SPID1
#define SPI_SCK_PIN                          A5   //SCL
#define SPI_MOSI_PIN                         A7   //SDA
//给一个不用的值，防止chibios的默认spi_master驱动操作PA6，导致矩阵扫描异常
#define SPI_MISO_PIN                B4

/* LCD Configuration */
#define LCD_RST_PIN D2   //RES
#define LCD_DC_PIN B5      //RS
#define LCD_CS_PIN A4       

#define ST7735_NUM_DEVICES 1

#define QUANTUM_PAINTER_DEBUG

// #define LAYER_STATE_8BIT

