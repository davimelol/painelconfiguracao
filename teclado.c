/*
 * File:   teclado.c
 * Author: 20185086
 *
 * Created on 6 de Maio de 2021, 14:53
 */


#include <xc.h>
#define MASK 0x10

char tabela [4][4] = {{ '1', '2', '3', 'A'},
                      { '4', '5', '6', 'B'},
                      { '7', '8', '9', 'C'}, 
                      { '*', '0', '#', 'D'} } ;

void teclado_init (void)
{
   ANSELH = 0;
   TRISB = 0xF0;
   PORTB = 0;
   
}

char teclado (void)
{
    char tecla = 0;
    char col, lin;
       
    for ( lin=0; lin<4; lin++)
    {
        PORTB = 0x01<<lin;                
        for ( col=0; col<4; col++ )
        {
            if ( PORTB & MASK<<col ) 
                tecla = tabela[lin][col];       
        }
    }
return(tecla);
}  
