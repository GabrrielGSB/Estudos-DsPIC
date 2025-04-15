/*
 * File:   main.c
 * Author: G.Gonzaga.S.Barreto
 *
 * Created on 14 de Abril de 2025, 15:06
 */

#include <xc.h>
#include "myLib.h"

 _FOSCSEL(FNOSC_FRC); // Selecionar CLK interno
 _FOSC(FCKSM_CSECMD & OSCIOFNC_OFF); // Habilitar a troca de CLK e configuração

int main(void)
{
    useMaxCLK();
    
    pinMode(0, OUTPUT);
    pinMode(1, OUTPUT);
    pinMode(2, OUTPUT);
    pinMode(3, OUTPUT);
    pinMode(4, OUTPUT);
    pinMode(5, OUTPUT);
    pinMode(6, OUTPUT);
    
//    digitalWrite(12, HIGH)
    LATB = 0b00111111; // 0
    LATB = 0b00000110; // 1
    LATB = 0b01011011; // 2
    LATB = 0b01001111; // 3
    LATB = 0b01100110; // 4
    LATB = 0b01101101; // 5
    LATB = 0b01111101; // 6
    LATB = 0b00000111; // 7
    LATB = 0b01111111; // 8
    LATB = 0b01100111; // 9
    
    while(1);                 
    return 0;
}
