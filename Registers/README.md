## Registers

- Registers are fast storage locations that can store binary data. They are meant to temporarily store data which needs to be processed by the CPU, or to store addresses pointed to data which needs to be fetched. They are meant to store the current context of the CPU.

In Arduino (ATMEGA328p) there are three main memory blocks or types:

  - Program Memory (Flash)
  - Data Memory(SRAM)
  - EEPROM
 
 
Registers exist in data memory (SRAM), which has a total of 2Kb

![SRAM](https://user-images.githubusercontent.com/74921179/198893001-15c87663-5f44-43ce-8741-2eeca7127803.png)

Registers can be used to access pins. Each pin has its own functions, one of them is as an input or an output (I/O).

### Manipulating registers:

There are three ports in the Arduino (ATMEGA328p), port B, C and D. Each port consists of three registers: **DD**xn, **PORT**xn and **PIN**xn

  - **DD**xn (Data Direction register) function is to determine if the configuration will be input or output.
  - **PORT**xn (Port register) function is to access the pins.
  - **PIN**xn (PIN register) is nomenclature for the pins in a specific port.

**DD**xn bits are accessed at the **DDR**x I/O address, the **PORT**xn bits at the **PORT**x I/O address, and the **PIN**xn
bits at the PINx I/O address.

If **DD**xn is written as a one, **PIN**xn is configured as an output. If **DD**xn is written as a zero, **PIN**xn is configured as an input.

If **PORT**xn is written as a one when the pin is configured as an input, the pin's pull-up resistor is activated. To switch the
pull-up resistor off, **PORT**xn has to be written logic zero.

If **PORT**xn is written as a one when the pin is configured as an output, the pin is driven high (one). If **PORT**xn is written as a zero when the pin is configured as an output, the port pin is driven low (zero)
