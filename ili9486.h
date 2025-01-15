#pragma once

#include "dev.h"
#include "ILI9486_Init.h"

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

typedef struct
{
    uint16_t width;
    uint16_t height;
} lcd_dev_t;


void lcdInit(void);

void lcdClear(uint16_t color);

void LCD_SetWindows(uint16_t xStar, uint16_t yStar,uint16_t xEnd,uint16_t yEnd);

void LCD_WriteRAM_Prepare();

void LCD_WR_REG(uint16_t reg);
void LCD_WR_DATA(uint16_t data);