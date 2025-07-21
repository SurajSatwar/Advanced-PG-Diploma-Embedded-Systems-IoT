#include <p18f4520.h> 

void delay_ms(unsigned int ms);
void lcd_cmd(unsigned char cmd);
void lcd_data(unsigned char data);
void lcd_init(void);

void main() {
    int adcResult;
    unsigned char ledCount, i;
    unsigned char arr[4]; 

    // Setup
    TRISA = 0xFF;        
    TRISD = 0x00;        
    TRISC &= 0xFC;       
    TRISB = 0x00;        // PORTB as output (LCD)

    LATD = 0x00;
    LATC &= 0xFC;
    LATB = 0x00;

    // ADC setup
    ADCON0 = 0x01;       
    ADCON1 = 0x0E;      
    ADCON2 = 0x92;      

    lcd_init();

    while (1) {
        // Start ADC cov
        ADCON0bits.GO = 1;
        while (ADCON0bits.GO);  
        adcResult = ADRESH << 8;
        adcResult += ADRESL;

       
        for (i = 0; i <= 3; i++) {
            arr[3 - i] = (adcResult % 10) + '0';
            adcResult /= 10;
        }

       
        lcd_cmd(0x80);  
        for (i = 0; i < 4; i++) {
            lcd_data(arr[i]);
        }

       
        adcResult = (ADRESH << 8) + ADRESL;

       
        ledCount = adcResult / 102;  // 1023/10 = 102

        
        LATD = 0x00;
        LATC &= 0xFC;

        
        for (i = 0; i < ledCount; i++) {
            if (i < 8)
                LATD |= (1 << i);        
            else
                LATC |= (1 << (i - 8));  
        }

        delay_ms(300);
    }
}

// LCD Command
void lcd_cmd(unsigned char cmd) {
    RS = 0;
    LCD_DATA = cmd;
    EN = 1;
    delay_ms(2);
    EN = 0;
}

// LCD Data
void lcd_data(unsigned char data) {
    RS = 1;
    LCD_DATA = data;
    EN = 1;
    delay_ms(2);
    EN = 0;
}

void lcd_init(void) {
    delay_ms(20);
    lcd_cmd(0x38);  
    lcd_cmd(0x0C);  
    lcd_cmd(0x06);  
    lcd_cmd(0x01);  
    delay_ms(2);
}


void delay_ms(unsigned int ms) {
    unsigned int i, j;
    for (i = 0; i < ms; i++)
        for (j = 0; j < 200; j++);
}
