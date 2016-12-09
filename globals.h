#ifndef _GLOBALS_H
#define _GLOBALS_H

#include "Ardumod.h"

extern Ardumod arduboy;

#define A_DOWN new_a
#define A_PRESSED (new_a && !old_a)
#define A_RELEASED (!new_a && old_a)

#define B_DOWN new_b
#define B_PRESSED (new_b && !old_b)
#define B_RELEASED (!new_b && old_b)

#define UP_DOWN new_up
#define UP_PRESSED (new_up && !old_up)
#define UP_RELEASED (!new_up && old_up)

#define DOWN_DOWN new_down
#define DOWN_PRESSED (new_down && !old_down)
#define DOWN_RELEASED (!new_down && old_down)

#define LEFT_DOWN new_left
#define LEFT_PRESSED (new_left && !old_left)
#define LEFT_RELEASED (!new_left && old_left)

#define RIGHT_DOWN new_right
#define RIGHT_PRESSED (new_right && !old_right)
#define RIGHT_RELEASED (!new_right && old_right)



#define TONE_MENUBAR_CURSOR 880
#define TONE_MENUBAR_BEEP 1174
#define TONE_MENUBAR_FLIP 990
#define TONE_MENUBAR_SHOW 1174

extern bool new_a, new_b, new_up, new_left, new_down, new_right;
extern bool old_a, old_b, old_up, old_down, old_left, old_right;

void updateInput();

void printDecimal(unsigned char x, unsigned char y, unsigned char num);
void printHex(unsigned char x, unsigned char y, unsigned char num);
void printHexDigit(unsigned char x, unsigned char y, unsigned char num);
void drawChar(unsigned char x, unsigned char y, unsigned char ch);
bool modValue(unsigned char &start, short delta, short min, short max);

#endif
