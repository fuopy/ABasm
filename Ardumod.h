#ifndef _ARDUMOD_H
#define _ARDUMOD_H

#include <Arduboy.h>

class Ardumod : public Arduboy
{
    public:
		void invertRect(int16_t x, int16_t y, uint8_t w, uint8_t h);
		void drawPixel(int x, int y, uint8_t color);
		void grayRect(int16_t x, int16_t y, uint8_t w, uint8_t h);
		void fillRect(int16_t x, int16_t y, uint8_t w, uint8_t h, uint8_t color);
		void drawFastVLine(int16_t x, int16_t y, uint8_t h, uint8_t color);
};

#endif
