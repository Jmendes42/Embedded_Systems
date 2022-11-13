#include "include/LCD.h"

ISR(PCINT1_vect) {
	if (!(_BV(PC0) & PINC))
		letterSet();
	else if (ROTA & ROTB)
		rotate();
}

int	main() {

	init();
	initialize_lcd();
	writeUser();
	while (true) {
	}
}
