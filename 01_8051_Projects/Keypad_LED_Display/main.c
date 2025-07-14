#include <reg51.h>


sbit r0 = P1^0;
sbit r1 = P1^1;
sbit r2 = P1^2;
sbit r3 = P1^3;

sbit c0 = P1^4;
sbit c1 = P1^5;
sbit c2 = P1^6;
sbit c3 = P1^7;

#define LED_PORT P2

void delay(unsigned int t) {
    unsigned int i, j;
    for(i = 0; i < t; i++)
        for(j = 0; j < 1275; j++);
}


unsigned char key_map[4][4] = {
    {0x01, 0x02, 0x03, 0x0A},  // 1 2 3 A
    {0x04, 0x05, 0x06, 0x0B},  // 4 5 6 B
    {0x07, 0x08, 0x09, 0x0C},  // 7 8 9 C
    {0x0E, 0x00, 0x0F, 0x0D}   // E 0 F D
};

unsigned char get_key() {
    unsigned char row;

    for(row = 0; row < 4; row++) {
        
        r0 = r1 = r2 = r3 = 1;
        if(row == 0) r0 = 0;
        if(row == 1) r1 = 0;
        if(row == 2) r2 = 0;
        if(row == 3) r3 = 0;

        if(c0 == 0) { while(c0==0); return key_map[row][0]; }
        if(c1 == 0) { while(c1==0); return key_map[row][1]; }
        if(c2 == 0) { while(c2==0); return key_map[row][2]; }
        if(c3 == 0) { while(c3==0); return key_map[row][3]; }
    }
    return 0xFF;  
}

void main() {
    unsigned char key_val;

    LED_PORT = 0x00; 

    while(1) {
        key_val = get_key();
        if(key_val != 0xFF) {
            LED_PORT = 0x00;      
            delay(50);
            LED_PORT = key_val;   
					delay(1000);
            LED_PORT = 0x00;     
        }
    }
}
