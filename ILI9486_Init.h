#pragma once

#include "ILI9486_Defines.h"

void ILI9486_Init_2()
{
    LCD_WR_REG(0x01); // SW reset
    delay(120);

    LCD_WR_REG(0x11); // Sleep out, also SW reset
    delay(120);

    LCD_WR_REG(0x3A);
      LCD_WR_DATA(0x55);           // 16-bit colour interface
 

    LCD_WR_REG(0xC0); //                          1100.0000 Power Control 1
    LCD_WR_DATA(0x0E);    //                          0001.0111   ... VRH1
    LCD_WR_DATA(0x0E);    //                          0001.0101   ... VRH2
    LCD_WR_REG(0xC1); //                          1100.0001 Power Control 2
    LCD_WR_DATA(0x41);    //                          0100.0001   . SAP BT
    LCD_WR_DATA(0x00);    //                          0000.0000   ..... VC
    LCD_WR_REG(0xC2); //                          1100.0010 Power Control 3
    LCD_WR_DATA(0x55);    //     nb. was 0x44         0101.0101   . DCA1 . DCA0

    LCD_WR_REG(0xC5);
    LCD_WR_DATA(0x00);
    LCD_WR_DATA(0x00);
    LCD_WR_DATA(0x00);
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
 
    LCD_WR_REG(TFT_INVOFF);

 
    LCD_WR_REG(0x36);
    LCD_WR_DATA(0x48);

    LCD_WR_REG(0x29);                     // display on
    delay(150);
}
