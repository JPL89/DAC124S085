// @File		MAIN.C		 		
// @Author		JOSIMAR PEREIRA LEITE
// @country		BRAZIL
// @Date		01/05/23
//
//
// Copyright (C) 2023 JOSIMAR PEREIRA LEITE
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
#include "utils.h"
#include "dac124s085.h"

void main(void)
{
    __delay_ms(500);   
    
    Pic18f2520_init();
    
    DAC124S085_Init();
    
    DAC124S085_Write(0, 1, 4095);
    
    while(1)
    {  
        
    }    
    
    return;
}
