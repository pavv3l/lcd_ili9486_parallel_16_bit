#pragma once

// Write command code                WRX rising edge RDX HIGH DCX LOW
// write command parameter or data  WRX rising edge RDX HIGH DCX HIGH


void setCSXHigh(void);
void setCSXLow(void);

void setDCXHigh(void);
void setDCXLow(void);