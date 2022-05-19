/*
 * File:   main.c
 * Author: Mohamed El-Kholy
 *
 * Created on June 14, 2020, 2:34 PM
 */


#include <xc.h>
#include "config.h"
#include <stdint.h>
#define _XTAL_FREQ 4000000
#define Rev RB0 
#define Lev0 RB1
#define Lev1 RB2
#define Lev2 RB3
#define Lev3 RB4

void set_duty_cycle (uint16_t);
void main(void) {
    // Configuration of RB to be inputs pin
    TRISB=0x1F;
    // Configuration of RD to be out pins for control motor Direction
    TRISD0=0;
    RD0=0;
    TRISD1=0;
    RD1=1;
    //Configure PWM Mode 
    CCP1M3=1;
    CCP1M2=1;
    //Configure RC2 as OutPut Pin
    TRISC2=0;
    //Set suitable Frequancy 
    PR2=124;
    //Configure Timer2 Module 
    T2CKPS0=1;
    T2CKPS1=0;
    TMR2ON=1;

    while (1) {
        if (Rev) 
        {
            RD0 = ~ RD0 ;
            RD1 = ~ RD1 ;
            __delay_ms(500);
        }
        if (Lev0) 
        {
            set_duty_cycle(0);
            __delay_ms(100);
        
        }
        if (Lev1) 
        {
         set_duty_cycle(250);
            __delay_ms(100);
        }
        if (Lev2)
        {
        set_duty_cycle(375);
            __delay_ms(100);
        }
        if (Lev3) {
         set_duty_cycle(500);
            __delay_ms(100);
        }
    __delay_ms(10);   
    }
  
    return;
}

void set_duty_cycle (uint16_t DC) {
    //check that is 10bit
    if (DC < 1024) {
        CCP1Y=DC &1 ;
        CCP1X=DC & 2;
        CCPR1L= DC >>2 ;
    }


}