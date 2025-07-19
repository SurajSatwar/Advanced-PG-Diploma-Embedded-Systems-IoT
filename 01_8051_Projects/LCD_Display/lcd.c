#include <reg51.h>

// LCD control pins
sbit RS = P3^0;
sbit RW = P3^1;
sbit EN = P3^2;

// LCD data port
#define LCD P2

void delay(unsigned int time) {
    unsigned int i, j;
    for(i = 0; i < time; i++)
        for(j = 0; j < 1275; j++);
}

void lcd_cmd(unsigned char cmd) {
    LCD = cmd;
    RS = 0;     
    RW = 0;     
    EN = 1;
    delay(1);
    EN = 0;
    delay(2);
}

void lcd_data(unsigned char dat) {
    LCD = dat;
    RS = 1;     
    RW = 0;     
    EN = 1;
    delay(1);
    EN = 0;
    delay(2);
}

void lcd_init() {
    lcd_cmd(0x38); 
    lcd_cmd(0x0C); 
    lcd_cmd(0x01); 
    lcd_cmd(0x06); 
    lcd_cmd(0x80); 
}

void lcd_string(char *str) {
    while(*str) {
        lcd_data(*str++);
    }
}

void main() {
    lcd_init();
    lcd_string("EMBEDDED SYSTEM");
    while(1);
}
