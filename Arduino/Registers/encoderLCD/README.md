
#### Useful Links

[LCD Module DataSheet](https://www.openhacks.com/uploadsproductos/eone-1602a1.pdf)

[AVR Macros Used](https://manpages.debian.org/testing/avr-libc/loop_until_bit_is_set.3avr.en.html)

[Rotary Encoder](https://www.allaboutcircuits.com/projects/how-to-use-a-rotary-encoder-in-a-mcu-based-project/)

#### Goals for this project:

  - Get familiar with LCD 1602 module;
  - Get familiar with rotary encoder;
  - Get familiar with external interrupts;
  - List of the used commands:

    - 0x01 ; 1 -> Clear display;
    - 0x06 ; 0110 -> Entry mode;
    - 0x38 ; 00111000	-> 8b 2 lines;
    - 0x28 ; 00101000	-> 4b 2 lines;
    - 0x10 ; 10000 -> Move cursor left;
    - 0x14 ; 10100 -> Move cursor right;
    - 0x80 ; 10000000	-> Cursor on 0,0;
    - 0xC0 ; 11000000	-> Cursor on 1,0;
    - 0x0F ; 1111	-> Display on, cursor blink;
