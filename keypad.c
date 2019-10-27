#include "tm4c123gh6pm.h"
#define OUTPUT GPIO_PORTD_DATA_R
#define INPUT GPIO_PORTB_DATA_R

int check(void);
void wait(unsigned long delay);

unsigned char getKey(void)
{
	int row;
  int column;
	int key;
	unsigned char pressed;
	OUTPUT &= 0xF0;
	if ( INPUT == 0x07 )
	{
		row = 1;
	}
	else if ( INPUT == 0x0B )
	{
		row = 2;	
	}
	else if ( INPUT == 0x0D )
	{
		row = 3;
	}
	else if ( INPUT == 0x0E )
	{
		row = 4;
	}
	else
	{
		row = 0;
	  column = 0;
	}
	column = check();
	key = 4*(row-1)+column;
	if(key==1)
		pressed = '1';
	else if(key==2)
		pressed = '2';
	else if(key==3)
		pressed = '3';
	else if(key==4)
		pressed = 'e';
	else if(key==5)
		pressed = '4';
	else if(key==6)
		pressed = '5';
	else if(key==7)
		pressed = '6';
	else if(key==8)
		pressed = 'b';
	else if(key==9)
		pressed = '7';
	else if(key==10)
		pressed = '8';
	else if(key==11)
		pressed = '9';
	else if(key==13)
		pressed = 'r';
	else if(key==14)
		pressed = '0';
	else if(key==15)
		pressed = 'l';
	else
		pressed = 'z';
	return pressed;
}


int check()
{
	 int column = 0;
	 wait(5);
	 OUTPUT &= 0XF0;
	 OUTPUT |= 0X08;
	 if(INPUT == 0x0F)
	 {
		 column = 4;
		 return column;
	 }
	 wait(5);
	 OUTPUT &= 0XF0;
	 OUTPUT |= 0X04;
	 if(INPUT == 0x0F)
	 {
		 column = 3;
		 return column;
	 }	 
	 wait(5);
	 OUTPUT &= 0XF0;
	 OUTPUT |= 0X02;
	 if(INPUT == 0x0F)
	 {
		 column = 2;
		 return column;
	 }
	 wait(5);
	 OUTPUT &= 0XF0;
	 OUTPUT |= 0X01;
	 if(INPUT == 0x0F)
	 {
		 column = 1;
		 return column;
	 }
	 return column;
	 
}