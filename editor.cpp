#include "globals.h"
#include "editor.h"
#include "vm.h"
#include "data.h"

#define PARAM_FORM_NOTHING     0
#define PARAM_FORM_NUM         1
#define PARAM_FORM_ADDRESS     2
#define PARAM_FORM_BUTTONMAP   3
#define PARAM_FORM_REG         4
#define PARAM_FORM_REG_REG_NUM 5
#define PARAM_FORM_REG_REG_REG 6

#define PARAM_SPACING 2
#define CHAR_WIDTH 4
#define REGISTER_WIDTH 8
#define BUTTON_WIDTH 8
#define OPCODE_WIDTH 38
#define BREAKPOINT_WIDTH 5

#define OPCODE_START 12

#define REPEAT_DELAY_TIME 20


#define MENU_ICON 0
#define MENU_EDIT 1
#define MENU_RUN 2
#define MENU_FILE 999

//#define MENU_FILE 1
//#define MENU_EDIT 2
//#define MENU_RUN 3

unsigned char cursorY = 0;
unsigned char cursorX = 0;
unsigned char scrollY = 255;
unsigned char repeatDelay = REPEAT_DELAY_TIME;
unsigned char offsetY = 0;

VMState vms = {
	{0, 0, 0, 0, 0, 0, 0, 0}, 0, false
};

const unsigned char opcode_param_counts[] = {
	0, 1, 1, 6, 1, 3, 3
};

const unsigned char opcode_params[] = {
	// 00 through 0f
	PARAM_FORM_NUM,
	PARAM_FORM_REG,
	PARAM_FORM_NUM,
	PARAM_FORM_REG,
	PARAM_FORM_NUM,
	PARAM_FORM_REG,
	PARAM_FORM_NUM,
	PARAM_FORM_REG,
	PARAM_FORM_REG,
	PARAM_FORM_REG,
	PARAM_FORM_NUM,
	PARAM_FORM_REG,
	PARAM_FORM_REG,
	PARAM_FORM_REG,
	PARAM_FORM_REG,
	PARAM_FORM_NUM,
	
	// f0 through ff
	PARAM_FORM_NOTHING,
	PARAM_FORM_NUM,
	PARAM_FORM_REG_REG_NUM,
	PARAM_FORM_REG_REG_REG,
	PARAM_FORM_REG_REG_REG,
	PARAM_FORM_NOTHING,
	PARAM_FORM_BUTTONMAP,
	PARAM_FORM_BUTTONMAP,
	PARAM_FORM_ADDRESS,
	PARAM_FORM_REG,
	PARAM_FORM_ADDRESS,
	PARAM_FORM_ADDRESS,
	PARAM_FORM_NUM,
	PARAM_FORM_NOTHING,
	PARAM_FORM_NOTHING,
	PARAM_FORM_NOTHING
};

void drawEditor();

void insertOperation(bool updateJumps);
void deleteOperation(bool updateJumps);

void printRegister(unsigned char x, unsigned char y, unsigned char num);
void printButtonMap(unsigned char x, unsigned char y, unsigned char num);
void printButton(unsigned char x, unsigned char y, unsigned char num);

unsigned char getOpcodeParamForm(unsigned char opcode);
unsigned char elementCount(unsigned char line);

void drawCodeLines(unsigned char start);
void drawCodeLine(unsigned char x, unsigned char y, unsigned char line, unsigned char opcode, unsigned char param);
void drawOpcodeAndParam(unsigned char x, unsigned char y, unsigned char opcode, unsigned char param);
void drawOpcode(unsigned char x, unsigned char y, unsigned char id);
void drawParam(unsigned char x, unsigned char y, unsigned char param, unsigned char form);
void drawCursor();

void drawScrollbar();
void drawScrollLine(unsigned char x, unsigned short y, unsigned char line, unsigned char opcode, unsigned char param);

void updateCursorDelay();
bool checkCursorDelay();
void moveCursor(char dx, char dy);
void activateCursor();
void activateOpcode(unsigned char opcodeIndex);
void activateParam(unsigned char paramIndex, unsigned char paramElement, unsigned char form);

unsigned char menuBlinkDelay = 35;
unsigned char menuBlinkEnabled = false;
unsigned char menuReleaseActivate = true;

void printRegister(unsigned char x, unsigned char y, unsigned char num)
{
	arduboy.drawBitmap(x, y, gfx_registers + (unsigned short)8 * num, 8, 8, 1);
}

void printButtonMap(unsigned char x, unsigned char y, unsigned char num)
{
	
	if(num & 128) printButton(x, y, 6); else printButton(x, y, 0);
	x += BUTTON_WIDTH + PARAM_SPACING;
	if(num & 64) printButton(x, y, 5); else printButton(x, y, 0);
	x += BUTTON_WIDTH + PARAM_SPACING;
	if(num & 32) printButton(x, y, 4); else printButton(x, y, 0);
	x += BUTTON_WIDTH + PARAM_SPACING;
	if(num & 16) printButton(x, y, 3); else printButton(x, y, 0);
	x += BUTTON_WIDTH + PARAM_SPACING;
	if(num & 8) printButton(x, y, 2); else printButton(x, y, 0);
	x += BUTTON_WIDTH + PARAM_SPACING;
	if(num & 4) printButton(x, y, 1); else printButton(x, y, 0);
}

void printButton(unsigned char x, unsigned char y, unsigned char num)
{
	arduboy.drawBitmap(x, y, gfx_buttons + (unsigned short)8 * num, 8, 8, 1);
}


void drawOpcode(unsigned char x, unsigned char y, unsigned char id)
{
	unsigned short offset = (id&0x0f) * OPCODE_WIDTH;
	
	if(id < 0xf0)
	{
		offset = ((id&0x0f)+16) * OPCODE_WIDTH;
		
		arduboy.drawBitmap(x+29, y, gfx_registers + 8*((id&0xf0)>>4), 8, 8, 1);
	}
	
	arduboy.drawBitmap(x, y, gfx_opcodes + offset, OPCODE_WIDTH, 8, 1);
}


void drawScrollbar()
{
	unsigned char line;
	
	unsigned char opcode;
	unsigned char param;
	unsigned char index;
	unsigned char bonus;
	
	unsigned char scrollArea = WIDTH - 10;
	
	for(line = 0; line < PROGRAM_CODE_LENGTH/2; line++)
	{
		index = line*2;
		if(index >= PROGRAM_CODE_LENGTH) break;
		
		opcode = initCode[index];
		param = initCode[index + 1];
		
		drawScrollLine(scrollArea, offsetY + line*2 - cursorY*2 + 32, 2*line, opcode, param);
	}
}

void updateCursorDelay()
{
	if(UP_DOWN || DOWN_DOWN || LEFT_DOWN || RIGHT_DOWN)
	{
		if(repeatDelay > 0)
		{
			repeatDelay--;
		}
		else if(repeatDelay == 0)
		{
			if(UP_DOWN || DOWN_DOWN || LEFT_DOWN || RIGHT_DOWN)
			{
				repeatDelay = 2;
			}
		}
	}
	else
	{
		repeatDelay = REPEAT_DELAY_TIME;
	}
}

bool checkCursorDelay()
{
	return repeatDelay == 0;
}

unsigned char getOpcodeParamForm(unsigned char opcode)
{
	if(opcode < 0xf0)
	{
		return opcode_params[opcode&0x0f];
	}

	return opcode_params[opcode - 0xf0 + 0x10];
}

void drawParam(unsigned char x, unsigned char y, unsigned char param, unsigned char form)
{
	if(form == PARAM_FORM_NOTHING)
	{
		// do nothing
	}
	else if(form == PARAM_FORM_NUM)
	{
		printHex(x, y, param);
		printButton(x, y, 0);
	}
	else if(form == PARAM_FORM_ADDRESS)
	{
		// printAddress(x, y, param);
		printHex(x, y, param);
		printButton(x, y, 0);
	}
	else if(form == PARAM_FORM_BUTTONMAP)
	{
		printButtonMap(x, y, param);
	}
	else if(form == PARAM_FORM_REG)
	{
		printRegister(x, y, param);
		printButton(x, y, 0);
	}
	else if(form == PARAM_FORM_REG_REG_NUM)
	{
		printRegister(x, y, (param&0b00000111));
		printButton(x, y, 0);
		
		printRegister(x+10, y, (param&0b00111000)>>3);
		printButton(x+10, y, 0);
		
		printHex(x+20, y, (param&0b11000000)>>6);
		printButton(x+20, y, 0);
	}
	else if(form == PARAM_FORM_REG_REG_REG)
	{
		printRegister(x, y, (param&0b00000111));
		printButton(x, y, 0);
		
		printRegister(x+10, y, (param&0b00111000)>>3);
		printButton(x+10, y, 0);
		
		printRegister(x+20, y, ((param&0b11000000)>>6) + 4);
		printButton(x+20, y, 0);
	}
}


void drawCodeLine(unsigned char x, unsigned char y, unsigned char line, unsigned char opcode, unsigned char param)
{
	if(lineFlags[line/2] == 1)
	{
		arduboy.fillRect(x, y+1, 3, 3, 1);
	}
	printHex(x+BREAKPOINT_WIDTH, y, line);
	drawChar(x+8+BREAKPOINT_WIDTH, y, ':');
	drawOpcodeAndParam(x+12+BREAKPOINT_WIDTH, y, opcode, param);
}

const unsigned char opcodeLengths[] = {
	1,3,3,2,2,3,3,2,2,2,1,1,1,3,1,1,
	1,1,2,2,2,2,2,2,2,2,2,2,2,2,2,2
};

void drawScrollLine(unsigned char x, unsigned short y, unsigned char line, unsigned char opcode, unsigned char param)
{
	unsigned char form = getOpcodeParamForm(opcode);
	unsigned char opcodeLength = 0;
	
	if(line == cursorY*2)
	{
		arduboy.drawPixel(x-2, y, 1);
	}
	
	// if it's a register opcode
	if(opcode < 0xf0)
	{
		opcode &= 0x0f;
		opcode += 0x10;
		opcodeLength = opcodeLengths[opcode];
		arduboy.drawPixel(x+2, y, 1);
	}
	// if it's a general opcode
	else
	{
		opcode = opcode - 0xf0;
		opcodeLength = opcodeLengths[opcode];
	}
	
	arduboy.drawFastHLine(x, y, opcodeLength, 1);
	
	x += 4;
	
	if(form == PARAM_FORM_NOTHING)
	{
		// do nothing
	}
	else if(form == PARAM_FORM_NUM || form == PARAM_FORM_ADDRESS || form == PARAM_FORM_REG)
	{
		// draw a single pixel
		arduboy.drawPixel(x, y, 1);
	}
	else if(form == PARAM_FORM_REG_REG_NUM || form == PARAM_FORM_REG_REG_REG)
	{
		// draw three pixels
		arduboy.drawPixel(x, y, 1);
		arduboy.drawPixel(x+2, y, 1);
		arduboy.drawPixel(x+4, y, 1);
	}
	else if(form == PARAM_FORM_BUTTONMAP)
	{
		// draw the relevant pixels
		arduboy.drawFastHLine(x, y, 5, 1);
	}
}


void drawOpcodeAndParam(unsigned char x, unsigned char y, unsigned char opcode, unsigned char param)
{
	unsigned char form = getOpcodeParamForm(opcode);
	
	drawOpcode(x, y, opcode);
	
	drawParam(x+OPCODE_WIDTH+PARAM_SPACING, y, param, form);
}

void drawCodeLines(unsigned char start)
{
	unsigned char line;
	
	unsigned char opcode;
	unsigned char param;
	unsigned char index;
	unsigned char verticalOffset = 0;
	unsigned char newStart = start;
	
	if(newStart == 255)
	{
		newStart = 0;
		verticalOffset = 1;
	}
	
	for(line = 0; line < 8-verticalOffset; line++)
	{
		index = line*2 + newStart*2;
		if((line == 7) && (start == PROGRAM_CODE_LENGTH/2 - 7)) break;
		
		opcode = initCode[index];
		param = initCode[index + 1];
		drawCodeLine(0, verticalOffset*8 + offsetY + line*8 + 1, 2*(line+newStart), opcode, param);
	}
}


unsigned char elementCount(unsigned char line)
{
	unsigned char index = line*2;
	unsigned char opcode = initCode[index];
	unsigned char param = initCode[index+1];
	unsigned char form = getOpcodeParamForm(opcode);
	
	return opcode_param_counts[form];
}

void drawCursor()
{
	unsigned char verticalOffset = 0; //(scrollY == 255) ? 8 : 0;
	unsigned char screenY = verticalOffset + offsetY + 8*(cursorY - scrollY);
	unsigned char screenHeight = 8;
	unsigned char screenX;
	unsigned char screenWidth;
	
	if(cursorX == 0)
	{
		screenX = BREAKPOINT_WIDTH;
		screenWidth = OPCODE_WIDTH + 1;
	}
	else
	{
		screenWidth = REGISTER_WIDTH;
		screenX = BREAKPOINT_WIDTH + OPCODE_WIDTH + PARAM_SPACING + (PARAM_SPACING + REGISTER_WIDTH)*(cursorX-1);
	}
	
	if(A_DOWN)
	{
		arduboy.drawRect(screenX + OPCODE_START - 2, screenY-1, screenWidth + 3, screenHeight+2, 1);
	}
	else
	{
		arduboy.invertRect(screenX + OPCODE_START - 1, screenY, screenWidth + 1, screenHeight);
	}
}

#define TONE_EDITOR_HORIZONTAL 880
#define TONE_EDITOR_VERTICAL 440

#define TONE_EDITOR_OPCODE 440
#define TONE_EDITOR_PARAM 880

#define TONE_EDITOR_VALUEUP 1200
#define TONE_EDITOR_VALUEDOWN 1000
#define TONE_EDITOR_BREAKON 660
#define TONE_EDITOR_BREAKOFF 550

void moveCursor(char dx, char dy)
{
	unsigned char elements;
	if(dx < 0)
	{
		if(cursorX > 0)
		{
			cursorX--;
			if(cursorX == 0)
				arduboy.tunes.tone(TONE_EDITOR_OPCODE, 10);
			else
				arduboy.tunes.tone(TONE_EDITOR_PARAM, 10);
				
		}
		else
		{
			if(!lineFlags[cursorY])
			{
				lineFlags[cursorY] = 1;
				arduboy.tunes.tone(TONE_EDITOR_BREAKON, 10);
			}
			else
			{
				lineFlags[cursorY] = 0;
				arduboy.tunes.tone(TONE_EDITOR_BREAKOFF, 10);
			}
		}
	}
	else if(dx > 0 && cursorX < elementCount(cursorY))
	{
		cursorX++;
		arduboy.tunes.tone(TONE_EDITOR_PARAM, 10);
	}
	
	if(dy < 0 && cursorY > 0)
	{
		cursorY--;
		elements = elementCount(cursorY);
		if(cursorX > elements) cursorX = elements;
		if(cursorX == 0)
			arduboy.tunes.tone(TONE_EDITOR_OPCODE, 10);
		else
			arduboy.tunes.tone(TONE_EDITOR_PARAM, 10);
	}
	else if(dy > 0 && cursorY < (PROGRAM_CODE_LENGTH/2 - 1))
	{
		cursorY++;
		elements = elementCount(cursorY);
		if(cursorX > elements) cursorX = elements;
		if(cursorX == 0)
			arduboy.tunes.tone(TONE_EDITOR_OPCODE, 10);
		else
			arduboy.tunes.tone(TONE_EDITOR_PARAM, 10);
	}
	
	if((cursorY+1 > scrollY+1 + 6) || (scrollY == 255 && cursorY >= 6))
	{
		scrollY++;
	}
	else if(cursorY+1 < scrollY+1 + 1)
	{
		if(scrollY != 255)
			scrollY--;
	}
}

void activateCursor()
{
	unsigned char index = cursorY*2;
	unsigned char opcode = initCode[index];
	unsigned char param = initCode[index+1];
	unsigned char form = getOpcodeParamForm(opcode);
	
	if(cursorX > 0)
	{
		activateParam(index+1, cursorX, form);
	}
	else
	{
		activateOpcode(index);
	}
}

#define TONE_EDITOR_OPCODE_UPREG 1000
#define TONE_EDITOR_OPCODE_DOWNREG  800
#define TONE_EDITOR_OPCODE_REG 900
#define TONE_EDITOR_OPCODE_GENERAL 1200


void activateOpcode(unsigned char opcodeIndex)
{
	unsigned char oldVal = initCode[opcodeIndex];
	
	if(LEFT_PRESSED)
	{
		if(modValue(initCode[opcodeIndex], -16, 0, 0x7f))
			arduboy.tunes.tone(TONE_EDITOR_OPCODE_DOWNREG, 10);
	}
	else if(RIGHT_PRESSED)
	{
		if(modValue(initCode[opcodeIndex], 16, 0, 0x7f))
			arduboy.tunes.tone(TONE_EDITOR_OPCODE_UPREG, 10);
	}
	else if(UP_PRESSED || (UP_DOWN && checkCursorDelay()))
	{
		// If among the register opcodes
		if(initCode[opcodeIndex] < 0xf0)
		{
			// If going past the highest in a set
			if(initCode[opcodeIndex]%16 == 15)
				
				// Go to general opcodes
				initCode[opcodeIndex] = 0xf0;
			else
				
				// Go to next register opcode
				initCode[opcodeIndex]++;
		}
		// If among the general opcodes
		else
		{
			// If not on the highest opcode
			if(initCode[opcodeIndex] != 0xff)
				
				// Go to the next opcode
				initCode[opcodeIndex]++;
		}
		
		if(oldVal != initCode[opcodeIndex])
		{
			if(initCode[opcodeIndex] < 0xf0)
			{
				arduboy.tunes.tone(TONE_EDITOR_OPCODE_REG, 10);
			}
			else
			{
				arduboy.tunes.tone(TONE_EDITOR_OPCODE_GENERAL, 10);
			}
		}
	}
	else if(DOWN_PRESSED || (DOWN_DOWN && checkCursorDelay()))
	{
		// If among the register opcodes
		if(initCode[opcodeIndex] < 0xf0)
		{
			// Don't go past the lowest in a set
			if(initCode[opcodeIndex]%16 != 0)
				
				// Go to next register opcode
				initCode[opcodeIndex]--;
		}
		// If among the general opcodes
		else
		{
			// If going to the opcode before the beginning of the set
			if(initCode[opcodeIndex] == 0xf0)
				
				// Go to the set of register opcodes
				initCode[opcodeIndex] = 0x0f;
			
			else
				initCode[opcodeIndex]--;
		}
		
		if(oldVal != initCode[opcodeIndex])
		{
			if(initCode[opcodeIndex] < 0xf0)
			{
				arduboy.tunes.tone(TONE_EDITOR_OPCODE_REG, 10);
			}
			else
			{
				arduboy.tunes.tone(TONE_EDITOR_OPCODE_GENERAL, 10);
			}
		}
	}
	
}

void activateParam(unsigned char paramIndex, unsigned char paramElement, unsigned char form)
{
	unsigned char val1, val2, val3;
	
	if(form == PARAM_FORM_NUM || form == PARAM_FORM_ADDRESS)
	{
		// number picker
		if(UP_PRESSED || (UP_DOWN && checkCursorDelay()))
		{
			if(modValue(initCode[paramIndex], 1, 0, 255))
			{
				arduboy.tunes.tone(TONE_EDITOR_VALUEUP, 10);
			}
		}
		else if(DOWN_PRESSED || (DOWN_DOWN && checkCursorDelay()))
		{
			if(modValue(initCode[paramIndex], -1, 0, 255))
			{
				arduboy.tunes.tone(TONE_EDITOR_VALUEDOWN, 10);
			}
		}
		else if(LEFT_PRESSED || (LEFT_DOWN && checkCursorDelay()))
		{
			if(modValue(initCode[paramIndex], -0x10, 0, 255))
			{
				arduboy.tunes.tone(TONE_EDITOR_VALUEDOWN, 10);
			}
		}
		else if(RIGHT_PRESSED || (RIGHT_DOWN && checkCursorDelay()))
		{
			if(modValue(initCode[paramIndex], 0x10, 0, 255))
			{
				arduboy.tunes.tone(TONE_EDITOR_VALUEUP, 10);
			}
		}
	}
	/*
	else if(form == PARAM_FORM_ADDRESS)
	{
		// address AKA NUMBER picker for now
		if(UP_PRESSED || (UP_DOWN && checkCursorDelay()))
		{
			
			if(modValue(initCode[paramIndex], 1, 0, 255))
				arduboy.tunes.tone(TONE_EDITOR_VALUEUP, 10);
		}
		else if(DOWN_PRESSED || (DOWN_DOWN && checkCursorDelay()))
		{
			if(modValue(initCode[paramIndex], -1, 0, 255));
				arduboy.tunes.tone(TONE_EDITOR_VALUEDOWN, 10);
		}
	}
	*/
	else if(form == PARAM_FORM_BUTTONMAP)
	{
		// toggle buttons individually
		if(A_PRESSED)
		{
			arduboy.tunes.tone(TONE_EDITOR_VALUEUP, 10);
			initCode[paramIndex] ^= (1<<(8-paramElement));
		}
	}
	else if(form == PARAM_FORM_REG)
	{
		// register picker
		if(UP_PRESSED || (UP_DOWN && checkCursorDelay()))
		{
			if(modValue(initCode[paramIndex], 1, 0, 7))
				arduboy.tunes.tone(TONE_EDITOR_VALUEUP, 10);
		}
		else if(DOWN_PRESSED || (DOWN_DOWN && checkCursorDelay()))
		{
			if(modValue(initCode[paramIndex], -1, 0, 7))
				arduboy.tunes.tone(TONE_EDITOR_VALUEDOWN, 10);
		}
	}
	else if(form == PARAM_FORM_REG_REG_NUM || form == PARAM_FORM_REG_REG_REG)
	{
		val1 = (initCode[paramIndex] & 0b00000111);
		val2 = (initCode[paramIndex] & 0b00111000)>>3;
		val3 = (initCode[paramIndex] & 0b11000000)>>6;
		
		// pick a register or number
		if(UP_PRESSED || (UP_DOWN && checkCursorDelay()))
		{
			if(paramElement == 1)
			{
				if(modValue(val1, 1, 0, 7))
					arduboy.tunes.tone(TONE_EDITOR_VALUEUP, 10);
			}
			else if(paramElement == 2)
			{
				if(modValue(val2, 1, 0, 7))
					arduboy.tunes.tone(TONE_EDITOR_VALUEUP, 10);
			}
			else if(paramElement == 3)
			{
				if(modValue(val3, 1, 0, 3))
					arduboy.tunes.tone(TONE_EDITOR_VALUEUP, 10);
			}
		}
		else if(DOWN_PRESSED || (DOWN_DOWN && checkCursorDelay()))
		{
			if(paramElement == 1)
			{
				if(modValue(val1, -1, 0, 7))
					arduboy.tunes.tone(TONE_EDITOR_VALUEDOWN, 10);
			}
			else if(paramElement == 2)
			{
				if(modValue(val2, -1, 0, 7))
					arduboy.tunes.tone(TONE_EDITOR_VALUEDOWN, 10);
			}
			else if(paramElement == 3)
			{
				if(modValue(val3, -1, 0, 3))
					arduboy.tunes.tone(TONE_EDITOR_VALUEDOWN, 10);
			}
		}
		
		initCode[paramIndex] = val1 | (val2<<3) | (val3<<6);
	}
}

//#define MENU_BAR_ITEMS 4
#define MENU_BAR_ITEMS 3

unsigned char menuBarAnchors[] = {
	//3, 15, 30, 47
	3, 15, 32
};
unsigned char menuBarWidths[] = {
	9, 17, 15
	//9, 15, 17, 15
};

struct PullDown {
	unsigned char items;
	unsigned char w;
	unsigned char h;
	const unsigned char* img;
};

PullDown pulldowns[MENU_BAR_ITEMS] = {
	//{4, 61, 27, gfx_iconmenu},
	{1, 53, 6, gfx_iconmenu},
	//{7, 39, 48, gfx_filemenu},
	{4, 68, 27, gfx_editmenu},
	{4, 65, 27, gfx_runmenu},
};


void drawPulldownSelection(unsigned char x, unsigned char y, unsigned char id, unsigned char cursorPos)
{
	arduboy.fillRect(x+1, 1+y+7*(cursorPos-1), pulldowns[id].w, 7, 2);
}

void drawPulldown(unsigned char x, unsigned char y, unsigned char id, unsigned char cursorPos)
{
	PullDown& pd = pulldowns[id];
	
	arduboy.fillRect(x, y, pd.w+2, pd.h+4, 0);
	arduboy.drawFastHLine(x+1, y+pd.h+1, pd.w, 1);
	arduboy.drawFastHLine(x+1, y+pd.h+2, pd.w, 1);
	arduboy.drawBitmap(x+1, y+1, pd.img, pd.w, pd.h, 1);
	drawPulldownSelection(x, y, id, cursorPos);
}

unsigned char menuBarCursorX = 1;
unsigned char menuBarCursorY = 0;

void moveMenuBarCursor(char dx, char dy)
{
	unsigned char ox = menuBarAnchors[menuBarCursorX];
	
	if(dx < 0)
	{
		arduboy.tunes.tone(TONE_MENUBAR_CURSOR, 10);
		menuBarCursorX--;
		if(menuBarCursorX >= MENU_BAR_ITEMS) menuBarCursorX = MENU_BAR_ITEMS-1;
		if(menuBarCursorY >= pulldowns[menuBarCursorX].items + 1)
			menuBarCursorY = pulldowns[menuBarCursorX].items;
	}
	else if(dx > 0)
	{
		arduboy.tunes.tone(TONE_MENUBAR_CURSOR, 10);
		menuBarCursorX++;
		if(menuBarCursorX >= MENU_BAR_ITEMS) menuBarCursorX = 0;
		if(menuBarCursorY >= pulldowns[menuBarCursorX].items + 1)
			menuBarCursorY = pulldowns[menuBarCursorX].items;
	}
	
	if(dy < 0)
	{
		arduboy.tunes.tone(TONE_MENUBAR_CURSOR, 10);
		drawPulldownSelection(ox, 8, menuBarCursorX, menuBarCursorY);
		menuBarCursorY--;
		if(menuBarCursorY >= pulldowns[menuBarCursorX].items + 1)
			menuBarCursorY = pulldowns[menuBarCursorX].items;
		drawPulldownSelection(ox, 8, menuBarCursorX, menuBarCursorY);
	}
	else if(dy > 0)
	{
		arduboy.tunes.tone(TONE_MENUBAR_CURSOR, 10);
		drawPulldownSelection(ox, 8, menuBarCursorX, menuBarCursorY);
		menuBarCursorY++;
		if(menuBarCursorY >= pulldowns[menuBarCursorX].items + 1)
			menuBarCursorY = 0;
		drawPulldownSelection(ox, 8, menuBarCursorX, menuBarCursorY);
	}
}

void showAboutMenu()
{
	arduboy.tunes.tone(TONE_MENUBAR_BEEP, 10);
		
	arduboy.fillRect(31, 12, 62, 46, 0);
	arduboy.drawBitmap(31, 12, gfx_aboutdialog, 62, 46, 1);
	arduboy.display();
	
	updateInput();
	
	while(true)
	{		
		if(!arduboy.nextFrame()) continue;
		
		updateInput();
		
		if(B_PRESSED || A_PRESSED)
			return;
	}
}

void activateMenuBar()
{
	// Icon Menu
	if(menuBarCursorX == MENU_ICON)
	{
		// About
		if(menuBarCursorY == 1)
		{
			showAboutMenu();
		}
		
		// Calculator
		else if(menuBarCursorY == 3)
		{
			
		}
		
		// Control Panel
		else if(menuBarCursorY == 4)
		{
			
		}
		
	}
	// File Menu
	else if(menuBarCursorX == MENU_FILE)
	{
		// New
		if(menuBarCursorY == 1)
		{
			
		}
		
		// Open
		else if(menuBarCursorY == 2)
		{
			
		}
		
		// Receive
		else if(menuBarCursorY == 3)
		{
			
		}
		
		// Save
		else if(menuBarCursorY == 5)
		{
			
		}
		
		// Save As
		else if(menuBarCursorY == 6)
		{
			
		}
		
		// Send
		else if(menuBarCursorY == 7)
		{
			
		}
	}
	// Edit Menu
	else if(menuBarCursorX == MENU_EDIT)
	{
		
		// Insert
		if(menuBarCursorY == 1)
		{
			arduboy.tunes.tone(TONE_MENUBAR_BEEP, 10);
			insertOperation(false);
		}
		
		// Insert and update jumps
		else if(menuBarCursorY == 2)
		{
			arduboy.tunes.tone(TONE_MENUBAR_BEEP, 10);
			insertOperation(true);
		}
		
		// Delete
		else if(menuBarCursorY == 3)
		{
			arduboy.tunes.tone(TONE_MENUBAR_BEEP, 10);
			deleteOperation(false);
		}
		
		// Delete and updage jumps
		else if(menuBarCursorY == 4)
		{
			arduboy.tunes.tone(TONE_MENUBAR_BEEP, 10);
			deleteOperation(true);
		}
	}
	// Run Menu
	else if(menuBarCursorX == MENU_RUN)
	{
		// Save 'n' Run
		if(menuBarCursorY == 1)
		{
			if(showRunProgramDialog())
			{
				vmReset(&vms, true);
				vmRun(&vms);
			}
		}
		
		// Run
		else if(menuBarCursorY == 2)
		{
			vmReset(&vms, true);
			vmRun(&vms);
		}
		
		// Run W/O breakpoints
		else if(menuBarCursorY == 3)
		{
			vmReset(&vms, false);
			vmRun(&vms);
		}
		
		// Resume
		else if(menuBarCursorY == 4)
		{
			vmRun(&vms);
		}
	}
}

void drawMenuBar()
{
	drawEditor();
	unsigned char ox;
			
	ox = menuBarAnchors[menuBarCursorX];
	
	arduboy.fillRect(0, 0, 128, 8, 0);
	arduboy.drawBitmap(0, 0, gfx_menubar, 128, 8, 1);
	arduboy.invertRect(ox, 0, menuBarWidths[menuBarCursorX], 8);
	arduboy.drawFastHLine(0, 8, WIDTH, 0);
}


void showMenuBar()
{
	if(cursorY == scrollY)
		offsetY = 8;
	
	unsigned char repeatTimes;
	bool redraw = true;
	
	bool menuBlinkEnabled = true;

	arduboy.tunes.tone(TONE_MENUBAR_SHOW, 10);
	
	while(true)
	{
		if(!arduboy.nextFrame()) continue;
		
		arduboy.clear();
	
		if(redraw)
		{
			drawMenuBar();
	
			if(menuBarCursorY > 0)
				drawPulldown(menuBarAnchors[menuBarCursorX], 8, menuBarCursorX, menuBarCursorY);
		}
		
		arduboy.display();
		
		updateInput();
		
		if(LEFT_PRESSED)
		{
			moveMenuBarCursor(-1, 0);
			redraw = true;
		}
		else if(RIGHT_PRESSED)
		{
			moveMenuBarCursor(1, 0);
			redraw = true;
		}
		else if(UP_PRESSED)
		{
			moveMenuBarCursor(0, -1);
			redraw = true;
		}
		else if(DOWN_PRESSED)
		{
			moveMenuBarCursor(0, 1);
			redraw = true;
		}
		
		
		if((menuReleaseActivate && B_RELEASED) || (!menuReleaseActivate && A_PRESSED))
		{
			if(menuBarCursorY > 0)
			{
				//if(menuBlinkEnabled)
				if(menuBarCursorX != MENU_EDIT)
				{
					for(repeatTimes = 8; repeatTimes > 0; repeatTimes--)
					{
						drawPulldownSelection(menuBarAnchors[menuBarCursorX], 8, menuBarCursorX, menuBarCursorY);
						arduboy.display();
						arduboy.tunes.tone(TONE_MENUBAR_FLIP, 10);
						delay(menuBlinkDelay);
					}
				}
			}
			
			arduboy.clear();
			drawMenuBar();
			arduboy.display();
			
			activateMenuBar();
			break;
		}
		else if((menuReleaseActivate && A_PRESSED) || (!menuReleaseActivate && B_PRESSED))
		{
			break;		
		}
	}
	
	offsetY = 0;
}

void drawEditor()
{
	drawCodeLines(scrollY);
	drawScrollbar();
	drawCursor();
}

void showEditor()
{
	bool redraw = true;
		
	while(true)
	{			
		if(!arduboy.nextFrame()) return;
		
		updateInput();
		
		updateCursorDelay();
		
		if(A_DOWN)
		{
			activateCursor();
			redraw = true;
		}
		else if((UP_PRESSED) || (UP_DOWN && checkCursorDelay()))
		{
			moveCursor(0, -1);
			redraw = true;
		}
		else if((DOWN_PRESSED) || (DOWN_DOWN && checkCursorDelay()))
		{
			moveCursor(0, 11);
			redraw = true;
		}
		else if(LEFT_PRESSED)
		{
			moveCursor(-1, 0);
			redraw = true;
		}
		else if(RIGHT_PRESSED)
		{
			moveCursor(1, 0);
			redraw = true;
		}

		if(redraw)
		{
			arduboy.clear();
			drawEditor();
			
			arduboy.display();
		}
		
		redraw = false;
		
		if(B_PRESSED)
		{
			showMenuBar();
			redraw = true;
		}
	}
}

void insertOperation(bool updateJumps)
{
	unsigned char index = cursorY * 2;
	unsigned char lineIndex;
	unsigned char jumpsModifiedStart = index;
	
	// Push down the lines
	for(lineIndex = PROGRAM_CODE_LENGTH-2; lineIndex > index; lineIndex -= 2)
	{
		initCode[lineIndex] = initCode[lineIndex-2];
		initCode[lineIndex+1] = initCode[lineIndex-1];
	}
	
	initCode[lineIndex] = 0xf0;
	initCode[lineIndex+1] = 0x00;
	
	// update the jumps
	if(updateJumps)
	{
		for(lineIndex = 0; lineIndex < PROGRAM_CODE_LENGTH-2; lineIndex += 2)
		{
			if((initCode[lineIndex] == 0xf8) && (initCode[lineIndex+1] > jumpsModifiedStart))
			{
				initCode[lineIndex+1] += 2;
			}
		}
	}
}

void deleteOperation(bool updateJumps)
{
	unsigned char index = cursorY * 2;
	unsigned char lineIndex;
	unsigned char jumpsModifiedStart = index;
	
	for(lineIndex = index; lineIndex < PROGRAM_CODE_LENGTH-2; lineIndex += 2)
	{
		initCode[lineIndex] = initCode[lineIndex+2];
		initCode[lineIndex+1] = initCode[lineIndex+3];
	}
	
	initCode[lineIndex] = 0xf0;
	initCode[lineIndex+1] = 0x00;
	
	// update the jumps
	if(updateJumps)
	{
		for(lineIndex = 0; lineIndex < PROGRAM_CODE_LENGTH-2; lineIndex += 2)
		{
			if((initCode[lineIndex] == 0xf8) && (initCode[lineIndex+1] > jumpsModifiedStart))
			{
				initCode[lineIndex+1] -= 2;
			}
		}
	}
	
}
