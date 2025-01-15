#include "ili9486.h"
#include "hardware/pio.h"

pio_hw_t *pio = pio0;

void lcdInit(void)
{
    LCD_WR_REG(0XF1);
	LCD_WR_DATA(0x36);
	LCD_WR_DATA(0x04);
	LCD_WR_DATA(0x00);
	LCD_WR_DATA(0x3C);
	LCD_WR_DATA(0X0F);
	LCD_WR_DATA(0x8F);
	LCD_WR_REG(0XF2);
	LCD_WR_DATA(0x18);
	LCD_WR_DATA(0xA3);
	LCD_WR_DATA(0x12);
	LCD_WR_DATA(0x02);
	LCD_WR_DATA(0XB2);
	LCD_WR_DATA(0x12);
	LCD_WR_DATA(0xFF);
	LCD_WR_DATA(0x10);
	LCD_WR_DATA(0x00);
	LCD_WR_REG(0XF8);
	LCD_WR_DATA(0x21);
	LCD_WR_DATA(0x04);
	LCD_WR_REG(0XF9);
	LCD_WR_DATA(0x00);
	LCD_WR_DATA(0x08);
	LCD_WR_REG(0x36);
	LCD_WR_DATA(0x08);
	LCD_WR_REG(0xB4);
	LCD_WR_DATA(0x00);
	LCD_WR_REG(0xC1);
	LCD_WR_DATA(0x47); //0x41
	LCD_WR_REG(0xC5);
	LCD_WR_DATA(0x00);
	LCD_WR_DATA(0xAF); //0x91
	LCD_WR_DATA(0x80);
	LCD_WR_DATA(0x00);
	LCD_WR_REG(0xE0);
	LCD_WR_DATA(0x0F);
	LCD_WR_DATA(0x1F);
	LCD_WR_DATA(0x1C);
	LCD_WR_DATA(0x0C);
	LCD_WR_DATA(0x0F);
	LCD_WR_DATA(0x08);
	LCD_WR_DATA(0x48);
	LCD_WR_DATA(0x98);
	LCD_WR_DATA(0x37);
	LCD_WR_DATA(0x0A);
	LCD_WR_DATA(0x13);
	LCD_WR_DATA(0x04);
	LCD_WR_DATA(0x11);
	LCD_WR_DATA(0x0D);
	LCD_WR_DATA(0x00);
	LCD_WR_REG(0xE1);
	LCD_WR_DATA(0x0F);
	LCD_WR_DATA(0x32);
	LCD_WR_DATA(0x2E);
	LCD_WR_DATA(0x0B);
	LCD_WR_DATA(0x0D);
	LCD_WR_DATA(0x05);
	LCD_WR_DATA(0x47);
	LCD_WR_DATA(0x75);
	LCD_WR_DATA(0x37);
	LCD_WR_DATA(0x06);
	LCD_WR_DATA(0x10);
	LCD_WR_DATA(0x03);
	LCD_WR_DATA(0x24);
	LCD_WR_DATA(0x20);
	LCD_WR_DATA(0x00);
	LCD_WR_REG(0x3A);
	LCD_WR_DATA(0x55);
	LCD_WR_REG(0x11);
	LCD_WR_REG(0x36);
	LCD_WR_DATA(0x28);
	delay_ms(120);
	LCD_WR_REG(0x29);

	LCD_direction(0x00); // horizontal 
	LCD_Clear(WHITE);
}

void lcdClear(uint16_t color)
{
	setCSXLow();
    uint16_t i, j;
    LCD_SetWindows(0, 320 - 1, 0, 320 - 1); 
    lcdWriteRAM_Prepare(); /* Prepare to write GRAM */
    for(i=0;i<320;i++)
    {
        for(j=0;j<320;j++)
        {
            LCD_WR_DATA(color);
        }
    }
	setCSXHigh();
}

void LCD_SetWindows(uint16_t xBeg, uint16_t yBeg,uint16_t xEnd,uint16_t yEnd)
{	
	LCD_WR_REG(0x2A);	
	LCD_WR_DATA(xBeg>>8);
	LCD_WR_DATA(0x00FF&xBeg);		
	LCD_WR_DATA(xEnd>>8);
	LCD_WR_DATA(0x00FF&xEnd);

	LCD_WR_REG(0x2B);	
	LCD_WR_DATA(yBeg>>8);
	LCD_WR_DATA(0x00FF&yBeg);		
	LCD_WR_DATA(yEnd>>8);
	LCD_WR_DATA(0x00FF&yEnd);

	LCD_WriteRAM_Prepare();
}

void LCD_WriteRAM_Prepare();
{
	LCD_WR_REG(0x2C);
}

void LCD_WR_REG(uint16_t reg)
{
	setDCXLow();
	pio->txf[0] = reg;
	setDCXHigh();
}
void LCD_WR_DATA(uint16_t data)
{
	pio->txf[0] = data;
}