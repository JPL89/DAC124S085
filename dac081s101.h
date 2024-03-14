// @File		DAC081S101.H		 		
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

#ifndef DAC081S101_H
#define DAC081S101_H

#define DAC081S101_CLK PORTCbits.RC0
#define DAC081S101_DIN PORTCbits.RC1
#define DAC081S101_DOUT PORTCbits.RC2
#define DAC081S101_CS PORTCbits.RC3

#define DAC081S101_CLK_TRIS TRISCbits.RC0
#define DAC081S101_DIN_TRIS TRISCbits.RC1
#define DAC081S101_DOUT_TRIS TRISCbits.RC2
#define DAC081S101_CS_TRIS TRISCbits.RC3 

static const void SPI_transfer(unsigned int data)
{     
    for(unsigned int mask = 0x8000; mask; mask >>= 1)
    {
        if(data & mask) DAC081S101_DIN = 1; else DAC081S101_DIN = 0;
            
         __asm__ __volatile__("nop");
         DAC081S101_CLK = 1;
         __asm__ __volatile__("nop");
         DAC081S101_CLK = 0;
         __asm__ __volatile__("nop");    
    }
}

void DAC081S101_Write(unsigned int data)
{
    DAC081S101_CS = 0;
    SPI_transfer(data);
    DAC081S101_CS = 1;   
}

void DAC081S101_Init(void)
{
    DAC081S101_CLK_TRIS = 0;
    DAC081S101_DIN_TRIS = 0;
    DAC081S101_DOUT_TRIS = 1;
    DAC081S101_CS_TRIS = 0;
    
    DAC081S101_CS = 1;
}

#endif 
