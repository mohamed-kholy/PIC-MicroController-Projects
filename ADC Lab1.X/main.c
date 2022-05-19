/*
 * File:   main.c
 * Author: Mohamed El-Kholy
 *
 * Created on 03 ?????, 2020, 03:28 ?
 */


#include <xc.h>
#include "configuration.h"
#include <stdint.h>
#define _XTAL_FREQ 4000000

void PWM1_Init(void);
void Set_duty_cycle (uint16_t);
void ADC_Init ();
uint16_t ADC_Read (uint8_t);

void main(void) {
    PWM1_Init();
    ADC_Init() ;
    while (1) {
        Set_duty_cycle(ADC_Read (0));
        __delay_ms(1);
    
    }
    return;
} 

void PWM1_Init(){
// Make RC2 as an output pin
    TRISC2=0;
    RC2=0;
    //Configure CCP1 Module in PWM
    CCP1M3=1;
    CCP1M2=1;
    //Set PWM Frequency 
    PR2=124;
    //PS of PWM
    T2CKPS0=1;
    T2CKPS1=0;
    // Turn on Timer 2 Module 
    TMR2ON=1;
}
void Set_duty_cycle(uint16_t DC) {
    if (DC < 1024) {
        CCP1Y = DC& 1 ; 
        CCP1X= DC&2 ;
        CCPR1L = DC >> 2 ;
    }
} 

void ADC_Init () {
        
    // ADC Configuration Pins As Analog pins in ADCON1
        PCFG3 = 0 ;
        PCFG2 = 0 ;
        PCFG1 = 0 ;
        PCFG0 = 0 ;
    //Choose Clock  Fosc/8
        ADCS0 = 1 ; // ADCON0
        ADCS1 = 0 ; // ADCON0
        ADCS2 = 0 ; // ADCON1
    // Choose AN0 as a Input Analog Channel 
        CHS2 = 0 ; // ADCON0
        CHS1 = 0 ; // ADCON0
        CHS0 = 0 ; // ADCON0
    // TURN ON ADC
        ADON = 1 ; // ADCON0
    // Choose Right Justify 
        ADFM = 1 ;
    // Enable Interrupt 
        ADIF = 0;  // Clear ADC Interrupt Flag
        ADIE = 1;  // ADC Interrupt Enable Bit
        PEIE = 1;  // Peripherals Interrupt Enable Bit
        GIE = 1;   // Global Interrupts Enable Bit
    }
uint16_t ADC_Read (uint8_t ANC) {

    if(ANC<0 || ANC>7)    // Check Channel Number Validity
    { return 0;}
    ADCON0 &= 0b11000101; // Clear The Channel Selection Bits
    ADCON0 |= ANC<<3;     // Select The Required Channel (ANC)
                          // Wait The Aquisition Time
    __delay_us(30);       // The Minimum Tacq = 20us, So That should be enough
    GO_DONE = 1;          // Start A/D Conversion
    while(ADCON0bits.GO_DONE); // Polling GO_DONE Bit
                               // Provides Delay Until Conversion Is Complete
    return ((ADRESH << 8) + ADRESL); // Return The Right-Justified 10-Bit Result


}

    