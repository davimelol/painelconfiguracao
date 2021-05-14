/*
 * File:   main.c
 * Author: 20185086
 *
 * Created on 14 de Maio de 2021, 16:16
 */

#include "config.h"
#include <xc.h>
#include "delay.h"
#include "dispLCD4vias.h"
#include "teclado.h"

void main(void) 
{
    char estado = 0;
    char tecla = 0;
    dispLCD_init();
    teclado_init();
    while ( 1 )
    {
        tecla = teclado();
        switch(estado)
        {
            case 0:
                estado = 1;
                break;
            case 1:
                dispLCD( 0,0,"welcome         " );
                delay (3000);
                estado = 10;
                break;
            case 10:
                dispLCD( 0,0,"melos solution  " );
                dispLCD( 1,0,"1:operacao c:cfg" );
                    if(tecla == '1')
                        estado = 20;
                        
                    if(tecla == 'C' )
                        estado = 100;
                    break;
            case 20: 
                dispLCD( 0,0,"operando...     " );
                dispLCD( 1,0,"digite * p/sair " );
                if(tecla == '*' )
                    estado = 10;
                break;
            case 100:
                dispLCD( 0,0,"configurando... " );
                dispLCD( 1,0,"digite * p/sair " );
                if(tecla == '*' )
                    estado = 10;
                break;
        }
    }
}
                                                            
                
        
               
       
    
    

