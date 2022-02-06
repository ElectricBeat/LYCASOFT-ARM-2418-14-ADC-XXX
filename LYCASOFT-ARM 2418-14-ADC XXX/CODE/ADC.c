#include <lpc214x.h>
#include "LPC2148_delay.h"
#include "LPC2148_LCD_4_BIT_HEADER_FILE.h"

int i,ADC_Value;

void divider(unsigned int x)
{
	int Temp,Dig1,Dig2;
	
	Temp = x;

	Dig1 = Temp/10;
	Lcd_Data(Dig1+48);

	Dig2 = Temp%10;
	Lcd_Data(Dig2+48);
}

int main(void)
{
	PINSEL0 = 0x00000000;
	PINSEL1 = 0x01000000;
	
	IODIR0 = 0x000003F0;
	IODIR1 = 0x00000000;

	Lcd_Intialization();
	
	Lcd_Command(0x80);
	Lcd_String("LYCA SOFT");
	
	while(1)                                //while loop that excecutes continueously
	{
		Lcd_Command(0xC0);
		AD0CR = 0X00200E02;
		AD0CR = 0X01000000;
		
		do
		{
			i = AD0GDR;
		}
		while((i & 0X80000000) == 0);
		{
			ADC_Value = (i>>6) & 0X3FF;
		}
	}
}