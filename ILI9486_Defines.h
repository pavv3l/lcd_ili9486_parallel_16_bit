#pragma once

#define ILI9486_BLACK       0x0000      /*   0,   0,   0 */
#define ILI9486_NAVY        0x000F      /*   0,   0, 128 */
#define ILI9486_DARKGREEN   0x03E0      /*   0, 128,   0 */
#define ILI9486_DARKCYAN    0x03EF      /*   0, 128, 128 */
#define ILI9486_MAROON      0x7800      /* 128,   0,   0 */
#define ILI9486_PURPLE      0x780F      /* 128,   0, 128 */
#define ILI9486_OLIVE       0x7BE0      /* 128, 128,   0 */
#define ILI9486_LIGHTGREY   0xC618      /* 192, 192, 192 */
#define ILI9486_DARKGREY    0x7BEF      /* 128, 128, 128 */
#define ILI9486_BLUE        0x001F      /*   0,   0, 255 */
#define ILI9486_GREEN       0x07E0      /*   0, 255,   0 */
#define ILI9486_CYAN        0x07FF      /*   0, 255, 255 */
#define ILI9486_RED         0xF800      /* 255,   0,   0 */
#define ILI9486_MAGENTA     0xF81F      /* 255,   0, 255 */
#define ILI9486_YELLOW      0xFFE0      /* 255, 255,   0 */
#define ILI9486_WHITE       0xFFFF      /* 255, 255, 255 */
#define ILI9486_ORANGE      0xFD20      /* 255, 165,   0 */
#define ILI9486_GREENYELLOW 0xAFE5      /* 173, 255,  47 */
#define ILI9486_PINK        0xF81F


#define TFT_NOP     0x00
#define TFT_SWRST   0x01

#define TFT_INVOFF  0x20
#define TFT_INVON   0x21

#define TFT_DISPOFF 0x28
#define TFT_DISPON  0x29

#define TFT_CASET   0x2A
#define TFT_PASET   0x2B
#define TFT_RAMWR   0x2C

#define TFT_RAMRD   0x2E

#define TFT_MADCTL  0x36
#define TFT_MAD_MY  0x80
#define TFT_MAD_MX  0x40
#define TFT_MAD_MV  0x20
#define TFT_MAD_ML  0x10
#define TFT_MAD_BGR 0x08
#define TFT_MAD_MH  0x04
#define TFT_MAD_SS  0x02
#define TFT_MAD_GS  0x01
#define TFT_MAD_RGB 0x00
