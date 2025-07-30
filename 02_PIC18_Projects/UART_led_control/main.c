#include<P18F4520.h>
void delay(int);
void trans(unsigned char);
unsigned char recive(void);
void string(unsigned char *p);
char str1[100] = "UART Transmission Completed";
char str2[] = "Wrong Command";
char str3[] = "LED ON";
char str4[] = "LED OFF";
char a;
void main(){
TRISC = 0x80;
SPBRG = 0x81;
TXSTA = 0x24;
RCSTA = 0x90;

while(1){
/*trans('H');
trans('E');
trans('L');
trans('L');
trans('O');
trans('\r');
string(str1);
trans('\r');*/


if (recive() == '1'){
PORTCbits.RC0 = 1;
string(str3);
trans('\r');
} else if(recive() == '0'){
PORTCbits.RC0 = 0;
string(str4);
trans('\r');
}else{
string(str2);
trans('\r');
}
//string(str1);
delay(10);
}
}
void trans(unsigned char x){
TXREG = x;
while(TXSTAbits.TRMT == 0);
}
void string(unsigned char *p)
{
while(*p != '\0'){
trans(*p);
p++;
}
}
unsigned char recive(void){
unsigned char c;
while(PIR1bits.RCIF == 0);
c = RCREG;
trans(c);
return c;

}
void delay(int t){
int i, j;
for(i = 0; i<100; i++){
for (j =0; j<t; j++){
}
}
}
