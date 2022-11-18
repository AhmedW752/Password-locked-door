/*
 * IncFile1.h
 *
 * Created: 01-Jun-21 11:02:10 PM
 *  Author: SHADY MEDHAT
 */ 


#ifndef lcd_4bit_AMIT_H_
#define lcd_4bit_AMIT_H_

#include <avr/io.h>
#include <util/delay.h>

/* Set a certain bit in any register */
#define SET_BIT(REG,BIT) (REG|=(1<<BIT))

/* Clear a certain bit in any register */
#define CLEAR_BIT(REG,BIT) (REG&=(~(1<<BIT)))

#define RS PB1 /* Define Register Select pin */
#define RW PB2
#define E PB3 /* Define Enable signal pin */
#define LCD_CTRL_PORT_DIR DDRB /*define LCD control port direction */
#define LCD_CTRL_PORT PORTB		/*define LCD control port */

#define LCD_Dir  DDRA			/* Define LCD data port direction */
#define LCD_Port PORTA			/* Define LCD data port */


/* LCD Commands */
#define CLEAR_COMMAND 0x01
#define HOME 0x02
#define TWO_LINE_LCD_Eight_BIT_MODE 0x30
#define CURSOR_OFF 0x0C
#define CURSOR_ON 0x0E
#define SET_CURSOR_LOCATION 0x80


void LCD_Command( unsigned char cmnd );
void LCD_Char( unsigned char data );
void LCD_Init (void);
void LCD_String (char *str);
void LCD_String_xy (char row, char pos, char *str);
void LCD_Clear();
#endif /* lcd_4bit_AMIT_H_ */