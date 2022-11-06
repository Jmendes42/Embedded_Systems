#include "LCD.h"

// 0x38 ; 00111000	-> 8b 2 lines
// 0x28 ; 00101000	-> 4b 2 lines
// 0x06 ; 0110		-> Entry mode
// 0x0F ; 1111		-> Display on, cursor blink
// 0x01 ; 1			-> Clear display
// 0x80 ; 10000000	-> Cursor on 0,0
// 0xC0 ; 11000000	-> Cursor on 1,0
// 0x10 ; 10000		-> Move cursor left
// 0x14 ; 10100		-> Move cursor right

const unsigned char abc[52] =	{'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P',
									'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', 'a', 'b', 'c', 'd', 'e',
										'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's',
											't', 'u', 'v', 'w', 'x', 'y', 'z'};

void	writeLCD(unsigned char c) {

	PORTD = c & 0xF0;;
	PORTB |= _BV(PB0) | _BV(PB2);
	PORTB &= ~_BV(PB1);
	_delay_ms(20);
	PORTB &= ~_BV(PB2);

	PORTD = (c << 4) & 0xF0;
	PORTB |= _BV(PB0) | _BV(PB2);
	PORTB &= ~_BV(PB1);
	_delay_ms(20);
	PORTB &= ~_BV(PB2);
}

void	command(unsigned char cmd) {
	
	PORTD = cmd & 0xF0;
	PORTB |= _BV(PB2);
	PORTB &= ~_BV(PB0) & ~_BV(PB1);
	_delay_ms(20);
	PORTB &= ~_BV(PB2);

	PORTD = (cmd << 4) & 0xF0;
	PORTB &= ~_BV(PB0) & ~_BV(PB1);
	PORTB |= _BV(PB2);
	_delay_ms(20);
	PORTB &= ~_BV(PB2);
}

void	initialize_lcd() {

	command(0x28);
	command(0x06);
	command(0x0F);
	command(0x01);
}

void	string(unsigned char *str, unsigned char len) {

	for (char i = 0; i < len; i++)
		writeLCD(str[i]);
}

ISR(PCINT1_vect) {


}

int	main() {

	unsigned char letter = 'A';
	_delay_ms(20);
	DDRD = 0xF0;
	DDRB = 0x07;
	PCICR |= _BV(PCIE1);

	PCMSK1 = 0x07;
	//PORTC |= _BV(PC0) | _BV(PC1) | _BV(PC2);
	initialize_lcd();
	
	command(0x80);
	for (char i = 0; i < 4; i++)
		command(0x14);
	string("USERNAME", 8);
	command(0xC0);
	for (char i = 0; i < 8; i++)
		command(0x14);
	writeLCD(letter);
	while (true) {
		if (!(PIND & _BV(PINC3))) {
			writeLCD(++letter);
			_delay_ms(100);
		}
	}
}
