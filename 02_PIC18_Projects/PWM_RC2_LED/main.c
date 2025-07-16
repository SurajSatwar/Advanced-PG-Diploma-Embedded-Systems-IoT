
#include <P18f4520.h>
void pwm_init(void);
void duty_cycle(int);
void delay(int);
int i;
void main(){
TRISCbits.RC2 = 0;
pwm_init();
while(1){
for (i = 0; i<=1023; i++)
duty_cycle(i);
delay(2);
}
for (i = 1023; i>0; i--){
duty_cycle(i);
delay(2);
}
}
void pwm_init(void){
PR2 = 0x7C;
CCPR1L = 0x00;
CCP1CON = 0x0C;
T2CON = 0x07;
}

void duty_cycle(int duty){
CCPR1L = duty >> 2;
CCP1CONbits.DC1B = duty & 0x03;
}

void delay(int t){
int i, j;
for (i = 0; i<t; i++){
for(j = 0; j<500; j++){
}}
}
