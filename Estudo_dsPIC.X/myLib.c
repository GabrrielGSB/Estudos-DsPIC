/*
 * File:   myLib.c
 * Author: G.Gonzaga.S.Barreto
 *
 * Created on 14 de Abril de 2025, 14:59
 */


#include "xc.h"
#include "myLib.h"

void pinMode(int pino, int modo) 
{
    if (modo == OUTPUT) TRISB &= ~(1 << pino);   // Coloca bit em 0 (saída)
    else                TRISB |=  (1 << pino);   // Coloca bit em 1 (entrada)
    
}

void digitalWrite(int pino, int valor) 
{
    if (valor == HIGH) LATB |=  (1 << pino);     // coloca o pino em nível alto
    else               LATB &= ~(1 << pino);    // coloca o pino em nível baixo
    
}

void useMaxCLK()
{
    // Configure PLL prescaler, PLL postscaler, PLL divisor
    PLLFBD             = 41; // M = 43
    CLKDIVbits.PLLPOST = 0;  // N2 = 2
    CLKDIVbits.PLLPRE  = 0;  // N1 = 2
    
    // Initiate Clock Switch to Internal FRC with PLL (NOSC = 0b001)
    __builtin_write_OSCCONH(0x01);
    __builtin_write_OSCCONL(0x01);
    
    // Wait for Clock switch to occur
    while (OSCCONbits.COSC != 0b001);
    
    // Wait for PLL to lock
    while(OSCCONbits.LOCK != 1);
}