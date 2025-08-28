#include<lpc214x.h>
void delay(int t);
void uart_init(void);
void PLL_0(void);
void uart_tx(unsigned char x);
unsigned char uart_rx(void);
char c;
int main(){
	PLL_0();
	uart_init();
	
	while(1){
		c = uart_rx();
		uart_tx('@');
		uart_tx('\r');
		delay(100);
	}
}

void uart_init(void){
	PINSEL0 = 0x00000005;
	U0LCR = 0X80;
	U0DLL = 0X62;
	U0DLM = 0X00;
	U0FDR = 0X00000010;
	U0LCR = 0X03;
	U0FCR = 0X07;
}
void PLL_0(void)
{
PLL0CON=0x01;
PLL0CFG=0x24;
PLL0FEED=0xAA;
PLL0FEED=0x55;
	while((PLL0STAT & (1<<10))==0);
	PLL0CON=0x03;
PLL0FEED=0xAA;
PLL0FEED=0x55;
	VPBDIV=0x00;
}
void uart_tx(unsigned char x){
	U0THR = x;
	while((U0LSR & (1<<5)) == 0);
}
void delay(int t){
int i, j;
	for(i=0; i<t; i++){
	for(j=0; j<500; j++){
	}
}
}
unsigned char uart_rx(void){
	while((U0LSR & 1)==0);
	return U0RBR;
}