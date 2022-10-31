#include <avr/io.h>
#include <stdbool.h>
#include <util/delay.h>
#include <avr/interrupt.h>

const unsigned char numbers[10] = {0x3F, 0x6, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x7, 0x7F, 0x67};

int i = 0;

//IMPLEMENT THE INTERRUPT HANDLER FUNCTION
ISR(TIMER1_OVF_vect)
{
	// USER CODE
	TCNT1 = 49910;
	i++;
}	

void	minutes(int min) {

	if (min < 10) {
		PORTB ^= _BV(2);
		PORTD |= numbers[min] | _BV(7);
		_delay_ms(1);
		PORTB ^= _BV(2);
		PORTB ^= _BV(3);
		PORTD = numbers[0];
		_delay_ms(1);
		PORTB ^= _BV(3);
	}
	else {
		int deciMin = min / 10;
		PORTB ^= _BV(3);
		PORTD = numbers[deciMin];
		_delay_ms(1);
		PORTB ^= _BV(3);
		PORTB ^= _BV(2);
		PORTD = numbers[min - (deciMin * 10)];
		_delay_ms(1);
		PORTB ^= _BV(2);
	}
}

int		secconds() {
	
	if (i < 10) {
		PORTB ^= _BV(0);
		PORTD = numbers[i];
		_delay_ms(1);
		PORTB ^= _BV(0);
		PORTB ^= _BV(1);
		PORTD = numbers[0];
		_delay_ms(1);
		PORTB ^= _BV(1);
	}
	else {
		int deciSec = i / 10;
		PORTB ^= _BV(1);
		PORTD = numbers[deciSec];
		_delay_ms(1);
		PORTB ^= _BV(1);
		PORTB ^= _BV(0);
		PORTD = numbers[i - (deciSec * 10)];
		_delay_ms(1);
		PORTB ^= _BV(0);
		return (deciSec);
	}
	return (0);
}

int		main()
{
	DDRB = 0xF;
	DDRD = 0xFF;

	// ENABLE THE GLOBAL INTERRUPT ENABLE BIT
	sei(); 

	// ENABLE THE REQUIRED TIMER INTERRUPT
	TIMSK1 |= 1 << TOIE1;

	//SET THE MODE OF THE TIMER
	TCCR1A &= ~(1 << WGM10) & ~(1 << WGM11);
	TCCR1B &= ~(1 << WGM12) & ~(1 << WGM13);

	//SET THE PRESCALER FOR THE TIMER
	TCCR1B |= _BV(CS10) | _BV(CS12);
	TCCR1B &= ~_BV(CS11);						// PRESCALAR TO 1024

	//SET THE PERIOD FOR THE TIMER
	TCNT1 = 49910;								// VALUE FROM WICH THE COUNTER STARTS FOR 1S

	int min = 0;

	while (true) {
		PORTD = 0x00;
		minutes(min);
		if (secconds() == 6) {
		   i = 0;
		   min++;;
		}	   
	}
}
