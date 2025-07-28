#include<P18f4520.h>
void spi_tr1(unsigned char x);
void spi_tr(unsigned char cmd, unsigned char data);
void spi_init(void);
void delay(int ms);
int data[10] = {0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x6d, 0x7d, 0x07, 0x7f, 0x6f};
int adr[8] = {0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08};
int k;
void main(){
spi_init();
while(1){
for(k = 0; k<10; k++){
spi_tr(adr[0], data[k]);
delay(100);
}
}
}


void spi_tr1(unsigned char x){
SSPBUF = x; //store data in buffer regster
while(PIR1bits.SSPIF == 0); // wait for transmission
PIR1bits.SSPIF = 0; //clear flag
}
void spi_tr(unsigned char cmd, unsigned char data){
PORTAbits.RA5 = 0; // Slect slave
spi_tr1(cmd);
spi_tr1(data);
PORTAbits.RA5 = 1; // Slect slave
}
void spi_init(void){
TRISAbits.RA5 = 0;
TRISCbits.RC5 = 0;
TRISCbits.RC3 = 0;

SSPSTAT = 0xC0;
SSPCON1 = 0x20;

spi_tr(0x0B, 0x07); // scan limit 8
spi_tr(0x09, 0x00); //decode off
spi_tr(0x0A, 0x0f); //high intensity
spi_tr(0x0C, 0x01); //Normal Operation
spi_tr(0x0f, 0x00); //test off
}
void delay(int ms){
int i, j;
for(i = 0; i<1000; i++){
for(j = 0; j<ms; j++){
}
}
}
