// @File		DAC124S085.H		 		
// @Author		JOSIMAR PEREIRA LEITE
// @country		BRAZIL
// @Date		14/03/24
//
//
// Copyright (C) 2024 JOSIMAR PEREIRA LEITE
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//

#ifndef DAC124S085_H
#define DAC124S085_H

#define DAC124S085_CLK PORTCbits.RC0
#define DAC124S085_DIN PORTCbits.RC1
#define DAC124S085_CS PORTCbits.RC3

#define DAC124S085_CLK_TRIS TRISCbits.RC0
#define DAC124S085_DIN_TRIS TRISCbits.RC1
#define DAC124S085_CS_TRIS TRISCbits.RC3 

static const void SPI_transfer(unsigned int data)
{     
    for(unsigned int mask = 0x8000; mask; mask >>= 1)
    {
        if(data & mask) DAC124S085_DIN = 1; else DAC124S085_DIN = 0;
            
         __asm__ __volatile__("nop");
         DAC124S085_CLK = 1;
         __asm__ __volatile__("nop");
         DAC124S085_CLK = 0;
         __asm__ __volatile__("nop");    
    }
}

// MODE
// 0: WRITE TO SPECIFIED REGISTER BUT DO NOT UPDATE OUTPUTS
// 1: WRITE TO SPECIFIED REGISTER AND UPDATE OUTPUTS
// 2: WITE TO ALL REGISTER AND UPDATES OUTPUTS
// 3: POWER-DOWN OUTPUTS
void DAC124S085_Write(unsigned char ch, unsigned char mode, unsigned int data)
{
    data |= (ch << 14);
    data |= (mode << 12);
    
    DAC124S085_CS = 0;
    SPI_transfer(data);
    DAC124S085_CS = 1;   
}

void DAC124S085_Init(void)
{
    DAC124S085_CLK_TRIS = 0;
    DAC124S085_DIN_TRIS = 0;
    DAC124S085_CS_TRIS = 0;
    
    DAC124S085_CS = 1;
}

#endif 
