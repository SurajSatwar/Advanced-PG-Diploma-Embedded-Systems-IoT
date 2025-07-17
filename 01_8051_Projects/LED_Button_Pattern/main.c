#include <reg51.h>


sbit LED1 = P1^0;
sbit LED2 = P1^1;
sbit LED3 = P1^2;


sbit BTN1 = P2^0;
sbit BTN2 = P2^1;
sbit BTN3 = P2^2;


void delay_ms(unsigned int ms) {
    unsigned int i, j;
    for(i = 0; i < ms; i++)
        for(j = 0; j < 1275; j++);
}

void main() {

    LED1 = 0;
    LED2 = 0;
    LED3 = 0;

    while(1) {
   
        if(BTN1 == 0) {  
            LED1 = 1;
            delay_ms(500);
            LED1 = 0;
            delay_ms(500);
        }

        
        else if(BTN2 == 0) {
            LED1 = 1;
            delay_ms(250);
            LED1 = 0;
            delay_ms(250);

            LED2 = 1;
            delay_ms(500);
            LED2 = 0;
            delay_ms(500);
        }

       
        else if(BTN3 == 0) {
            LED1 = 1;
            delay_ms(125);
            LED1 = 0;
            delay_ms(125);

            LED2 = 1;
            delay_ms(250);
            LED2 = 0;
            delay_ms(250);

            LED3 = 1;
            delay_ms(500);
            LED3 = 0;
            delay_ms(500);
        }

        else {
            
            LED1 = 0;
            LED2 = 0;
            LED3 = 0;
        }
    }
}
