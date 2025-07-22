#include<P18f4520.h>
void delay(int);
void key_detect(void);
void main(){
TRISB = 0xf0;
TRISA = 0x00;
//TRISCbits.RC1 = 0;
INTCON2bits.RBPU = 0;
ADCON1 = 0x0f;
PORTA = 0x00;
while(1){
key_detect();
delay(10);
}
}
void key_detect(void){
PORTBbits.RB0 =0; // r0 connected to ground
PORTBbits.RB1 =1;
PORTBbits.RB2 =1;
PORTBbits.RB3 =1;
if(PORTBbits.RB5 == 0){
// Key 8 pressed
PORTAbits.RA5 =1;
delay(100);
PORTAbits.RA5 =0;
delay(100); // LED ON
} else if(PORTBbits.RB4 == 0){
PORTAbits.RA2 = 1;
delay(10);
}
PORTBbits.RB0 =1; // r0 connected to ground
PORTBbits.RB1 =0;
PORTBbits.RB2 =1;
PORTBbits.RB3 =1;
if(PORTBbits.RB4 == 0){
// Key 8 pressed
PORTAbits.RA5 =0; // LED ON

}
}
void delay(int t){
int i, j;
for(i = 0; i<t; i++){
for(j =0; j<t; j++)
{
}
}

}
