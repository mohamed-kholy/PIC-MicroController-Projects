#include <xc.h>

#define row1 RD0
#define row2 RD1
#define row3 RD2
#define row4 RD3
#define Col1 RD4
#define Col2 RD5
#define Col3 RD6
#define Col4 RD7
#define Keybad_Port PORTD
#define Keybad_Port_Direction TRISD

void Keybad_Init ();
char Keybad_Scanner ();
