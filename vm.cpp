#include "globals.h"
#include "vm.h"

unsigned char lineFlags[PROGRAM_CODE_LENGTH/2];

unsigned char initCode[PROGRAM_CODE_LENGTH] = {
	//// Reset ////
	
	// If b is not pressed, exit
	//0xf6, 0x08, // 00: SKID b
	//0xff, 0x00, // 02: EXIT _
	//0xf0, 0x00, // 04: NOOP _
	
	0xf0, 0x00,
	0xf0, 0x00,
	0xf0, 0x00,
	
	// Initialize game registers
	0x00, 64,   // 06: SIR0 64
	0x10, 32,   // 08: SIR1 32
	0x20, 1,    // 0A: SIR2 1
	0x30, 0,    // 0C: SIR3 0
	
	// Wait for a button press
	//0xf6, 0x04, // 0E: SKID a
	//0xf8, 0x0e, // 10: JUMP 0Eh
	
	0xf0, 0x00,
	0xf0, 0x00,
	
	// Fill screen with black
	0xf1, 0x00, // 12: FSCR 0
	
	//// Game Loop ////
	
	// If up is pressed, jump
	0xf7, 128,  // 14: SKIU u
	0xf8, 0x44, // 16: JUMP 44h
	
	// If down is pressed, jump
	0xf7, 16,   // 18: SKIU d
	0xf8, 0x4e, // 1A: JUMP 4Eh
	
	// If left is pressed, jump
	0xf7, 32,   // 1C: SKIU l
	0xf8, 0x58, // 1E: JUMP 58h
	
	// If right is pressed, jump
	0xf7, 64,   // 20: SKIU r
	0xf8, 0x62, // 22: JUMP 62h
	
	//// Physics Update ////
	
	// Add velocities
	0x03, 0x02, // 24: ADR0 R2
	0x13, 0x03, // 26: ADR1 R3
	
	
	// (new code)
	// Check collision
	0x40, 1,    // 28: SIR4 1
	0xf3, 0b00001000, // 2A: GPIX 014
	0x4f, 0x00, // 2C: SIR4 0
	0xf8, 0x6C, // 2E: JUMP 6Ch
	
	0xf0, 0x00, // 30: NOOP _
	0xf0, 0x00, // 32: NOOP _
	0xf0, 0x00, // 34: NOOP _
	0xf0, 0x00, // 36: NOOP _
	0xf0, 0x00, // 38: NOOP _
	0xf0, 0x00, // 3A: NOOP _
	
	
	// (old code)
	// Check Pixel Collision
	//0xf3, 0b00001000, // 28: GPIX 014
	//0x4f, 0x00, // 2A: SIR4 0
	//0xf8, 0x6C, // 2C: JUMP 6Ch
	
	// Check Horizontal Wall Collision
	//0x0a, 0x00, // 2E: SNI0 0
	//0xf8, 0x6C, // 30: JUMP 6Ch
	
	// Check Upper Wall Collision
	//0xf0, 0xf0, //0x1a, 0x00, // 32: SNI1 0
	//0xf0, 0xf0, //0xf8, 0x6C, // 34: JUMP 6Ch
	
	// Check Lower Wall Collision
	//0xf0, 0xf0, //0x40, 64,   // 36: SIR4 64
	//0xf0, 0xf0, //0x2D, 0x04, // 38: SLR2 R4
	//0xf0, 0xf0, //0xf8, 0x6C, // 3A: JUMP 6Ch
	
	//// Drawing ////
	
	// Draw new position
	0xf2, 0b01001000, // 3C: SPIX 011
	0xfd, 0x00, // 3E: DISP _
	0xf5, 0x00, // 40: WAIF _
	
	// Goto game loop
	0xf8, 0x14, // 42: JUMP 14h
	
	
	
	//// Up is Pressed ////
	
	// If left or right are held, goto physics
	0xf7, 0x40, // 44: SKIU lr
	0xf8, 0x24, // 46: JUMP 24h
	
	// Set the velocities
	0x20, 0,    // 48: SIR2 0
	0x30, 255,  // 4A: SIR3 255
	
	// Goto physics
	0xf8, 0x24, // 4C: JUMP 24h
	
	
	
	//// Down is Pressed ////
	
	// If left or right are held, goto physics
	0xf7, 0x40, // 4E: SKIU lr
	0xf8, 0x24, // 50: JUMP 24h
	
	// Set the velocities
	0x20, 0,    // 52: SIR2 0
	0x30, 1,    // 54: SIR3 1
	
	// Goto physics
	0xf8, 0x24, // 56: JUMP 24h
		
		
		
	//// Left is Pressed ////
	
	// If left or right are held, goto physics
	0xf7, 0x90, // 58: SKIU ud
	0xf8, 0x24, // 5A: JUMP 24h
	
	// Set the velocities
	0x20, 255,  // 5C: SIR2 255
	0x30, 0,    // 5E: SIR3 0
	
	// Goto physics
	0xf8, 0x24, // 60: JUMP 24h
		
		
		
	//// Right is Pressed ////
	
	// If left or right are held, goto physics
	0xf7, 0x90, // 62: SKIU ud
	0xf8, 0x24, // 64: JUMP 24h
	
	// Set the velocities
	0x20, 1,    // 66: SIR2 1
	0x30, 0,    // 68: SIR3 0
	
	// Goto physics
	0xf8, 0x24, // 6A: JUMP 24h
	
	
	
	//// Death ////
	
	// Print "Dead"
	0xfc, 0x04, // 6C: PRNT 4
	'D',  'e',  // 6E: 'D'  'e'
	'a',  'd',  // 70: 'a'  'd'
	0xfd, 0x00, // 72: DISP _
	
	// Wait for B Pressed
	0xf6, 0x08, // 74: SKID B
	0xf8, 0x74, // 76: JUMP 74h
	0xf8, 0x00, // 78: JUMP 00h
};


unsigned char vmReset(VMState* vmPtr, bool breakpointsEnabled)
{
	unsigned char index;
	
	VMState& vms = *vmPtr;
	
	for(index = 0; index < VM_NUM_REGISTERS; index++)
	{
		vms.registers[index] = 0;
	}
	
	vms.pc = 0;
	vms.skipInstruction = false;
	vms.breakpointsEnabled = breakpointsEnabled;
}

unsigned char vmRun(VMState* vmPtr)
{
	unsigned char reg1, reg2, reg3;
	unsigned char iterator;
	
	unsigned char opcode;
	unsigned char x, y;
	
	bool justResumed = true;
	
	VMState& vms = *vmPtr;
		
	while(!arduboy.nextFrame());
	
	while(true)
	{
		updateInput();
		if(LEFT_DOWN && RIGHT_DOWN && B_DOWN)
			return VMRUN_RETURN_KILL;
		
		if(vms.pc >= PROGRAM_CODE_LENGTH)
			return VMRUN_RETURN_ERROR;
		
		if(!justResumed && lineFlags[vms.pc/2] == 1)
			return VMRUN_RETURN_BREAK;
		
		justResumed = false;
			
		opcode = initCode[vms.pc++];
		
		/*
		arduboy.setCursor(0, 64-8);
		arduboy.print("[");
		arduboy.print(pc-1);
;		arduboy.print("], ");
		arduboy.print(opcode);
		arduboy.print(", ");
		arduboy.print(initCode[pc]);
		arduboy.print("   ");
		arduboy.display();
		*/
		
		//pdelay(25);
		
		if(vms.skipInstruction)
		{
			vms.pc++;
			vms.skipInstruction = false;
			continue;
		}
		
		
		if(opcode < 0xF0) // register opcodes
		{
			reg1 = (opcode & 0b01110000) >> 4;
			opcode &= 0b00001111;
			
			if(opcode == 0x00) // set immediate
			{
				vms.registers[reg1] = initCode[vms.pc++];
			}
			else if(opcode == 0x01) // copy from reg
			{
				vms.registers[reg1] = vms.registers[initCode[vms.pc++]];
			}
			else if(opcode == 0x02) // add immediate
			{
				vms.registers[reg1] += initCode[vms.pc++];
			}
			else if(opcode == 0x03) // add with reg
			{
				vms.registers[reg1] += vms.registers[initCode[vms.pc++]];
			}
			else if(opcode == 0x04) // subtract immediate
			{
				vms.registers[reg1] -= initCode[vms.pc++];
			}
			else if(opcode == 0x05) // subtract using reg
			{
				vms.registers[reg1] -= vms.registers[initCode[vms.pc++]];
			}
			else if(opcode == 0x06) // muliply immediate
			{
				vms.registers[reg1] *= vms.registers[initCode[vms.pc++]];
			}
			else if(opcode == 0x07) // multiply using reg
			{
				vms.registers[reg1] *= vms.registers[initCode[vms.pc++]];
			}
			else if(opcode == 0x08) // divide using reg
			{
				vms.registers[reg1] /= vms.registers[initCode[vms.pc++]];
			}
			else if(opcode == 0x09) // mod using reg
			{
				vms.registers[reg1] %= vms.registers[initCode[vms.pc++]];
			}
			else if(opcode == 0x0a) // skip instruction if reg is not equal to val
			{
				if(vms.registers[reg1] != initCode[vms.pc++]) vms.skipInstruction = true;
			}
			else if(opcode == 0x0b) // skip instruction if reg is not equal to reg
			{
				if(vms.registers[reg1] != vms.registers[initCode[vms.pc++]]) vms.skipInstruction = true;
			}
			else if(opcode == 0x0c) // skip instruction if reg is equal to reg
			{
				if(vms.registers[reg1] == vms.registers[initCode[vms.pc++]]) vms.skipInstruction = true;
			}
			else if(opcode == 0x0d) // skip instruction if reg is less than reg
			{
				if(vms.registers[reg1] < vms.registers[initCode[vms.pc++]]) vms.skipInstruction = true;
			}
			else if(opcode == 0x0e) // skip instruction if reg is greater than reg
			{
				if(vms.registers[reg1] > vms.registers[initCode[vms.pc++]]) vms.skipInstruction = true;
			}
			else if(opcode == 0x0f) // skip instruction if reg is equal to val
			{
				if(vms.registers[reg1] == initCode[vms.pc++]) vms.skipInstruction = true;
			}
		}
		else // general opcodes
		{
			if(opcode == 0xf0) // no operation
			{
				vms.pc++;
			}
			else if(opcode == 0xf1) // fill screen with color
			{
				arduboy.fillScreen(initCode[vms.pc++]);
			}
			else if(opcode == 0xf2) // set pixel on screen (lsb: rx, ry, color)
			{
				opcode = initCode[vms.pc++];
				reg1 = opcode & 0b00000111;
				reg2 = (opcode & 0b00111000) >> 3;
				reg3 = (opcode & 0b11000000) >> 6;
				
				arduboy.drawPixel(vms.registers[reg1], vms.registers[reg2], reg3);
			}
			else if(opcode == 0xf3) // get pixel on screen (lsb: rx, ry, rdest)
			{                       // does not modify rdest if coords are offscreen
				opcode = initCode[vms.pc++];
				reg1 = opcode & 0b00000111;
				reg2 = (opcode & 0b00111000) >> 3;
				reg3 = ((opcode & 0b11000000) >> 6) + 4;
				
				x = vms.registers[reg1];
				y = vms.registers[reg2];
				
				if(x < WIDTH && y < HEIGHT)
					vms.registers[reg3] = arduboy.getPixel(x, y);
			}
			else if(opcode == 0xf4) // play a tone (lsb: rtoneLo, rtoneHi, rDelay)
			{
				opcode = initCode[vms.pc++];
				reg1 = opcode & 0b00000111;
				reg2 = (opcode & 0b00111000) >> 3;
				reg3 = ((opcode & 0b11000000) >> 6) + 4;
				
				arduboy.tunes.tone(((short)vms.registers[reg2])*16 + vms.registers[reg1], vms.registers[reg3]);
			}
			else if(opcode == 0xf5) // wait for the next frame
			{
				while(!arduboy.nextFrame());
				vms.pc++;
			}
			else if(opcode == 0xf6) // skip if desired buttons are down
			{
				reg1 = initCode[vms.pc++];
				if(arduboy.pressed(reg1)) vms.skipInstruction = true;
			}
			else if(opcode == 0xf7) // skip if desired buttons are up
			{
				reg1 = initCode[vms.pc++];
				if(arduboy.notPressed(reg1)) vms.skipInstruction = true;
			}
			else if(opcode == 0xf8) // jump pc to address in eeprom
			{
				opcode = initCode[vms.pc++];
				vms.pc = opcode;
			}
			else if(opcode == 0xf9) // jump pc to address in eeprom indirect reg
			{
				reg1 = initCode[vms.pc++];
				vms.pc = vms.registers[reg1];
			}
			else if(opcode == 0xfa) // restore register values from eeprom address
			{
				// todo
				vms.pc++;
			}
			else if(opcode == 0xfb) // dump register values to eeprom address
			{
				// todo
				vms.pc++;
			}
			else if(opcode == 0xfc) // print a number of following characters
			{
				reg1 = initCode[vms.pc++];
				arduboy.setCursor(0, 0);
				for(iterator = 0; iterator < reg1; iterator++)
				{
					arduboy.print((char)initCode[vms.pc++]);
				}
			}
			else if(opcode == 0xfd) // display buffer to screen
			{
				arduboy.display();
				vms.pc++;
			}
			else if(opcode == 0xfe) // reserved
			{
				vms.pc++;
			}
			else if(opcode == 0xff) // exit init routine
			{
				vms.pc++;
				return VMRUN_RETURN_EXIT;
			}
		}
	}
}