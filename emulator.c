/*

Harry Beadle
hb11g15@soton.ac.uk

Date Created: 10/02/2017
emulator.c

> Wrapper for simulation of the processor.

ELEC2204 Computer Engineering
Coursework: Computer Emulation

*/
#include <stdio.h>
#include <string.h>

#include "inc/emulator.h"

int tick(void)
{
	// Tick the processor
	if (updateCU() != 0) {
		printf("CU UNDEF\n");
		return 1;
	}
	if (updateALU() != 0) {
		printf("ALU UNDEF\n");
		return 1;
	}
	if (updateMemory() != 0) {
		printf("MEM UNDEF\n");
		return 1;
	}
	return 0;
}

char* getStateString(int state) {
	switch (state) {
		case 0: return "DECODE";
		case 1: return "ALU_SETAGETB";
		case 2: return "ALU_SETBEXEC";
		case 3: return "INC_COUNTER";
		case 4: return "GET_INSTRUCTION";
		case 5: return "SET_INSTRUCTION";
	}
}

void memdump(int n)
{
	printf("Memory Dump:\n");
	for (int i = 0; i < n; i++) {
		printf("%d:%#06x O:%d A:%d B:%d C:%d\n", 
			i, 
			memory[i], 
			(memory[i] & 0xF000) >> 12,
			(memory[i] & 0x0FC0) >> 6,
			memory[i] & 0x003F,
			memory[i] & 0x0FFF
		);
	}
}

int main(void)
{
	// Load the program into memory.
	printf("Loading Program into Memory... ");
	memcpy(memory, program, sizeof(program));
	printf("Done.\n");
	memdump(6);
	// Initalise the system.
	printf("Initalising Control Unit... ");
	program_counter = 0;
	next_state = GET_INSTRUCTION;	
	printf("Done.\n");
	// Print the debug output.
	printf("CYCL DATA ADDR PC-- IR-- ACC- ST--\n");
	int cycle = 0;
	while (cycle < 1000) {
		printf("%04X %04X %04X %04X %04X %04X %s\n",
			cycle,
			data,
			addr,
			program_counter,
			instruction_register,
			accumulator,
			getStateString(state)
		);
		tick();
		cycle++;
	}
	memdump(6);
}