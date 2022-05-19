#include "LCD.h"

void LCD_Init(){
    // Configure I/O Pins 
    LCD_DATA_PORT = 0x00 ;
    LCD_EN = 0 ;
    LCD_RS =0 ;
    // Data Sheet Steps 
    LCD_Data(0x00);
    __delay_ms (30);
    __delay_us(LCD_EN_Delay);
    LCD_Command(0x03);
    __delay_ms (5);
    LCD_Command(0x03);
     __delay_us (120) ;
    LCD_Command(0x03);
    LCD_Command(0x02);
    LCD_Command(0x02);
    LCD_Command(0x08);
    LCD_Command(0x00);
    LCD_Command(0x0C);
    LCD_Command(0x00);
    LCD_Command(0x06);

}
void LCD_Data (unsigned char Data){
    
    if (Data & 1)
        D4 = 1 ;
    else 
        D4 = 0 ;
    if (Data & 2 )
        D5 =1 ; 
    else 
        D5 = 0 ;
    if (Data & 4)
        D6 = 1 ;
    else 
        D6 =0 ;
    if (Data & 8)
        D7 = 1 ; 
    else 
        D7 = 0;
}
void LCD_Command (unsigned char command) {

    RS = 0 ; // select Command Register 
    LCD_Data(command) ; // Move Data to LCD Output pins 
    // send Enable Clock Signal 
    EN =  1 ; 
    __delay_us(LCD_EN_Delay) ; 
    EN = 0 ;
}
void LCD_Write_Char (char Data) {
    
    char Low4 , High4 ;
    Low4 = Data & 0x0F ;
    High4 = Data & 0xF0 ;
    RS = 1 ;
    LCD_Data(High4>>4);
    EN = 1 ; 
    __delay_us (LCD_EN_Delay);
    EN = 0 ;
    __delay_us (LCD_EN_Delay);
    LCD_Data(Low4);
    EN = 1 ;
    __delay_us (LCD_EN_Delay);
    EN = 0 ;
    __delay_us (LCD_EN_Delay);
}
void LCD_Write_String (char *Str ) {
    int  i ; 
    for (i = 0 ; Str[i]!='\0'; i++ ) {
        LCD_Write_Char(Str[i]);
    }
}
void LCD_set_cursor (unsigned char r , unsigned char c ) {
    
    unsigned char temp , high4 , low4 ;
    if (r==1) {
        temp = 0x80 +c-1 ;
        high4 = temp >> 4 ;
        low4 = temp & 0x0F ;
        LCD_Command(high4);
        LCD_Command(low4) ;
    
    }
     if (r==2) {
        temp = 0xC0 +c-1 ;
        high4 = temp >> 4 ;
        low4 = temp & 0x0F ;
        LCD_Command(high4);
        LCD_Command(low4) ;
    
    }

} 
void LCD_Clear() {
    LCD_Command(0);
    LCD_Command(1);
}
void LCD_SL () {
    LCD_Command(0x01);
    LCD_Command(0x08);

}
void LCD_RL () {
    LCD_Command(0x01);
    LCD_Command(0x0C);
}
void LCD_Shift_Cursor_Right () {
    LCD_Command(0x00);
    LCD_Command(0x06);

}
void Entry_Mode_Set () {

    LCD_Command(0x00);
    LCD_Command(0x07);
}