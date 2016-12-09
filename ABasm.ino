#include "globals.h"
#include "data.h"
#include "vm.h"

#include "save.h"

#include "editor.h"

void setup()
{
	arduboy.begin();
	
	while(!arduboy.nextFrame());
	updateInput();
	
	if(UP_DOWN)
	{
		defaultProgram();
	}
	else if(DOWN_DOWN)
	{
		emptyProgram();
	}
	else
	{
		loadProgram();
	}
}

void loop()
{
	showEditor();
}

