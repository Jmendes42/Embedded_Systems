#ifndef LCD_H
#define LCD_H

#include <avr/io.h>
#include <stdbool.h>
#include <util/delay.h>
#include <avr/interrupt.h>

#define ROTA !(_BV(PC2) & PINC)
#define ROTB !(_BV(PC1) & PINC)

// UTILS
void	init();
void	rotate();
void	writeUser();
void	letterSet();
void	writeSaved();
void	string(unsigned char *str, unsigned char len);

// 4BITS
void	initialize_lcd();
void	writeLCD(unsigned char c);
void	command(unsigned char cmd);

// 8BITS
/*void	8b_initialize_lcd();
void	8b_writeLCD(unsigned char c);
void	8b_command(unsigned char cmd);*/

#endif
