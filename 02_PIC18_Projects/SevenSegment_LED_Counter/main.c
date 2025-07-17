#include<P18F4520.h>
void delay(unsigned int t) {
unsigned int i, j;
for(i = 0; i < t; i++)
{
for(j = 0; j < 100; j++){}
}
}
unsigned int i;
unsigned int seg[10] = {0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F};
void main()
{
TRISB = 0x00;

//TRISCbits.RC0 = 0;
//TRISCbits.RC1 = 0;
//TRISCbits.RC2 = 0;
//PORTCbits.RC0 = 0;
//PORTCbits.RC1 = 0;
//PORTCbits.RC2 = 0;
TRISDbits.RD0 = 0;
TRISDbits.RD1 = 0;
PORTB = 0x00;
PORTDbits.RD0 = 1;
PORTDbits.RD1 = 1;

while(1)
{
PORTDbits.RD0 = 0;
PORTDbits.RD1 = 0;
PORTB = 0x3f;
delay(300);
PORTDbits.RD0 = 0;
PORTDbits.RD1 = 1;
//PORTCbits.RC0 = 1;//red on
for(i = 0;i< 10;i++)
{
PORTB = seg[i];
delay(300);
}
if (i == 10){
PORTB = 0x3f;
PORTDbits.RD0 = 1;
PORTDbits.RD1 = 0;
i = 0;
}
for(i = 0;i< 10;i++)
{
PORTB = seg[i];
delay(300);
}
if (i == 10){
PORTDbits.RD0 = 0;
PORTDbits.RD1 = 0;
PORTB = 0x3f;
delay(300);
}
}
}
