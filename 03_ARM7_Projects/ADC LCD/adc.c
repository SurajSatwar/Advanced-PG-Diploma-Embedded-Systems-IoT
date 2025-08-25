/* Connections P0.10-RS P0.11-RW P0.12-E
               P0.16 to P0.23 - D0 to D7 */
							 
#include<lpc214x.h>
void delay(int a)
{
  int i, j;
  for(i=0; i<=a; i++)
  for(j=0; j<=10000; j++);	
}

void Delay(unsigned long b)
{
while (--b!=0);
}
 
  void lcd_cmd(unsigned char c)
{
	IO0CLR=0x00ff0000;
	IO0SET|=(c<<16);
	IO0CLR|=(c<<10)| (c<<11);
	IO0SET|=(c<<12);
	delay(10);
	IO0CLR|=(c<<12);
}

void lcd_data(unsigned char d)
{
  IO0CLR=0x00ff0000;
	IO0SET|=(d<<16);
	IO0CLR|=(1<<11);
	IO0SET|=(1<<10);
	IO0SET|=(1<<12);
		delay(10);
	IO0CLR|=(c<<12);
}

void init_lcd(void)
{
 IO0DIR=0x00ff1fff;
	IO0CLR=0x00ff1fff;
	
	       lcd_cmd(0x30);
	       lcd_cmd(0x80);
	       lcd_cmd(0x0c);
	       lcd_data('A');
	       lcd_data('D');
	       lcd_data('C');
}
void adc_init(void)
{
PINSEL1=0x01000000;
	AD0CR=0x00200202;
}
int read_adc0(void)
{
int val;
	AD0CR|=0x01000000;
	do{
  val=AD0CR1;
} while((val&(1<<31))==0);
  AD0CR&=~0x01000000;
  val>>=6;
val=val&0x3ff;
return(val);

}
 int main()
{
int dat,i=0;
	
	char buf[5];
	init_lcd();
	adc_init();
	IO0DIR|=0x00ff0000;
	while(1)
	{
  Delay(200000);
		lcd_cmd(0xC0);
		IO0CLR!=0x00000FFF;
		dat=read_adc0();
		
		
		i=0;
		while(dat>0)
		{
      buf[i]=dat%10;
			dat=dat/10;
			i++;
}
while(--i>=0)
{
lcd_data(' ');
	lcd_data(' ');
}
}
}