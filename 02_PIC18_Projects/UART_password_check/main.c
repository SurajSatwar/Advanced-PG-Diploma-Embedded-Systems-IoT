#include<P18F4520.h>
#include<string.h>
void delay(int);
void tx(unsigned char);
unsigned char rx(void);
unsigned char c;
void string(char str[]);

char str0[] = "Enter 4-digit password:\r";
char str1[] = "\rCorrect Password\r";
char str2[] = "\rWrong Password\r";
char str3[] = "Allowed only 1 or 0\r";

unsigned char input[5];
unsigned char password[5] = "1234";
unsigned char i;

void main(){
TRISC = 0x80;
SPBRG = 0x81;
TXSTA = 0x24;
RCSTA = 0x90;
TRISAbits.RA0 = 0;
PORTAbits.RA0 = 0;
string(str0);



while(1){
for (i = 0; i < 4; i++) {
input[i] = rx();
tx(input[i]);
}
input[4] = '\0';

if(strcmp(input, password) == 0) {
string(str1);
PORTAbits.RA0 = 1;
delay(10000);
PORTAbits.RA0 = 0;
}
else {
string(str2);
PORTAbits.RA0 = 0;
}

delay(300);
}}

void tx(unsigned char x){
TXREG = x;
while(TXSTAbits.TRMT == 0);
}

unsigned char rx(void){
while(PIR1bits.RCIF == 0);
c = RCREG;
return c;
}

void string(char str[]){
unsigned int i = 0;
while (str[i] != '\0'){
tx(str[i]);
i++;
}}

void delay(int t){
int i, j;
for(i = 0; i < t; i++){
for(j = 0; j<300; j++)
{}}}

/*

*/
