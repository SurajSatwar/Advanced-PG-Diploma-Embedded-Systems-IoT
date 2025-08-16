#include <lpc214x.h>

#define RS (1<<8)
#define RW (1<<9)
#define EN (1<<10)

// LCD Data lines P0.16–P0.23
#define LCD_DATA_MASK 0xFF0000

// Keypad rows: P1.16–P1.19, cols: P0.11–P0.14
char keypad[4][4] = {
    {'7','8','9','D'},
    {'4','5','6','M'},
    {'1','2','3','S'},
    {'C','0','E','A'}
};

void delay_ms(unsigned int ms) {
    unsigned int i, j;
    for(i = 0; i < ms; i++)
        for(j = 0; j < 400; j++);
}

void lcd_cmd(unsigned char cmd) {
    IO0CLR = RS | RW | EN;
    IO0CLR = LCD_DATA_MASK;
    IO0SET = (cmd << 16) & LCD_DATA_MASK;
    IO0CLR = RS;
    IO0CLR = RW;
    IO0SET = EN;
    delay_ms(2);
    IO0CLR = EN;
}

void lcd_data(unsigned char data) {
    IO0CLR = RS | RW | EN;
    IO0CLR = LCD_DATA_MASK;
    IO0SET = (data << 16) & LCD_DATA_MASK;
    IO0SET = RS;
    IO0CLR = RW;
    IO0SET = EN;
    delay_ms(2);
    IO0CLR = EN;
}

void lcd_init() {
    IO0DIR |= RS | RW | EN | LCD_DATA_MASK;
    delay_ms(20);
    lcd_cmd(0x38);  // 8-bit, 2 line
    lcd_cmd(0x0C);  // Display ON, Cursor OFF
    lcd_cmd(0x01);  // Clear
    delay_ms(2);
}

void lcd_puts(char *str) {
    while(*str) {
        lcd_data(*str++);
    }
}

char get_key() {
    int row, col;

    IO1DIR |= (1 << 16) | (1 << 17) | (1 << 18) | (1 << 19);  // Rows as output
    IO0DIR &= ~((1 << 11) | (1 << 12) | (1 << 13) | (1 << 14)); // Cols as input

    for(row = 0; row < 4; row++) {
        IO1CLR = (0xF << 16);                // Clear all rows
        IO1SET = (1 << (16 + row));          // Set current row high
        delay_ms(5);

        if((IO0PIN & (1 << 11)) != 0) return keypad[row][0];
        if((IO0PIN & (1 << 12)) != 0) return keypad[row][1];
        if((IO0PIN & (1 << 13)) != 0) return keypad[row][2];
        if((IO0PIN & (1 << 14)) != 0) return keypad[row][3];
    }

    return 0;
}

int main() {
    char key;
    lcd_init();
    lcd_puts("Press Key:");
    lcd_cmd(0xC0);  // Move to 2nd line

    while(1) {
        key = get_key();
        if(key) {
            lcd_data(key);
            delay_ms(300);  // debounce
        }
    }
}
