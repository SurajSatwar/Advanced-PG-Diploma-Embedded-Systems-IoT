#include <P18f4520.h>

// LCD Connections
#define LCD_PORT PORTD
#define RS PORTCbits.RC1
#define RW PORTCbits.RC0
#define EN PORTCbits.RC2

// Function Prototypes
void delay(int);
void lcd_init(void);
void lcd_cmd(unsigned char);
void lcd_data(unsigned char);
void lcd_string(unsigned char *p);
void rtc_init(void);
void rtc_write(void);
void rtc_time(void);
void start(void);
void stop(void);
void check(void);
void i2c_data(char);
void i2c_read(void);
void display(void);

// Global Variables
unsigned char str[100] = "RTC using I2C";
char arr[7]; // To store raw RTC data (Sec, Min, Hr, Day, Date, Month, Year)
char time[8]; // To store formatted time string HH:MM:SS
int i, m;
char min, sec, hr;

void main() {
    delay(5);
    lcd_init();
    rtc_init();
    rtc_write();
    lcd_string(str);
    while (1) {
        rtc_time();
    }
}

void lcd_cmd(unsigned char c) {
    LCD_PORT = c;
    RS = 0;
    RW = 0;
    EN = 1;
    delay(5);
    EN = 0;
}

void lcd_data(unsigned char c) {
    LCD_PORT = c;
    RS = 1;
    RW = 0;
    EN = 1;
    delay(5);
    EN = 0;
}

void lcd_init(void) {
    TRISCbits.RC0 = 0; // RW pin
    TRISCbits.RC1 = 0; // RS pin
    TRISCbits.RC2 = 0; // E pin
    TRISD = 0x00; // PORTD as output for LCD data
    delay(15);
    lcd_cmd(0x30);
    delay(1);
    lcd_cmd(0x30);
    delay(1);
    lcd_cmd(0x38);
    lcd_cmd(0x01);
    lcd_cmd(0x06);
    lcd_cmd(0x0C);
    lcd_cmd(0x80);
}

void lcd_string(unsigned char *p) {
    while (*p != '\0') {
        lcd_data(*p);
        p++;
    }
}

void start(void) {
    SSPCON2bits.SEN = 1;
    while (PIR1bits.SSPIF != 1);
    PIR1bits.SSPIF = 0;
}

void stop(void) {
    SSPCON2bits.PEN = 1;
    while (PIR1bits.SSPIF != 1);
    PIR1bits.SSPIF = 0;
}

void check(void) {
    int a;
    while (PIR1bits.SSPIF != 1);
    PIR1bits.SSPIF = 0;
    a = SSPBUF;
}

void rtc_init(void) {
    TRISCbits.RC3 = 1;
    TRISCbits.RC4 = 1;
    SSPCON1 = 0x28;
    SSPSTAT = 0xC0;
    PIE1bits.SSPIE = 1;
    SSPADD = 49;
}

void rtc_write(void) {
    start();
    PIR1bits.SSPIF = 0;
    i2c_data(0xD0);
    PIR1bits.SSPIF = 0;
    i2c_data(0x00);
    i2c_data(0x10);
    PIR1bits.SSPIF = 0;
    stop();

    start();
    PIR1bits.SSPIF = 0;
    i2c_data(0xD0);
    PIR1bits.SSPIF = 0;
    i2c_data(0x01);
    i2c_data(0x10);
    PIR1bits.SSPIF = 0;
    stop();

    start();
    PIR1bits.SSPIF = 0;
    i2c_data(0xD0);
    PIR1bits.SSPIF = 0;
    i2c_data(0x02);
    i2c_data(0x10);
    PIR1bits.SSPIF = 0;
    stop();
}





// Function to send a byte of data over I2C
void i2c_data(char x) {
    SSPBUF = x;              // Load data into SSPBUF for transmission
    delay(50); 
    while (PIR1bits.SSPIF != 1); // Wait for transmission to complete
    PIR1bits.SSPIF = 0;      // Clear SSP interrupt flag
}








// Function to read data from I2C (RTC)
void i2c_read(void) {
    start();                // I2C Start condition
     SSPBUF = 0xD1;         // RTC slave address with read bit
    check();                // Wait for ACK from RTC

    for (i = 0; i < 7; i++) {
        PIR1bits.SSPIF = 0;
        SSPCON2bits.RCEN = 1;               // Enable receive mode
        while (PIR1bits.SSPIF != 1);        // Wait for byte reception to complete
        PIR1bits.SSPIF = 0;
        m = SSPBUF;
        arr[i] = m;                    // Read received byte

        if (i < 6) {
            SSPCON2bits.ACKDT = 0;          // NACK after last byte
          SSPCON2bits.ACKEN = 1; 
  while (PIR1bits.SSPIF != 1);
PIR1bits.SSPIF = 0;
        }  
    }                             //Husen
       
        SSPCON2bits.ACKDT = 1;
        SSPCON2bits.ACKEN = 1;              // Enable ACK/NACK sequence
         while (PIR1bits.SSPIF != 1);          // Wait for ACK/NACK sequence to complete
           PIR1bits.SSPIF = 0;   
              stop(); 
}

                                    // Stop I2C









// Function to read time from RTC
void rtc_time(void) {
    start();                // I2C Start condition
    i2c_data(0xD0);         // RTC slave address with write bit
    i2c_data(0x00);         // Set internal address pointer to 0x00 (seconds)
    stop();                 // I2C Stop condition
    delay(5);               // Small delay before reading
    i2c_read();             // Read the time bytes from RTC
    display();              // Display the read time on LCD
}







// Function to display formatted time on LCD
void display(void) {
    sec = arr[0];          // Second 
    min = arr[1];          // Minute
   hr = arr[2];           // Hour

 time[6] = ((sec >> 4) & 0x0F) + '0';
    time[7] = (sec & 0x0F) + '0';
     time[5] = ':';

  time[3] = ((min >> 4) & 0x0F) + '0';
    time[4] = (min & 0x0F) + '0';

 time[2] = ':';

 time[0] = ((hr >> 4) & 0x0F) + '0';
    time[1] = (hr & 0x0F) + '0';

 lcd_cmd(0xC0);         // Clear LCD
             // Move to first line


    for (i = 0; i < 8; i++) {
        lcd_data(time[i]);
    }

 //   delay(1000);           // Refresh every second
}

// Simple delay function
void delay(int x) {
    int a, b;
    for (a = 0; a < x; a++)
        for (b = 0; b < 1000; b++);
}
