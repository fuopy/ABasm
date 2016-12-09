#include "globals.h"
#include "data.h"

Ardumod arduboy;

bool new_a, new_b, new_up, new_left, new_down, new_right;
bool old_a, old_b, old_up, old_down, old_left, old_right;

void updateInput()
{
	old_a = new_a;
	old_b = new_b;
	old_up = new_up;
	old_down = new_down;
	old_left = new_left;
	old_right = new_right;
	
	new_a = arduboy.pressed(B_BUTTON);
	new_b = arduboy.pressed(A_BUTTON);
	new_up = arduboy.pressed(UP_BUTTON);
	new_down = arduboy.pressed(DOWN_BUTTON);
	new_left = arduboy.pressed(LEFT_BUTTON);
	new_right = arduboy.pressed(RIGHT_BUTTON);
}

bool modValue(unsigned char &start, short delta, short min, short max)
{
	short val = start;
	val += delta;
	if(val < min) val = min;
	if(val > max) val = max;
	bool changed = (unsigned char)start != (unsigned char)val;
	start = val;
	return changed;
}

void printDecimal(unsigned char x, unsigned char y, unsigned char num)
{
	if(num >= 100) drawChar(x, y, '0' + num/100);
	if(num >= 10) drawChar(x+4, y, '0' + (num%100/10));
	drawChar(x+8, y, '0' + (num%10));
}

void printHex(unsigned char x, unsigned char y, unsigned char num)
{
	printHexDigit(x, y, num/16);
	printHexDigit(x+4, y, num%16);
}

void printHexDigit(unsigned char x, unsigned char y, unsigned char num)
{
	if(num < 0x0a)
	{
		drawChar(x, y, '0' + num);
	}
	else
	{
		drawChar(x, y, 'A' + (num-10));
	}
}

void drawChar(unsigned char x, unsigned char y, unsigned char ch)
{
	arduboy.drawBitmap(x, y, gfx_font + (unsigned short)3 * (ch - '0'), 3, 8, 1);
}