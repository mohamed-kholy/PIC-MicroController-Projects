/*
 * File:   main.c
 * Author: Mohamed El-Kholy
 *
 * Created on 16 ?????, 2020, 06:31 ?
 */


#include <xc.h>
#include <stdint.h>
#include "config.h"
#define _XTAL_FREQ 4000000
#define Read RB0 
#define W_3  RB1 
#define W_5  RB2 
#define W_7  RB3 

void write_EEPROM(uint8_t address , uint8_t data);
uint8_t read_EEPROM ( uint8_t address);

void main(void) {
    TRISB=0x0F;
    TRISD=0x00;
    PORTD=0x00;
    uint8_t address = 0 ;
    while (1) {
        if (W_3) 
        {
         write_EEPROM(address++ , 3) ;
         __delay_ms(500);
        }
     if (W_5) 
        {
         write_EEPROM(address++ , 5) ;
         __delay_ms(500);
        }
         if (W_7) 
        {
         write_EEPROM(address++ , 7) ;
         __delay_ms(500);
        }
        if (address==3)
            address=0;
        if(Read==1){
            for (uint8_t i=0 ; i<3 ; i++){
               PORTD=  read_EEPROM(i);
               __delay_ms(1000);
                
            }
        }
    
    }
    
    
    return;
}
void write_EEPROM (uint8_t address , uint8_t data) 
{
    uint8_t GIE_State ;
    while (EECON1bits.WR); 
        EEADR=address;
        EEDATA=data;
        EECON1bits.EEPGD=0;
        EECON1bits.WREN=1;
        GIE_State=GIE;
        INTCONbits.GIE=0;
        EECON2=0x55;
        EECON2=0xAA;
        EECON1bits.WR=1;
        GIE=GIE_State;
        EECON1bits.WREN=0;
        EECON1bits.WR=0; 

}
uint8_t read_EEPROM ( uint8_t address){
    uint8_t data ;
    EEADR = address ;
    EECON1bits.EEPGD=0;
    EECON1bits.RD=1;
    data = EEDATA;
    return data ;
}