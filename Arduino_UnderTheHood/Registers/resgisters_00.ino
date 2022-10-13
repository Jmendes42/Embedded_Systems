#define PIN_LOW 0   // 0b00000000
#define PIN_HIGH 32 // 0b00100000

#define BLINK 1000

void    setup() {
    DDRB = PIN_HIGH;
}

void    loop() {
    PORTB = PIN_HIGH;
    delay(BLINK);
    PORTB = PIN_LOW;
    delay(BLINK);
}