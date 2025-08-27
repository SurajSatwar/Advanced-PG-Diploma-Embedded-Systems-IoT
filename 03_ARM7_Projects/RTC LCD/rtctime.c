#include <lpc214x.h>

// Function prototypes
void lcd_init(void);
void lcd_cmd(unsigned char c);
void lcd_data(unsigned char c);
void lcd_string(unsigned char *p);
void rtc_init(void);
void delay_ms(unsigned int ms);
void display_day(unsigned int day);
int main(void)
{
    lcd_init();
    rtc_init();

    while (1)
    {
			lcd_cmd(0x80);  // Move to first line

        lcd_data((DOM / 10) + '0');
        lcd_data((DOM % 10) + '0');
        lcd_data('_');
        lcd_data((MONTH / 10) + '0');
        lcd_data((MONTH % 10) + '0');
        lcd_data('_');
        lcd_data(((YEAR / 1000)%10) + '0');
        lcd_data(((YEAR / 100)%10) + '0');
			  lcd_data(((YEAR / 10)%10) + '0');
			  lcd_data((YEAR % 10) + '0');
			lcd_data('_');
			display_day(DOW);
			
        lcd_cmd(0xC0);  // Move to second line

        lcd_data((HOUR / 10) + '0');
        lcd_data((HOUR % 10) + '0');
        lcd_data(':');
        lcd_data((MIN / 10) + '0');
        lcd_data((MIN % 10) + '0');
        lcd_data(':');
        lcd_data((SEC / 10) + '0');
        lcd_data((SEC % 10) + '0');
    }
}

void rtc_init(void)
{
    // Enable clock for RTC
    CCR = 0x02;     // Reset and stop RTC
    ILR = 0x00;     // Clear interrupt flags
    CIIR = 0x00;    // Disable incremental interrupts

    // Set initial time
    DOM =  13;
    MONTH = 8;
	  YEAR = 2025;
	  SEC  = 0;
    MIN  = 27;
    HOUR = 21;

    // Select external 32.768 kHz crystal for RTC
    CCR = 0x00;     // Ensure stopped before setting
    CCR = 0x11;     // CLKSRC = 1 (external), enable RTC
}


void lcd_init(void)
{
    IO0DIR |= 0x00FF1C00; // LCD data + control pins as output
    lcd_cmd(0x38);  // 8-bit mode, 2 lines
    lcd_cmd(0x01);  // Clear display
    lcd_cmd(0x80);  // Move cursor to home
    lcd_cmd(0x0C);  // Display ON, cursor OFF
}

void lcd_cmd(unsigned char c)
{
    IO0CLR = 0x00FF0000;       // Clear data pins
    IO0SET = (c << 16);        // Put command on data lines
    IO0CLR = (1 << 10);        // RS = 0
    IO0CLR = (1 << 11);        // RW = 0
    IO0SET = (1 << 12);        // EN = 1
    delay_ms(2);
    IO0CLR = (1 << 12);        // EN = 0
}

void lcd_data(unsigned char c)
{
    IO0CLR = 0x00FF0000;       // Clear data pins
    IO0SET = (c << 16);        // Put data on data lines
    IO0SET = (1 << 10);        // RS = 1
    IO0CLR = (1 << 11);        // RW = 0
    IO0SET = (1 << 12);        // EN = 1
    delay_ms(2);
    IO0CLR = (1 << 12);        // EN = 0
}

void lcd_string(unsigned char *p)
{
    while (*p != '\0')
    {
        lcd_data(*p);
        p++;
    }
}

void delay_ms(unsigned int ms)
{
    unsigned int i, j;
    for (i = 0; i < ms; i++)
        for (j = 0; j < 6000; j++);
}

void display_day(unsigned int day)
{
switch (day)
	{
    case 0: lcd_string("SUN"); break;
		case 1: lcd_string("MON"); break;
		case 2: lcd_string("TUE"); break;
		case 3: lcd_string("WED"); break;
		case 4: lcd_string("THU"); break;
		case 5: lcd_string("FRI"); break;
		case 6: lcd_string("SAT"); break;
		default: lcd_string("UN"); break;
}
}