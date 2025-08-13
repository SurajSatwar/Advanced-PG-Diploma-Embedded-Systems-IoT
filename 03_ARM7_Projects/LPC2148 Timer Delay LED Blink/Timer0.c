#include<LPC214x.h>

void timer_init(void){
    VPBDIV = 0x01;
    T0CTCR = 0x00;
    T0PR = 119999;
}

void timer_delay(int s){
    T0TC = 0x00;
    T0TCR = 0x02;    // Reset timer
    T0TCR = 0x01;    // Enable Timer
    while(T0TC < s);
    T0TCR = 0x00;
}

int main(void){
    PINSEL0 = 0x00000000;
    IO0DIR |= (1<<4);
    timer_init();
    
    while(1){
        IO0SET |= (1<<4);
        timer_delay(1);
        IO0CLR |= (1<<4);
        timer_delay(1);
    }
}
