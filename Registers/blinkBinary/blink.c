#include <avr/io.h>
#include <stdbool.h>
#include <util/delay.h>

#define BLINK_MS 200

int main() {

	DDRD = 0xFF;	// Set DDRD to 0b11111111
	PORTB = _BV(0);	// Enable pullup resistor on p

	while (true) {
		if (!(PINB & _BV(0))) {		// Check if button is pushed
			PORTD += 1 << 0; 		// Increment binary count
			_delay_ms(BLINK_MS);
		}
	}
}
