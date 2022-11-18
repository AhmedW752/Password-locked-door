/*
 * KEYPAD.h
 *
 * Created: 02-Jun-21 2:16:37 AM
 *  Author: SHADY MEDHAT
 */ 


#ifndef KEYPAD_H_
#define KEYPAD_H_

#include <avr/io.h>
#include <util/delay.h>

/* Set a certain bit in any register /
#define SET_BIT(REG,BIT) (REG|=(1<<BIT))

/ Clear a certain bit in any register /
#define CLEAR_BIT(REG,BIT) (REG&=(~(1<<BIT)))

/ LCD HW Pins /
#define RS PB1
#define RW PB2
#define E  PB3
#define LCD_CTRL_PORT_DIR DDRB
#define LCD_CTRL_PORT PORTB
#define LCD_DATA_PORT_DIR DDRA
#define LCD_DATA_PORT PORTA


/ LCD Commands */
#define CLEAR_COMMAND 0x01
#define HOME 0x02
#define TWO_LINE_LCD_Eight_BIT_MODE 0x30
#define CURSOR_OFF 0x0C
#define CURSOR_ON 0x0E
#define SET_CURSOR_LOCATION 0x80

#define N_col 3
#define opened 0
#define closed 1
#define N_row 4


static unsigned char KeyPad_4x3_adjustKeyNumber(unsigned char button_number);
void str_cmp(char pwd[]);
unsigned char KeyPad_getPrKey(void);



#endif /* KEYPAD_H_ */