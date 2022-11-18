/*
 * KEYPAD.c
 *
 * Created: 02-Jun-21 2:19:24 AM
 *  Author: SHADY MEDHAT
 */ 
unsigned char TR_Counter=0;
unsigned char state= closed;
unsigned char KeyPad_getPrKey(void)
{
	unsigned char col,row;
	while(1)
	{
		for(col=0;col<N_col;col++) /* loop for columns */
		{
			/* 		each time only one of the column pins will be output and
			  	  	  the rest will be input pins including the row pins
			 */
			DDRC = (0b00010000<<col); //00010000
			/*		  clear the output pin column in this trace and enable the internal
	 	 	 	 	 pull up resistors for the rows pins
			*/
			PORTC = (~(0b00010000<<col)); //11101111

			for(row=0;row<N_row;row++) /* loop for rows */
			{
				if(!(PINC & (1<<row))) /* if the switch is press in this row */
				{
						return KeyPad_4x3_adjustKeyNumber((row*N_col)+col+1); // returning value of pressed key
				}
			}
		}
	}
}

static unsigned char KeyPad_4x3_adjustKeyNumber(unsigned char button_number) // function for symbols in lower keypad buttons
{
	switch(button_number)
	{
		case 10: return '*';
				 break;
		case 11: return 0;
				 break;
		case 12: return '#';
				 break;
		default: return button_number;
	}
}
void str_cmp(char pwd[])
{
	char PASS[] = "752759"; /* SAVED PIN*/
	if (strcmp(PASS,pwd) == 0)
	{
		/* CASE CORRECT PIN*/
		_delay_ms(1000);
		LCD_Clear();
		LCD_String_xy(0,3,"   ACCESS GRANTED");
		// LCD_displayCharacter(128275);
		SET_BIT(PORTD,7);
		SET_BIT(PORTC,7);
		/* puts 1 on PIN1 in PORTB for motor to operate and green LED */
		_delay_ms(10000);/* wait until door is opened*/
		//PORTB&=(0X00); /* Motor stops to stop the door*/
		state=opened;

	}
	else
	{							/* CASE INCORRECT PIN*/
		_delay_ms(1000);
		LCD_Clear();
		LCD_String_xy(0,3,"   ACCESS DENIED");
		SET_BIT(PORTD,3);
		SET_BIT(PORTA,3);
		_delay_ms(4000);
		CLEAR_BIT(PORTA,3);
	}
}
