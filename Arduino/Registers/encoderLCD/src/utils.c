#include "../include/LCD.h"

char                    bufName[16];
char                    bufIndex = 0;
static unsigned char    letter = 'A';

void	writeSaved() {
	command(0x01);
	command(0x80);
	string("SAVED USER", 10);
	command(0xC0);
	string(bufName, bufIndex);
}

void	writeUser() {
	static char l = 0;
	static char j = 0;

	command(0x80);
	for (char i = 0; i < 4 + j; i++)
		writeLCD(' ');
	string("USERNAME", 8);
	command(0xC0);
	for (char i = 0; i < 7 + l; i++)
		command(0x14);
	writeLCD(letter);
	j++;
	l += 2;
}

void	letterSet() {
	char counter = 0;
	static char d = -1;

	while (!(_BV(PC0) & PINC)) {
		_delay_ms(100);
		counter++;
	}
	if (counter < 10 && bufIndex < 16) {
		writeLCD(letter);
		_delay_ms(200);
		if (d++ % 2 == 0) {
			command(0x18);
			writeUser();
		}
		bufName[bufIndex++] = letter;
	}
	else
		writeSaved();
}

void	rotate() {
	loop_until_bit_is_set(PINC, PB1);
	if (ROTA)
		letter -= 1;
	else 
		letter += 1;
	command(0x10);
	writeLCD(letter);
}

void	init() {
	sei();
	DDRD = 0xF0;
	DDRB = 0x38;
	PCICR |= _BV(PCIE1);
	PCMSK1 = 0x07;
	PORTC = 0x07;
}

void	string(unsigned char *str, unsigned char len) {

	for (char i = 0; i < len; i++)
		writeLCD(str[i]);
}