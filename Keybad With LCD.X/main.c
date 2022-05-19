/*
 * File:   main.c
 * Author: Mohamed El-Kholy
 *
 * Created on 19 ?????, 2020, 02:31 ?
 */


#include <xc.h>
#include "Config.h"
#include "Keybad.h"
#include "LCD.h"
char key ; 
char* line = "Enter Key";
void main(void) {
    LCD_Clear();
    LCD_Init();
    Keybad_Init();
    LCD_set_cursor(1,1);
    LCD_Write_String("Welcome\0");
    __delay_ms(500);
    LCD_Clear();
    LCD_set_cursor(1,1);
    
    /*LCD_Command(0x00);
    LCD_Command(0x0F);*/
    LCD_Write_String(line);
    Entry_Mode_Set();
    LCD_set_cursor(2,1);
    key = Keybad_Scanner();
   
         switch (key) {
    
        case '1' : key = '1' ; LCD_Write_Char(key);  break ;
        case '2' : key = '2' ; Entry_Mode_Set(); LCD_Write_Char(key);  break ;
        case '3' : key = '3' ; Entry_Mode_Set(); LCD_Write_Char(key);  break ;
        case '4' : key = '4' ; Entry_Mode_Set(); LCD_Write_Char(key);  break ;
        case '5' : key = '5' ; Entry_Mode_Set(); LCD_Write_Char(key);  break ;
        case '6' : key = '6' ; Entry_Mode_Set(); LCD_Write_Char(key);  break ;
        case '7' : key = '7' ; Entry_Mode_Set(); LCD_Write_Char(key);  break ;
        case '8' : key = '8' ; Entry_Mode_Set(); LCD_Write_Char(key);  break ;
        case '9' : key = '9' ; Entry_Mode_Set(); LCD_Write_Char(key);  break ;
        case '0' : key = '0' ; Entry_Mode_Set(); LCD_Write_Char(key);  break ;
        case 'A' : key = 'A' ; Entry_Mode_Set(); LCD_Write_Char(key);  break ;
        case 'B' : key = 'B' ; Entry_Mode_Set(); LCD_Write_Char(key);  break ;
        case 'C' : key = 'C' ; Entry_Mode_Set(); LCD_Write_Char(key);  break ;
        case 'D' : key = 'D' ; Entry_Mode_Set(); LCD_Write_Char(key);  break ;
        case '*' : key = '*' ; Entry_Mode_Set(); LCD_Write_Char(key);  break ;
        case '#' : key = '#' ; Entry_Mode_Set(); LCD_Write_Char(key);  break ;
    
    } 

    while (1) ;

       return;
}
