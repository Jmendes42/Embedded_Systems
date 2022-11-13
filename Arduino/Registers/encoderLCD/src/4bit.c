#include "../include/LCD.h"

void	writeLCD(unsigned char c) {

	PORTD = c & 0xF0;;
	PORTB |= _BV(PB5) | _BV(PB3);
	PORTB &= ~_BV(PB4);
	_delay_ms(3);
	PORTB &= ~_BV(PB3);

	PORTD = (c << 4) & 0xF0;
	PORTB |= _BV(PB5) | _BV(PB3);
	PORTB &= ~_BV(PB4);
	_delay_ms(3);
	PORTB &= ~_BV(PB3);
}

void	command(unsigned char cmd) {
	
	PORTD = cmd & 0xF0;
	PORTB |= _BV(PB3);
	PORTB &= ~_BV(PB5) & ~_BV(PB4);
	_delay_ms(3);
	PORTB &= ~_BV(PB3);

	PORTD = (cmd << 4) & 0xF0;
	PORTB &= ~_BV(PB5) & ~_BV(PB4);
	PORTB |= _BV(PB3);
	_delay_ms(3);
	PORTB &= ~_BV(PB3);
}

void	initialize_lcd() {

	command(0x28);
	command(0x06);
	command(0x0F);
	command(0x01);
}

