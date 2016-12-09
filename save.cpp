#include "globals.h"
#include "save.h"

#include "vm.h"

void saveProgram()
{
	short dataIndex;
	unsigned char data;
	for(dataIndex = 0; dataIndex < PROGRAM_CODE_LENGTH; dataIndex++)
	{
		data = EEPROM.read(PROGRAM_EEPROM_START + dataIndex);
		if(data != initCode[dataIndex])
		{
			EEPROM.write(PROGRAM_EEPROM_START + dataIndex, initCode[dataIndex]);
		}
	}
}

void loadProgram()
{
	short dataIndex;
	for(dataIndex = 0; dataIndex < PROGRAM_CODE_LENGTH; dataIndex++)
	{
		initCode[dataIndex] = EEPROM.read(PROGRAM_EEPROM_START + dataIndex);
	}
}

void defaultProgram()
{
	
}

void emptyProgram()
{
	unsigned short dataIndex = 0;
	
	for(dataIndex = 0; dataIndex < PROGRAM_CODE_LENGTH - 1; dataIndex += 2)
	{
		initCode[dataIndex] = 0xf0;
		initCode[dataIndex+1] = 0x00;
	}
}
