/*
 * File:   delay.c
 * Author: 20185086
 *
 * Created on 30 de Abril de 2021, 16:19
 */

#include "config.h"
#include <xc.h>

void delay (unsigned int t ) 
{ 
    while (t)
    {
        __delay_ms(1);
        --t;
    }
}