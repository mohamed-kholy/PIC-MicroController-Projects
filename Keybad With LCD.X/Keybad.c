#include "Keybad.h"
#include "LCD.h"
#define _XTAL_FREQ 4000000 

char key ; 

void Keybad_Init () {
    Keybad_Port = 0x00 ;
    Keybad_Port_Direction = 0xF0 ;  
}
char Keybad_Scanner () {
    Keybad_Port =0x01 ; // row1 =1 
    if ((row1)&&(Col1)){
       __delay_ms(100);
       while (Col1);
       key = '1';
    }
    
     if ((row1)&&(Col2))
        key =  '2';
    if ((row1)&&(Col3))
        key =  '3';
    if ((row1)&&(Col4))
        key =  'A';
    Keybad_Port =0x02; // row2 = 1
    if ((row2)&&(Col1))
        key =  '4';
    if ((row2)&&(Col2))
        key =  '5';
    if ((row2)&&(Col3))
        key = '6';
    if ((row2)&&(Col4))
        key =  'B';
    Keybad_Port =0x04; // row3 = 1
    if ((row3)&&(Col1))
        key =  '7';
    if ((row3)&&(Col2))
        key =  '8';
    if ((row3)&&(Col3))
        key =  '9';
    if ((row3)&&(Col4))
        key =  'C';
    Keybad_Port =0x08; // row4 = 1
     if ((row4)&&(Col1))
        key =  '*';
     if ((row4)&&(Col2))
        key =  '0';
     if ((row4)&&(Col3))
        key =  '#';
     if ((row4)&&(Col4))
        key =  'D';
    return key ;
 
}
