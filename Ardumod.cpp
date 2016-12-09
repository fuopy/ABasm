#include "Ardumod.h"


void Ardumod::invertRect(int16_t x, int16_t y, uint8_t w, uint8_t h)
{
	if(y < 0)
	{
		h += y;
		y = 0;
	}
	if(x < 0)
	{
		w += x;
		x = 0;
	}

	uint8_t row, page, col;

	unsigned char pageY = y%8;
	unsigned char fullPages = (h - (8 - pageY))/8;

	unsigned char lowerPart = 0xff << pageY;
	unsigned char upperPart = ~(0xff << ((y+h)%8));

	row = y/8;

	for(col = 0; col < w; col++)
	{
		int16_t address = (row*WIDTH) + (uint8_t)x+col;
		if(address > sizeof(sBuffer)) continue;
		if(address < 0) continue;

		sBuffer[address] ^= lowerPart;
	}
	
	
	for(page = 1; page <= fullPages && page < 8; page++)
	//for(page = 0; page < h/8; page++)
	{
		row = page + y/8;
	
		for(col = 0; col < w; col++)
		{
			int16_t address = (row*WIDTH) + (uint8_t)x+col;
			if(address > sizeof(sBuffer)) continue;
			if(address < 0) continue;
			
			sBuffer[address] ^= 0xff;
		}
	}

	row = page + y/8;

	for(col = 0; col < w; col++)
	{
		int16_t address = (row*WIDTH) + (uint8_t)x+col;
		if(address > sizeof(sBuffer)) continue;
		if(address < 0) continue;

		sBuffer[address] ^= upperPart;
	}
}

void Ardumod::drawPixel(int x, int y, uint8_t color)
{
  #ifdef PIXEL_SAFE_MODE
  if (x < 0 || x > (WIDTH-1) || y < 0 || y > (HEIGHT-1))
  {
    return;
  }
  #endif

  uint8_t row = (uint8_t)y / 8;
  if (color == 1)
  {
    sBuffer[(row*WIDTH) + (uint8_t)x] |=   _BV((uint8_t)y % 8);
  }
  else if(color == 0)
  {
    sBuffer[(row*WIDTH) + (uint8_t)x] &= ~ _BV((uint8_t)y % 8);
  }
  else
  {
	sBuffer[(row*WIDTH) + (uint8_t)x] ^= _BV((uint8_t)y % 8);
  }	   
}

void Ardumod::grayRect(int16_t x, int16_t y, uint8_t w, uint8_t h)
{
	if(y < 0)
	{
		h += y;
		y = 0;
	}
	if(x < 0)
	{
		w += x;
		x = 0;
	}
	
	uint8_t row, page, col;
	
	for(page = 0; page < h/8; page++)
	{
		row = (uint8_t)y / 8 + page;
	
		for(col = 0; col < w; col++)
		{
			int16_t address = (row*WIDTH) + (uint8_t)x+col;
			if(address > sizeof(sBuffer)) continue;
			if(address < 0) continue;
			
			if(col%2 == 0)
				sBuffer[address] = 0b01010101;
			else
				sBuffer[address] = 0b10101010;
		}
	}
}

/* unmodified from core lib 1.1 */

void Ardumod::fillRect
(int16_t x, int16_t y, uint8_t w, uint8_t h, uint8_t color)
{
  drawFastHLine(x, y, w, color);  // stupidest version - update in subclasses if desired!
  for (int16_t i=x; i<x+w; i++)
  {
    drawFastVLine(i, y, h, color);
  }

}

void Ardumod::drawFastVLine
(int16_t x, int16_t y, uint8_t h, uint8_t color)
{
  int end = y+h;
  for (int a = max(0,y); a < min(end,HEIGHT); a++)
  {
    drawPixel(x,a,color);
  }
}