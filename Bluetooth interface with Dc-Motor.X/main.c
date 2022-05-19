/*
 * File:   main.c
 * Author: Mohamed El-Kholy
 *
 * Created on 19 ?????, 2020, 03:50 ?
 */


#include <xc.h>
#include "config.h"
#include <stdint.h>
#define _XTAL_FREQ 4000000
#define forward_button 49
#define backward_Button 50
#define stop_Button 51

void UART_Rx_Init(void);
uint8_t reading_value = 0;
void main(void) {
    
    UART_Rx_Init();
    TRISB0=0;
    TRISB1=0;
    RB0=0;
    RB1=0;
    TRISC1=0;
    RC1=1;
    while (1){
    
    }
    
    return;
}
void UART_Rx_Init (void) {

    BRGH = 1; 
    SPBRG = 25;
    SYNC = 0;
    SPEN = 1;
    TRISC6 = 1;
    TRISC7 = 1;
    RCIE = 1 ;
    PEIE = 1 ;
    GIE =1 ;
    CREN = 1;  

}



void __interrupt ISR(void) {
    if (RCIF==1) {
        reading_value=RCREG;
        if (reading_value==forward_button)
        {
            
            RB0=0;
            RB1=1;
        
        }
        if (reading_value==backward_Button)
        {
            RB0=1;
            RB1=0;
        }
        if (reading_value==stop_Button)
        {
            RB0=1;
            RB1=1;
        }
    
    }

}