/*
 * newPADOLO.c
 *
 * Created: 01-Jun-21 11:01:04 PM
 * Author : SHADY MEDHAT
 */ 

#include <avr/io.h>
#include <util/delay.h>
#include "lcd_4bit_AMIT.h"
#include "KEYPAD.h"

int main(void)
{
    /* Replace with your application code */
	LCD_Init();/* Initializing LCD settings as desired*/
	LCD_Clear();
	SET_BIT(DDRD,7); /* Initializing last pin in PORTD to be o/p*/
	int x;
	char Pin[6]; /* Array to save entered pin*/
	while(1)
	{
		if(state== closed)
		{
			if(TR_Counter<3)
			{
				LCD_Clear();
				LCD_String_xy(0,3,"   PIN CODE:");
				for(x=0;x<6;x++) /* 6 is the no of allowed Entries for the pin*/
				{
					Pin[x]=KeyPad_getPrKey()+48; /* fills the array with characters from the keypad */
					while((!(PINC & (1<<0)))|(!(PINC & (1<<1)))|(!(PINC & (1<<2)))|(!(PINC & (1<<3)))) // SHADY's
					{
						/* open loop to keep the processor waiting until pressed button is released*/
					}
					LCD_Char(Pin[x]); /* Display Entered pin on LCD*/
				}

				str_cmp(Pin); /* Compared Entered pin with saved one to check*/
			}
			else 	
			{
				//PORTB|=(1<<7);
			}
		}
		else /* state is opened*/
		{
			LCD_Clear();
			LCD_String_xy(0,3,"   WELCOME BOSS");
			while(!(PINC&(1<<0)))
			{
				/* open loop to keep the processor waiting until pressing button to lock the door*/
			}
			state=closed;
			LCD_Clear();
			LCD_String_xy(0,3,"   CLOSING");
			SET_BIT(PORTC,1);
			CLEAR_BIT(PORTB,0);
			_delay_ms(10000);
		}
	}
}