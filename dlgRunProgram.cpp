#include "globals.h"
#include "data.h"
#include "dlgRunProgram.h"
#include "save.h"

bool showRunProgramDialog()
{
	arduboy.fillRect(18-1, 8-1, 96+2, 48+2, 0);
	arduboy.drawBitmap(18, 8, gfx_rundialog, 96, 48, 1);
	arduboy.display();
	
	arduboy.tunes.tone(TONE_MENUBAR_BEEP, 10);
	
	updateInput();
	
	while(true)
	{		
		if(!arduboy.nextFrame()) continue;
		
		if(B_PRESSED)
		{
			arduboy.drawBitmap(24, 38, gfx_invertbutton, 28, 11, 2);
			arduboy.display();
			
			while(true)
			{
				if(!arduboy.nextFrame()) continue;
				
				if(B_RELEASED)
				{
					return false;
				}
				
				updateInput();
			}
		}
		else if(A_PRESSED)
		{
			arduboy.drawBitmap(79, 38, gfx_invertbutton, 28, 11, 2);
			arduboy.display();
			
			while(true)
			{
				if(!arduboy.nextFrame()) continue;
				
				if(A_RELEASED)
				{
					if(!(UP_DOWN || DOWN_DOWN || LEFT_DOWN || RIGHT_DOWN))
						saveProgram();
					return true;
				}
				updateInput();
			}
		}
		
		updateInput();
	}	
}