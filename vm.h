#ifndef _VM_H
#define _VM_H

#define VM_NUM_REGISTERS 8

#define PROGRAM_CODE_LENGTH 256
#define PROGRAM_RAM_LENGTH 256

#define VMRUN_RETURN_EXIT 0
#define VMRUN_RETURN_BREAK 1
#define VMRUN_RETURN_KILL 2
#define VMRUN_RETURN_ERROR 3

struct VMState {
	unsigned char registers[8];
	unsigned char pc;
	bool skipInstruction;
	bool breakpointsEnabled;
};

extern unsigned char initCode[PROGRAM_CODE_LENGTH];
extern unsigned char lineFlags[PROGRAM_CODE_LENGTH/2];
unsigned char vmRun(VMState* vmPtr);
unsigned char vmReset(VMState* vmPtr, bool breakpointsEnabled);

#endif
