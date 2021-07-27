#include "globals.h"
#include "vm.h"

unsigned char lineFlags[PROGRAM_CODE_LENGTH/2];

unsigned char ram[PROGRAM_RAM_LENGTH];


unsigned char initCode[PROGRAM_CODE_LENGTH];


#define CLEAR_CARRY() (vms.flags &= ^VM_FLAG_CARRY)
#define CLEAR_OVERFLOW() (vms.flags &= ^VM_FLAG_OVERFLOW)
#define CLEAR_ZERO() (vms.flags &= ^VM_FLAG_ZERO)
#define CLEAR_NEGATIVE() (vms.flags &= ^VM_FLAG_NEGATIVE)

#define CHECK_ZERO(x) (vms.flags |= (!(x)) ? VM_FLAG_ZERO : 0)
#define CHECK_OVERFLOW(x) ((vms.flags |= (((x) > 127) && ((x) < 65408))) ? VM_FLAG_OVERFLOW : 0)
#define CHECK_CARRY(x) (vms.flags |= ((x) & 0xff00) ? VM_FLAG_CARRY : 0)
#define CHECK_NEGATIVE(x) (vms.flags |= ((x) & 0b10000000) ? VM_FLAG_NEGATIVE : 0)

#define SET_CARRY_IF(x) (vms.flags |= ((x))) ? VM_FLAG_CARRY : 0)
#define SET_OVERFLOW_IF(x) (vms.flags |= ((x))) ? VM_FLAG_OVERFLOW : 0)

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
	vms.flags = 0;
}

unsigned char vmRun(VMState* vmPtr)
{
	unsigned char reg1, reg2, reg3;
	unsigned char iterator;
	
	unsigned char opcode;
	unsigned char x, y, temp;
	unsigned char data2;
	unsigned char mode;

	unsigned char result;
	unsigned short largerResult;

	
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


		if(opcode < 0b10000000) // register opcodes
		{
			// Extract data from the opcode.
			reg1 = (opcode & 0b01110000) >> 4; // The destination register.
			opcode &= 0b00001111;              // The subopcode.
			result = vms.registers[reg1];      // Hold onto the value of the destination register for later.
			
			// Opcode: loadi /////////////////////////////////////////////////////
			// "Load Immediate"
			//
			// Loads an immediate value into the destination register.
			// Sets the zero flag if result is 0.
			// Sets the negative flag if the MSB of result is 1.
			if(opcode == 0x00) // load immediate
			{
				CLEAR_ZERO();
				CLEAR_NEGATIVE();
				result = initCode[vms.pc++];
				CHECK_ZERO();
				CHECK_NEGATIVE();
			}
			
			// Opcode: addi /////////////////////////////////////////////////////
			// "Add Immediate"
			//
			// Adds an immediate value to the destination register.
			// Sets the zero flag if result is 0.
			// Sets the carry flag if result is greater than 255.
			// Sets the overflow flag if result is less than -128 or greater than +127.
			// Sets the negative flag if the MSB of result is 1.
			// Sets the overflow register to high byte of value.
			else if(opcode == 0x01) // add immediate
			{
				CLEAR_ZERO();
				CLEAR_CARRY();
				CLEAR_OVERFLOW();
				CLEAR_NEGATIVE();
				vms.overflow = 0;
				largerResult = result;
				largerResult += initCode[vms.pc++];
				result = largerResult & 0xff;
				vms.overflow = (largerResult >> 8) & 0xff;
				CHECK_OVERFLOW(largerResult);
				CHECK_CARRY(largerResult);
				CHECK_ZERO(result);
				CHECK_NEGATIVE(result);
			}
			
			// Opcode: subi /////////////////////////////////////////////////////
			// "Subtract Immediate"
			//
			// Subtracts an immediate value from the destination register.
			// Sets the zero flag if result is 0.
			// Sets the carry flag if result is greater than 255.
			// Sets the overflow flag if result is less than -128 or greater than +127.
			// Sets the negative flag if the MSB of result is 1.
			// Sets the overflow register to high byte of value.
			else if(opcode == 0x02) // subtract immediate
			{
				CLEAR_ZERO();
				CLEAR_CARRY();
				CLEAR_OVERFLOW();
				CLEAR_NEGATIVE();
				vms.overflow = 0;
				largerResult = result;
				largerResult -= initCode[vms.pc++];
				result = largerResult & 0xff;
				vms.overflow = (largerResult >> 8) & 0xff;
				CHECK_OVERFLOW(largerResult);
				CHECK_CARRY(largerResult);
				CHECK_ZERO(result);
				CHECK_NEGATIVE(result);
			}

			// Opcode: muli ///////////////////////////////////////////////////
			// "Multiply Immediate"
			//
			// Multiplies an immediate value against the destination register.
			// Sets the zero flag if result is 0.
			// Sets the carry flag if result is greater than 255.
			// Sets the overflow flag if result is less than -128 or greater than +127.
			// Sets the negative flag if the MSB of result is 1.
			// Sets the overflow register to high byte of value.
			else if(opcode == 0x03)
			{
				CLEAR_ZERO();
				CLEAR_CARRY();
				CLEAR_OVERFLOW();
				CLEAR_NEGATIVE();
				vms.overflow = 0;
				largerResult = result;
				largerResult *= vms.registers[initCode[vms.pc++]];
				result = largerResult & 0xff;
				vms.overflow = (largerResult >> 8) & 0xff;
				CHECK_OVERFLOW(largerResult);
				CHECK_CARRY(largerResult);
				CHECK_ZERO(result);
				CHECK_NEGATIVE(result);
			}

			// Opcode: divi ///////////////////////////////////////////////////
			// "Divide Immediate"
			//
			// Divides an immediate value against the destination register.
			// Sets the zero flag if result is 0.
			// Sets the negative flag if the MSB of result is 1.
			else if(opcode == 0x04)
			{
				CLEAR_ZERO();
				CLEAR_NEGATIVE();
				result /= vms.registers[initCode[vms.pc++]];
				CHECK_ZERO(result);
				CHECK_NEGATIVE(result);
			}

			// Opcode: modi ///////////////////////////////////////////////////
			// "Modulo Immediate"
			//
			// Mods an immediate value against the destination register.
			// Sets the zero flag if result is 0.
			// Sets the negative flag if the MSB of result is 1.
			else if(opcode == 0x05)
			{
				CLEAR_ZERO();
				CLEAR_NEGATIVE();
				result %= vms.registers[initCode[vms.pc++]];
				CHECK_ZERO(result);
				CHECK_NEGATIVE(result);
			}

			// Opcode: seqi ///////////////////////////////////////////////////
			// "Skip If Equal Immediate"
			//
			// Skips to the next instruction if destination register has the
			// same value as immediate value.
			else if(opcode == 0x06)
			{
				if(result == initCode[vms.pc++]) vms.skipInstruction = true;
			}
			
			// Opcode: snei ///////////////////////////////////////////////////
			// "Skip If Not Equal Immediate"
			//
			// Skips to the next instruction if destination register has a
			// different value from the immediate value.
			else if(opcode == 0x07)
			{
				if(result != initCode[vms.pc++]) vms.skipInstruction = true;
			}
			
			// Opcode: slti ///////////////////////////////////////////////////
			// "Skip If Less Than Immediate"
			//
			// Skips to the next instruction if destination register has a
			// value less than the immediate value.
			else if(opcode == 0x08)
			{
				if(result < initCode[vms.pc++]) vms.skipInstruction = true;
			}
			
			// Opcode: sgti ///////////////////////////////////////////////////
			// "Skip If Greater Than Immediate"
			//
			// Skips to the next instruction if destination register has a
			// value greater than the immediate value.
			else if(opcode == 0x09)
			{
				if(result > initCode[vms.pc++]) vms.skipInstruction = true;
			}
			
			// Opcode: loada //////////////////////////////////////////////////
			// "Load absolute"
			//
			// Loads a value from an absolute RAM address into the destination
			// register.
			// Sets the zero flag if result is 0.
			// Sets the negative flag if the MSB of result is 1.
			else if(opcode == 0x0a)
			{
				CLEAR_ZERO();
				CLEAR_NEGATIVE();
				result = ram[initCode[vms.pc++]];
				CHECK_ZERO(result);
				CHECK_NEGATIVE(result);
			}

			// Opcode: storea /////////////////////////////////////////////////
			// "Store Absolute"
			//
			// Stores the value in the destination register to an absolute
			// location in ram.
			// Sets the zero flag if result is 0.
			// Sets the negative flag if the MSB of result is 1.
			else if(opcode == 0x0b)
			{
				ram[initCode[vms.pc++]] = result;
			}

			// Opcode: loadr //////////////////////////////////////////////////
			// "Load Register"
			//
			// Loads from RAM to the destination register. Dereference mode
			// is determined in the subcode. Special register values are
			// useable.
			//
			// Dereference Mode 0: Copy register A value to destination
			// register.
			//
			// Dereference Mode 1: Copy value from memory location pointed to
			// by register A to destination register.
			//
			// Dereference Mode 2: Copy value from memory location pointed to
			// by (register A + register B) to destination register.
			//
			// Dereference Mode 3: Reserved.
			else if(opcode == 0x0c) // register load
			{
				data2 = vms.pc++;            // Read the next byte for data.
				reg2 = data2 & 0b111;        // Extract register.
				reg3 = (data2 >> 3) & 0b111; // Extract another register.
				mode = data2 & 0b11000000;   // Extract dereference mode.

				// Dereference Mode 0: Copy register A value to destination
				// register.
				if (mode == 0b00000000) // r = a
				{
					CLEAR_ZERO();
					CLEAR_NEGATIVE();
					result = vms.registers[reg2];
					CHECK_ZERO(result);
					CHECK_NEGATIVE(result);
				}

				// Dereference Mode 1: Copy value from memory location pointed to
				// by register A to destination register.
				else if(mode == 0b01000000) // r = *a
				{
					CLEAR_ZERO();
					CLEAR_NEGATIVE();
					result = ram[vms.registers[reg2]];
					CHECK_ZERO(result);
					CHECK_NEGATIVE(result);
				}

				// Dereference Mode 2: Copy value from memory location pointed to
				// by (register A + register B) to destination register.
				else if(mode == 0b10000000) // r = *(a + b)
				{
					CLEAR_ZERO();
					CLEAR_NEGATIVE();
					result = ram[vms.registers[reg2] + vms.registers[reg3]];
					CHECK_ZERO(result);
					CHECK_NEGATIVE(result);
				}
			}

			// Opcode: skipr //////////////////////////////////////////////////
			// "Skip Register"
			//
			// Skips the next instruction based on comparisons between the
			// destination register and register A.
			//
			// Subcode: eq => Skip if destination register == register A.
			// Subcode: ne => Skip if destination register != register A.
			// Subcode: gt => Skip if destination register > register A.
			// Subcode: lt => Skip if destination register < register A.
			// Subcode: ge => Skip if destination register >= register A.
			// Subcode: le => Skip if destination register <= register A.
			else if(opcode == 0x0e) // RegisterSkip
			{
				// Read the opcode.
				data2 = vms.pc++;           // Read the next byte for data.
				reg2 = data2 & 0b1111;      // Extract register (plus special values).
				mode = data2 & 0b11110000;  // Extract sub opcode.
				x = vms.registers[reg2];

				// Decode reg2 special values.
				if (reg2 == 0b1000)      x = (vms.flags & VM_FLAG_CARRY);    // Carry flag
				else if (reg2 == 0b1001) x = (vms.flags & VM_FLAG_ZERO);     // Zero flag
				else if (reg2 == 0b1010) x = (vms.flags & VM_FLAG_OVERFLOW); // Overflow flag
				else if (reg2 == 0b1011) x = (vms.flags & VM_FLAG_NEGATIVE); // Negative flag
				else if (reg2 == 0b1100) x = (vms.flags & VM_FLAG_SAMEBITS); // Same Bit Pattern flag
				else if (reg2 == 0b1101) x = vms.overflow;                   // Overflow register
				else if (reg2 == 0b1110) x = 0xff;                           // Constant: 255.
				else if (reg2 == 0b1111) x = 0x00;                           // Constant: 0.

				// Perform skip.
				// Subcode: eq => Skip if destination register == register A.
				if(mode == 0x00) vms.skipInstruction = (result == x);
				// Subcode: ne => Skip if destination register != register A.
				else if(mode == 0x10) vms.skipInstruction = (result != x);
				// Subcode: gt => Skip if destination register > register A.
				else if(mode == 0x20) vms.skipInstruction = (result > x);
				// Subcode: lt => Skip if destination register < register A.
				else if(mode == 0x30) vms.skipInstruction = (result < x);
				// Subcode: ge => Skip if destination register >= register A.
				else if(mode == 0x40) vms.skipInstruction = (result >= x);
				// Subcode: le => Skip if destination register <= register A.
				else if(mode == 0x50) vms.skipInstruction = (result <= x);
			}

			// Opcode: mathr //////////////////////////////////////////////////
			// "Math Register"
			//
			// Skips the next instruction based on comparisons between the
			// destination register and register A.
			//
			// See subcode descriptions for more information.
			else if(opcode == 0x0f) // RegisterMath
			{
				// Read the opcode.
				data2 = vms.pc++;           // Read the next byte for data.
				reg2 = data2 & 0b1111;      // Extract register (plus special values).
				mode = data2 & 0b11110000;  // Extract sub opcode.
				x = vms.registers[reg2];

				// Decode reg2 special values.
				if (reg2 == 0b1000)      x = (vms.flags & VM_FLAG_CARRY);    // Carry flag
				else if (reg2 == 0b1001) x = (vms.flags & VM_FLAG_ZERO);     // Zero flag
				else if (reg2 == 0b1010) x = (vms.flags & VM_FLAG_OVERFLOW); // Overflow flag
				else if (reg2 == 0b1011) x = (vms.flags & VM_FLAG_NEGATIVE); // Negative flag
				else if (reg2 == 0b1100) x = (vms.flags & VM_FLAG_SAMEBITS); // Same Bit Pattern flag
				else if (reg2 == 0b1101) x = vms.overflow;                   // Overflow register
				else if (reg2 == 0b1110) x = 0xff;                           // Constant: 255.
				else if (reg2 == 0b1111) x = 0x00;                           // Constant: 0.

				// Perform math.

				// Subcode: mathr load ////////////////////////////////////////
				// "Load"
				//
				// Copies register A value to destination register.
				// Sets the zero flag if result is 0.
				// Sets the negative flag if the MSB of result is 1.
				if(mode == 0x00)
				{
					CLEAR_ZERO();
					CLEAR_CARRY();

					// Perform the assignment.
					result = x;

					CHECK_ZERO(result);
					CHECK_CARRY(result);
				}

				// Subcode: mathr add /////////////////////////////////////////
				// "Add"
				//
				// Adds register A value to destination register.
				// Sets the zero flag if result is 0.
				// Sets the carry flag if result is greater than 255.
				// Sets the overflow flag if result is less than -128 or greater than +127.
				// Sets the negative flag if the MSB of result is 1.
				// Sets the overflow register to high byte of value.
				else if(mode == 0x10)
				{
					CLEAR_ZERO();
					CLEAR_CARRY();
					CLEAR_OVERFLOW();
					CLEAR_NEGATIVE();
					vms.overflow = 0;
					largerResult = result;
					largerResult += x;
					result = largerResult & 0xff;
					vms.overflow = (largerResult >> 8) & 0xff;
					CHECK_OVERFLOW(largerResult);
					CHECK_CARRY(largerResult);
					CHECK_ZERO(result);
					CHECK_NEGATIVE(result);
				}

				// Subcode: mathr sub /////////////////////////////////////////
				// "Subtract"
				//
				// Subtracts register A value from destination register.
				// Sets the zero flag if result is 0.
				// Sets the carry flag if result is greater than 255.
				// Sets the overflow flag if result is less than -128 or greater than +127.
				// Sets the negative flag if the MSB of result is 1.
				// Sets the overflow register to high byte of value.
				else if(mode == 0x20)
				{
					CLEAR_ZERO();
					CLEAR_CARRY();
					CLEAR_OVERFLOW();
					CLEAR_NEGATIVE();
					vms.overflow = 0;
					largerResult = result;
					largerResult -= x;
					result = largerResult & 0xff;
					vms.overflow = (largerResult >> 8) & 0xff;
					CHECK_OVERFLOW(largerResult);
					CHECK_CARRY(largerResult);
					CHECK_ZERO(result);
					CHECK_NEGATIVE(result);
				}

				// Subcode: mathr rshift //////////////////////////////////////
				// "Right Shift"
				//
				// Right-shifts destination register value register A times.
				// Sets the zero flag if result is 0.
				// Sets the carry flag to bit that was shifted out.
				//
				// Consider: Shifting multiple bits goes into overflow register.
				else if(mode == 0x30)
				{
					// Move the lsb into the carry flag.
					CLEAR_CARRY();
					SET_CARRY_IF(result & 0b1);

					// Perform the right shift.
					result >>= x;
					CHECK_ZERO(result);
				}

				// Subcode: mathr lshift //////////////////////////////////////
				// "Left Shift"
				//
				// Left-shifts destination register value register A times.
				// Sets the zero flag if result is 0.
				// Sets the carry flag to bit that was shifted out.
				else if(mode == 0x40)
				{
					// Move the msb into the carry flag.
					CLEAR_CARRY();
					SET_CARRY_IF(result & 0b10000000);
					
					// Perform the left shift.
					result <<= x;
					CHECK_ZERO(result);
				}

				// Subcode: mathr mult ////////////////////////////////////////
				// "Multiply"
				//
				// Multiplies destination register value by register A value.
				// Sets the zero flag if result is 0.
				// Sets the carry flag if result is greater than 255.
				// Sets the overflow flag if result is less than -128 or greater than +127.
				// Sets the negative flag if the MSB of result is 1.
				// Sets the overflow register to high byte of value.
				else if(mode == 0x50)
				{
					CLEAR_ZERO();
					CLEAR_CARRY();
					CLEAR_OVERFLOW();
					CLEAR_NEGATIVE();
					vms.overflow = 0;
					largerResult = result;
					largerResult *= x;
					result = largerResult & 0xff;
					vms.overflow = (largerResult >> 8) & 0xff;
					CHECK_OVERFLOW(largerResult);
					CHECK_CARRY(largerResult);
					CHECK_ZERO(result);
					CHECK_NEGATIVE(result);
				}

				// Subcode: mathr div /////////////////////////////////////////
				// "Multiply"
				//
				// Divides destination register by register A.
				// Sets the zero flag if result is 0.
				// Sets the negative flag if the MSB of result is 1.
				else if(mode == 0x60)
				{
					CLEAR_ZERO();
					CLEAR_NEGATIVE();
					result /= x;
					CHECK_ZERO(result);
					CHECK_NEGATIVE(result);
				}

				// Subcode: mathr mod /////////////////////////////////////////
				// "Modulo"
				//
				// Mods destination register by register A.
				// Sets the zero flag if result is 0.
				// Sets the negative flag if the MSB of result is 1.
				else if(mode == 0x70)
				{
					CLEAR_ZERO();
					CLEAR_NEGATIVE();
					result %= x;
					CHECK_ZERO(result);
					CHECK_NEGATIVE(result);
				}

				// Subcode: mathr and /////////////////////////////////////////
				// "Bitwise And"
				//
				// Bitwise-ANDs destination register and register A.
				// Sets the zero flag if result is 0.
				else if(mode == 0x80)
				{
					CLEAR_ZERO();
					result &= x;
					CHECK_ZERO(result);
				}

				// Subcode: mathr or //////////////////////////////////////////
				// "Bitwise Or"
				//
				// Bitwise-ORs destination register and register A.
				// Sets the zero flag if result is 0.
				else if(mode == 0x90)
				{
					CLEAR_ZERO();
					result |= x;
					CHECK_ZERO(result);
				}

				// Subcode: mathr xor /////////////////////////////////////////
				// "Bitwise Xor"
				//
				// Bitwise-XORs destination register and register A.
				// Sets the zero flag if result is 0.
				else if(mode == 0xA0) // r ^= a
				{
					CLEAR_ZERO();
					result ^= x;
					CHECK_ZERO(result);
				}

				// Subcode: mathr ror /////////////////////////////////////////
				// "Right Rotate"
				//
				// Rotates bits right, LSB becomes MSB. (once for now.)
				// Sets the zero flag if result is 0.
				else if(mode == 0xB0) // r rotate right by a
				{
					CLEAR_ZERO();
					temp = x & 0b1;
					temp = temp ? 0b10000000 : 0;
					result >>= 1;
					result |= temp;
					CHECK_ZERO(result);
				}

				// Subcode: mathr rol /////////////////////////////////////////
				// "Left Rotate"
				//
				// Rotates bits right, LSB becomes MSB. (once for now.)
				// Sets the zero flag if result is 0.
				else if(mode == 0xC0) // r rotate left by a
				{
					temp = x & 0b10000000;
					temp = temp ? 1 : 0;
					result <<= 1;
					result |= temp;
					CHECK_ZERO(result);
				}
				// Store the low part in reg1, high part in overflow, set overflow flag.
				result = largerResult & 0xff;
				vms.overflow = (largerResult >> 8) & 0xff;
			}
			vms.registers[reg1] = result;
			
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