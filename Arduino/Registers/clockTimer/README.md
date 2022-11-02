#### ClockTimer

This project series consist of bare-metal programs that use a four seven segment display to count seconds and minutes.

For this project, my goals were:

  - Get familiar with navigating the data sheet;
  - To get familiar with interrupts (ISR) and clock timers;
  - Get to know all the types of interrupts possible with timers;
  - Broaden my knowledge on registers and binary operations;
  - Conciliate both registers and timers;
  - Also got the opportunity to get familiar with the four seven segment display;

![Untitled ‑ Made with FlexClip(12)](https://user-images.githubusercontent.com/74921179/199434645-3efd5a59-6628-4c31-bc5d-698023d9b08d.gif)

**Notes:**

1st version -> Timer Overflow:
  
  - Number configurations are in hexadecimal numeration in an array;
  - The ```sei()``` function enables the use of timers;
  - Timer 1 will be used on this exercise. To enable, just write 1 to the bit 0 (**TOIE1**) of **TIMSK1** register

![TIMSK1](https://user-images.githubusercontent.com/74921179/198903385-58067cdc-4de2-4f84-a8de-a37a0d27f6b0.png)

  - To set the timer mode to overflow (normal mode), the following bits in **TCCR1A** and **TCCR1B** must be at 0 value:
    - **WGM10** and **WGM11** in **TCCR1A**;
    - **WGM12** and **WGM13** in **TCCR1B**;

![normal](https://user-images.githubusercontent.com/74921179/198903683-c528b212-86e6-4561-a586-089592032ebc.png)
![TCCR1A](https://user-images.githubusercontent.com/74921179/198903686-f982525d-3903-49b2-bf1f-ca7b92047e3c.png)
![TCCR1B](https://user-images.githubusercontent.com/74921179/198903689-f1223610-8d3d-499d-b985-97491d5ab879.png)

  - The presacaler is set to 1024. This means that the frequency of the timer (16MHz) will be divided by the value 1024. To set this the **CS12** and **CS10** bits of **TCCR1B** must be set to 1.

![presacaler](https://user-images.githubusercontent.com/74921179/198904015-2207c728-5ce7-4a91-ac2f-32697e7b8e22.png)
![TCCR1B](https://user-images.githubusercontent.com/74921179/198904018-39eb1d2a-8b9f-4382-9735-f70d127ed4bf.png)

