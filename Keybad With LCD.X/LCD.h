#include <xc.h>
#define _XTAL_FREQ 4000000

#define LCD_EN_Delay 500
#define LCD_DATA_PORT TRISB
#define LCD_EN TRISB4
#define LCD_RS TRISB5
#define RS RB5
#define EN RB4
#define D4 RB0
#define D5 RB1
#define D6 RB2
#define D7 RB3

// ProtoType OF LCD Functions 

void LCD_Init(); // Initialize The LCD For 4-Bit Interface
void LCD_Clear(); // Clear The LCD Display
void LCD_SL ();  // Shift Lift LCD Data
void LCD_SR ();  // Shift Right LCD Data
void LCD_Command (unsigned char); // send Command to LCD
void LCD_Data (unsigned char); // send data to LCD
void LCD_set_cursor (unsigned char , unsigned char) ; // Set Cursor Position
void LCD_Write_Char (char ); //Write Character To LCD
void LCD_Write_String (char*); // Write String To LCD 
void LCD_Shift_Cursor_Right ();
void Entry_Mode_Set ();