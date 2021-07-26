#include "globals.h"
#include "vm.h"

unsigned char lineFlags[PROGRAM_CODE_LENGTH/2];

unsigned char ram[PROGRAM_RAM_LENGTH];


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
	unsigned char data2;
	unsigned char mode;
	
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


		// Flags:
		// 0: Carry
		// 1: Zero
		// 2: Overflow
		// 3: Negative
		// 4: Same Bit Pattern


		// Future: consider more regular instructions, using 4 bytes instead of 2.
		// No need:
		// TYA, TXS??
		// TX
		
		// Redundant 6502 Instructions
		// TYA, TXA, TAY, TAX, TAY, TAX, STX, STA, STY
		// LDA, LDX, LDY, CPX, CPY
		// DEX, DEY, INX, INY

		// N/A 6502 Instructions
		// SEI, SED, RTI, CLD, CLI, BRK

		// Unsure math instructions
		// CMP                      | sets the registers to nice values
		// BIT                      | non-destructive bitwise compare

		// cmp r0, r1

		// 6502 Math
		// ADC, SBC, CLC, SEC       | (r += a), (r -= a), (carry = 0), (carry = 1)
		// LSR, ORA, ROL, ROR, ASL  | (r >>= a), (r |= a), (r rotl= a), (r rotr= a), (r <<= a)
		// TSX, TXS, PHA, PLA       | (sp = r), (r = sp), (push r), (pop r)
		// INC, DEC, EOR, AND       | (++r), (--r), (r ^= a), (r &= a)


		// add: Format 2
		// addi: Format 1
		// 


		// 6502 Control Flow
		// RTS, JSR, NOP, JMP       | (return), (gosub), (noop), (goto)
		// PHP, PLP                 | (php), (plp)
		// BVS, BPL, BNE            | SkipIfOverflow, SkipIfPositive, SkipIfNotEqual
		// BMI, BEQ, BCS, BCC       | SkipIfNegative, SkipIfEqual, SkipIfCarry, SkipIfNotCarry

		// 1. Register-immediate opcodes.
		// First Byte: 0rrrcccc
		// 0 = Zero
		// r = register
		// c = opcode

		// ABasmV2
		// s: store.

		
		// Format 1: register and absolute.
		// r = target register
		// C = opcode
		// a = absolute vallue
		// Byte 0: 0rrrCCCC
		// Byte 1: aaaaaaaa

		// Format 2: two registers
		// r = target register
		// C = opcode
		// x = subcode
		// a = register 2
		// Byte 0: 0rrrCCCC
		// Byte 1: xxxxxaaa

		// Format 3: three registers
		// r = target register
		// C = opcode
		// x = subcode
		// a = register 2
		// b = register 3
		// Byte 0: 0rrrCCCC
		// Byte 1: xxbbbaaa

		// Format 4: everything else
		// Byte 0: 1???????
		// Byte 1: ????????

		// Format 5: absolute
		// Byte 0: 1CCCCCCC
		// Byte 1: aaaaaaaa
		// C = opcode
		// a = absolute value



		// Sketchpad
		// li r0 1
		// l r1, r0 zero


		// Segments.
		// CurrentCodeSegment
		// CurrentStackSegment
		// CurrentDataSegment

		// All memory is mutable.
		// Multiple Segments can point to same memory page.
		// Opcode for changing memory pages.

		// Push processor state is important. If we want to
		// do a gosub to another memory page, we should push the processor
		// state, then change pages.

		// push pc
		// push current page
		// push destination page
		// 

		// Memory multiplexer.
		// Option 1: use the "standard multiplexer"
		// Option 2: Use an external multiplexer circuit.


		//COMMANDLIST
		// 0h, rrr: set immediate
		// 1h, rrr: add immediate (6502: ADC)
		// 2h, rrr: sub immediate
		// 3h, rrr: mul immediate
		// 4h, rrr: div immediate
		// 5h, rrr: mod immediate
		// 6h, rrr: skip= immediate
		// 7h, rrr: skip!= immediate
		// 8h, rrr: skip< immediate
		// 9h, rrr: skip> immediate
		// ah, rrr: load absolute
		// bh, rrr: store absolute
		// ch, rrr: register load
		// dh, rrr: register store
		// eh, rrr: register-register control flow
		// fh, rrr: register-register math



		// 2. Register load.
		// Second Byte: ccaaabbb
		// cc
		// 00: load r at b
		// 01: load r at *b
		// 10: load r at b + a
		// 11: load r at *b + a

		// 3. Register store.
		// Second Byte: ccaaabbb
		// cc
		// 00: store r at b
		// 01: store r at *b
		// 10: store r at b + a
		// 11: store r at *b + a

		// 4. Register-register control flow.
		// Second Byte: ccccaaaa
		// c = opcode
		// a = register or flag


		// Opcode: RegisterSkip

		// Skip If:
		// 0: (r == a)
		// 1: (r != a)
		// 2: (r > a)
		// 3: (r < a)
		// 4: (r >= a)
		// 5: (r <= a)

		// a is 4 bits:

		// 1000 (compare with carry flag)
		// 1001 (compare with zero flag)
		// 1010 (compare with overflow flag)
		// 1011 (compare with negative flag)
		// 1100 (compare with same bit pattern flag)
		// 1101 (compare with overflow register)
		// 1110 (compare with 0xff)
		// 1111 (compare with 0x00)

		// 5. Register-register math.
		// Second Byte: cccccaaa
		// c = opcode
		// r = register

		// 0: r = a
		// 1: r += a
		// 2: r -= a
		// 3: r >>= a, carry has old low bit
		// 4: r <<= a, carry has old high bit
		// 5: r *= a, overflow register has high byte
		// 6: r /= a
		// 7: r %= a
		// 8: r &= a
		// 9: r |= a
		// A: r ^= a
		// B: r rotate right by a
		// C: r rotate left b a


		// 00h, rrr:
		// 


		// Misc: Missing chip-8 stuff.
		// return
		// goto
		// gosub
		// xor
		// and
		// or
		// rshift
		// lshift


		// Library and I/O routines.
		// random
		// draw sprite
		// delay timer
		// sound timer
		// draw string
		// draw number as string
		// dump registers
		// load registers

		
		if(opcode < 0b10000000) // register opcodes
		{
			reg1 = (opcode & 0b01110000) >> 4;
			opcode &= 0b00001111;
			
			if(opcode == 0x00) // load immediate
			{
				vms.registers[reg1] = initCode[vms.pc++];
			}
			else if(opcode == 0x01) // add immediate
			{
				vms.registers[reg1] += initCode[vms.pc++];
			}
			else if(opcode == 0x02) // subtract immediate
			{
				vms.registers[reg1] -= initCode[vms.pc++];
			}
			else if(opcode == 0x03) // muliply immediate
			{
				vms.registers[reg1] *= vms.registers[initCode[vms.pc++]];
			}
			else if(opcode == 0x04) // divide immediate
			{
				vms.registers[reg1] /= vms.registers[initCode[vms.pc++]];
			}
			else if(opcode == 0x05) // mod immediate
			{
				vms.registers[reg1] %= vms.registers[initCode[vms.pc++]];
			}
			else if(opcode == 0x06) // skip if equal immediate
			{
				if(vms.registers[reg1] == initCode[vms.pc++]) vms.skipInstruction = true;
			}
			else if(opcode == 0x07) // skip if not equal immediate
			{
				if(vms.registers[reg1] != initCode[vms.pc++]) vms.skipInstruction = true;
			}
			else if(opcode == 0x08) // skip if less than immediate
			{
				if(vms.registers[reg1] < initCode[vms.pc++]) vms.skipInstruction = true;
			}
			else if(opcode == 0x09) // skip if greater than immediate
			{
				if(vms.registers[reg1] > initCode[vms.pc++]) vms.skipInstruction = true;
			}

			else if(opcode == 0x0a) // load absolute
			{
				vms.registers[reg1] = ram[initCode[vms.pc++]];
			}
			else if(opcode == 0x0b) // store absolute
			{
				ram[initCode[vms.pc++]] = vms.registers[reg1];
			}

			else if(opcode == 0x0c) // register load
			{
				data2 = vms.pc++;
				reg2 = data2 & 0b111;
				reg3 = (data2 >> 3) & 0b111;
				mode = data2 & 0b11000000;

				// Here's what I want to be able to do:
				// 1. Get a value from an absolute address. Handled earlier.
				// Should I define an implicit register for this? an "A" register? Yikes!
				// load absolute, r0 means *(address + value in r0)

				// Mode 00: r = *a
				// Mode 01: r = **a
				// Mode 10: r = *a + b   // Compares to absolute and offset.
				// Mode 11: r = *a + *b

				if (mode == 0b00000000) // Mode 00
				{
					vms.registers[reg1] = vms.registers[reg2];
				}
				else if(mode == 0b01000000) // Mode 01
				{
					vms.registers[reg1] = ram[vms.registers[reg2]];
				}
				else if(mode == 0b10000000) // Mode 10
				{
					vms.registers[reg1] = ram[vms.registers[reg2] + vms.registers[reg3]];
				}
			}
			else if(opcode == 0x0e) // RegisterSkip
			{
				data2 = vms.pc++;
				reg2 = data2 & 0b1111;
				mode = data2 & 0b11110000;
				x = vms.registers[reg2];

				if (reg2 == 0b1000) x = 0; // Carry flag
				else if (reg2 == 0b1001) x = 0; // Zero flag
				else if (reg2 == 0b1010) x = 0; // Overflow flag
				else if (reg2 == 0b1011) x = 0; // Negative flag
				else if (reg2 == 0b1100) x = 0; // Same Bit Pattern flag
				else if (reg2 == 0b1101) x = 0; // Overflow register
				else if (reg2 == 0b1110) x = 0xff;
				else if (reg2 == 0b1111) x = 0x00;

				if(mode == 0x00) // Skip if r == a
				{
					if(vms.registers[reg1] == x) vms.skipInstruction = true;
				}
				else if(mode == 0x10) // Skip if r != a
				{
					if(vms.registers[reg1] != x) vms.skipInstruction = true;
				}
				else if(mode == 0x20) // Skip if r > a
				{
					if(vms.registers[reg1] > x) vms.skipInstruction = true;
				}
				else if(mode == 0x30) // Skip if r < a
				{
					if(vms.registers[reg1] < x) vms.skipInstruction = true;
				}
				else if(mode == 0x40) // Skip if r >= a
				{
					if(vms.registers[reg1] < x) vms.skipInstruction = true;
				}
				else if(mode == 0x50) // Skip if r <= a
				{
					if(vms.registers[reg1] < x) vms.skipInstruction = true;
				}
			}
			else if(opcode == 0x0f) // RegisterMath
			{
				data2 = vms.pc++;
				reg2 = data2 & 0b1111;
				mode = data2 & 0b11110000;
				x = vms.registers[reg2];

				if (reg2 == 0b1000) x = 0; // Carry flag
				else if (reg2 == 0b1001) x = 0; // Zero flag
				else if (reg2 == 0b1010) x = 0; // Overflow flag
				else if (reg2 == 0b1011) x = 0; // Negative flag
				else if (reg2 == 0b1100) x = 0; // Same Bit Pattern flag
				else if (reg2 == 0b1101) x = 0; // Overflow register
				else if (reg2 == 0b1110) x = 0xff;
				else if (reg2 == 0b1111) x = 0x00;

				if(mode == 0x00) // r = a
				{
					vms.registers[reg1] = x;
				}
				else if(mode == 0x10) // r += a
				{
					vms.registers[reg1] += x;
				}
				else if(mode == 0x20) // r -= a
				{
					vms.registers[reg1] -= x;
				}
				else if(mode == 0x30) // r >>= a
				{
					vms.registers[reg1] >>= x;
				}
				else if(mode == 0x40) // r << a
				{
					vms.registers[reg1] <<= x;
				}
				else if(mode == 0x50) // r *= a
				{
					vms.registers[reg1] *= x;
				}
				else if(mode == 0x60) // r /= a
				{
					vms.registers[reg1] /= x;
				}
				else if(mode == 0x70) // r %= a
				{
					vms.registers[reg1] %= x;
				}
				else if(mode == 0x80) // r &= a
				{
					vms.registers[reg1] &= x;
				}
				else if(mode == 0x90) // r |= a
				{
					vms.registers[reg1] |= x;
				}
				else if(mode == 0xA0) // r ^= a
				{
					vms.registers[reg1] ^= x;
				}
				else if(mode == 0xB0) // r rotate right by a
				{
					vms.registers[reg1] >>= x;
				}
				else if(mode == 0xC0) // r rotate left by a
				{
					vms.registers[reg1] <<= x;
				}
			}

			// else if(opcode == 0x0c) // register load
			// {
			// 	data2 = vms.pc++;
			// 	reg2 = data2 & 0b111;
			// 	reg3 = (data2 >> 3) & 0b111;
			// 	mode = data2 & 0b11000000;

			// 	// Mode 00: r = a (copy a to r)
			// 	// Mode 01: r = *a (copy value at memory location a to r)
			// 	// Mode 10: r = *(a + b) (copy value at memory location a + b to r)
			// 	// Mode 11: reserved.

			// 	if (mode == 0b00000000) // Mode 00
			// 	{
			// 		vms.registers[reg1] = vms.registers[reg2];
			// 	}
			// 	else if(mode == 0b01000000) // Mode 01
			// 	{
			// 		vms.registers[reg1] = ram[vms.registers[reg2]];
			// 	}
			// 	else if(mode == 0b10000000) // Mode 10
			// 	{
			// 		vms.registers[reg1] = ram[vms.registers[reg2] + vms.registers[reg3]];
			// 	}
			// }

			// 4. RegisterSkip
			
			else if(opcode == 0x01) // copy from reg
			{
				vms.registers[reg1] = vms.registers[initCode[vms.pc++]];
			}
			else if(opcode == 0x03) // add with reg
			{
				vms.registers[reg1] += vms.registers[initCode[vms.pc++]];
			}
			else if(opcode == 0x05) // subtract using reg
			{
				vms.registers[reg1] -= vms.registers[initCode[vms.pc++]];
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

			else if (opcode == 0x80) // BranchIfOverflow?? Or does this go in with extended regs?
			{

			}
		}
	}
}