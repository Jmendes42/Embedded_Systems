#include <avr/io.h>
#include <stdbool.h>
#include <util/delay.h>

#define BLINK_MS 100

//#define MASK(x) ((unsigned char) (1<<(x))) = _BV()

int main() {

    DDRB |= _BV(5);

    while (true) {
        PORTB ^= _BV(5);        // |= _BV(PORTB5) && &= ~_BV(PORTB5)
        _delay_ms(BLINK_MS);
    }
}