#ifndef _VM_H
#define _VM_H

#define VM_NUM_REGISTERS 8

#define PROGRAM_CODE_LENGTH 256
#define PROGRAM_RAM_LENGTH 256

#define VMRUN_RETURN_EXIT 0
#define VMRUN_RETURN_BREAK 1
#define VMRUN_RETURN_KILL 2
#define VMRUN_RETURN_ERROR 3

#define VM_FLAG_CARRY 0b1000    // Unsigned result is too large
#define VM_FLAG_ZERO 0b1001     // Result is zero
#define VM_FLAG_OVERFLOW 0b1010 // Signed result is too large
#define VM_FLAG_NEGATIVE 0b1011 // Result is negative
#define VM_FLAG_SAMEBITS 0b1100 // Result exactly matched a bit pattern (maybe remove this one)

struct VMState {
	unsigned char registers[8];
	unsigned char pc;
	bool skipInstruction;
	bool breakpointsEnabled;
	unsigned char flags;
	unsigned char overflow;
};

extern unsigned char initCode[PROGRAM_CODE_LENGTH];
extern unsigned char lineFlags[PROGRAM_CODE_LENGTH/2];
unsigned char vmRun(VMState* vmPtr);
unsigned char vmReset(VMState* vmPtr, bool breakpointsEnabled);


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

		// 1000 (compare with carry flag)               VM_FLAG_CARRY
		// 1001 (compare with zero flag)                VM_FLAG_ZERO
		// 1010 (compare with overflow flag)            VM_FLAG_OVERFLOW
		// 1011 (compare with negative flag)            VM_FLAG_NEGATIVE
		// 1100 (compare with same bit pattern flag)    VM_FLAG_SAMEBITS
		// 1101 (compare with overflow register)        vms.overflow
		// 1110 (compare with 0xff)                     0xff
		// 1111 (compare with 0x00)                     0x00

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

		

#endif


// Original startup program...


	// //// Reset ////
	
	// // If b is not pressed, exit
	// //0xf6, 0x08, // 00: SKID b
	// //0xff, 0x00, // 02: EXIT _
	// //0xf0, 0x00, // 04: NOOP _
	
	// 0xf0, 0x00,
	// 0xf0, 0x00,
	// 0xf0, 0x00,
	
	// // Initialize game registers
	// 0x00, 64,   // 06: SIR0 64
	// 0x10, 32,   // 08: SIR1 32
	// 0x20, 1,    // 0A: SIR2 1
	// 0x30, 0,    // 0C: SIR3 0
	
	// // Wait for a button press
	// //0xf6, 0x04, // 0E: SKID a
	// //0xf8, 0x0e, // 10: JUMP 0Eh
	
	// 0xf0, 0x00,
	// 0xf0, 0x00,
	
	// // Fill screen with black
	// 0xf1, 0x00, // 12: FSCR 0
	
	// //// Game Loop ////
	
	// // If up is pressed, jump
	// 0xf7, 128,  // 14: SKIU u
	// 0xf8, 0x44, // 16: JUMP 44h
	
	// // If down is pressed, jump
	// 0xf7, 16,   // 18: SKIU d
	// 0xf8, 0x4e, // 1A: JUMP 4Eh
	
	// // If left is pressed, jump
	// 0xf7, 32,   // 1C: SKIU l
	// 0xf8, 0x58, // 1E: JUMP 58h
	
	// // If right is pressed, jump
	// 0xf7, 64,   // 20: SKIU r
	// 0xf8, 0x62, // 22: JUMP 62h
	
	// //// Physics Update ////
	
	// // Add velocities
	// 0x03, 0x02, // 24: ADR0 R2
	// 0x13, 0x03, // 26: ADR1 R3
	
	
	// // (new code)
	// // Check collision
	// 0x40, 1,    // 28: SIR4 1
	// 0xf3, 0b00001000, // 2A: GPIX 014
	// 0x4f, 0x00, // 2C: SIR4 0
	// 0xf8, 0x6C, // 2E: JUMP 6Ch
	
	// 0xf0, 0x00, // 30: NOOP _
	// 0xf0, 0x00, // 32: NOOP _
	// 0xf0, 0x00, // 34: NOOP _
	// 0xf0, 0x00, // 36: NOOP _
	// 0xf0, 0x00, // 38: NOOP _
	// 0xf0, 0x00, // 3A: NOOP _
	
	
	// // (old code)
	// // Check Pixel Collision
	// //0xf3, 0b00001000, // 28: GPIX 014
	// //0x4f, 0x00, // 2A: SIR4 0
	// //0xf8, 0x6C, // 2C: JUMP 6Ch
	
	// // Check Horizontal Wall Collision
	// //0x0a, 0x00, // 2E: SNI0 0
	// //0xf8, 0x6C, // 30: JUMP 6Ch
	
	// // Check Upper Wall Collision
	// //0xf0, 0xf0, //0x1a, 0x00, // 32: SNI1 0
	// //0xf0, 0xf0, //0xf8, 0x6C, // 34: JUMP 6Ch
	
	// // Check Lower Wall Collision
	// //0xf0, 0xf0, //0x40, 64,   // 36: SIR4 64
	// //0xf0, 0xf0, //0x2D, 0x04, // 38: SLR2 R4
	// //0xf0, 0xf0, //0xf8, 0x6C, // 3A: JUMP 6Ch
	
	// //// Drawing ////
	
	// // Draw new position
	// 0xf2, 0b01001000, // 3C: SPIX 011
	// 0xfd, 0x00, // 3E: DISP _
	// 0xf5, 0x00, // 40: WAIF _
	
	// // Goto game loop
	// 0xf8, 0x14, // 42: JUMP 14h
	
	
	
	// //// Up is Pressed ////
	
	// // If left or right are held, goto physics
	// 0xf7, 0x40, // 44: SKIU lr
	// 0xf8, 0x24, // 46: JUMP 24h
	
	// // Set the velocities
	// 0x20, 0,    // 48: SIR2 0
	// 0x30, 255,  // 4A: SIR3 255
	
	// // Goto physics
	// 0xf8, 0x24, // 4C: JUMP 24h
	
	
	
	// //// Down is Pressed ////
	
	// // If left or right are held, goto physics
	// 0xf7, 0x40, // 4E: SKIU lr
	// 0xf8, 0x24, // 50: JUMP 24h
	
	// // Set the velocities
	// 0x20, 0,    // 52: SIR2 0
	// 0x30, 1,    // 54: SIR3 1
	
	// // Goto physics
	// 0xf8, 0x24, // 56: JUMP 24h
		
		
		
	// //// Left is Pressed ////
	
	// // If left or right are held, goto physics
	// 0xf7, 0x90, // 58: SKIU ud
	// 0xf8, 0x24, // 5A: JUMP 24h
	
	// // Set the velocities
	// 0x20, 255,  // 5C: SIR2 255
	// 0x30, 0,    // 5E: SIR3 0
	
	// // Goto physics
	// 0xf8, 0x24, // 60: JUMP 24h
		
		
		
	// //// Right is Pressed ////
	
	// // If left or right are held, goto physics
	// 0xf7, 0x90, // 62: SKIU ud
	// 0xf8, 0x24, // 64: JUMP 24h
	
	// // Set the velocities
	// 0x20, 1,    // 66: SIR2 1
	// 0x30, 0,    // 68: SIR3 0
	
	// // Goto physics
	// 0xf8, 0x24, // 6A: JUMP 24h
	
	
	
	// //// Death ////
	
	// // Print "Dead"
	// 0xfc, 0x04, // 6C: PRNT 4
	// 'D',  'e',  // 6E: 'D'  'e'
	// 'a',  'd',  // 70: 'a'  'd'
	// 0xfd, 0x00, // 72: DISP _
	
	// // Wait for B Pressed
	// 0xf6, 0x08, // 74: SKID B
	// 0xf8, 0x74, // 76: JUMP 74h
	// 0xf8, 0x00, // 78: JUMP 00h


			
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