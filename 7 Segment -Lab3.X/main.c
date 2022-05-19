/*
 * File:   main.c
 * Author: Mohamed El-Kholy
 *
 * Created on 07 ?????, 2020, 08:50 ?
 */


#include <xc.h>
#include "Config.h"
#define _XTAL_FREQ 4000000 

void main(void) {
    unsigned char segment_array[10] = {0x03,0x9F,0x25,0x0C,0x99,0x48,0x41,0x1F,0x00,0x09};
    unsigned char counter = 0;
    TRISB = 0x00;
    PORTB=  0xFF;
    while(1){
        PORTB=segment_array[counter];
        __delay_ms(1000);
        counter++;
        if(counter ==10)
            counter=0;
    
    }
    
    return;
}
