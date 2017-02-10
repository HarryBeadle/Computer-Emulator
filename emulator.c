/*

Harry Beadle
hb11g15@soton.ac.uk

Date Created: 10/02/2017
emulator.c

> Wrapper for simulation of the processor.

ELEC2204 Computer Engineering
Coursework: Computer Emulation

*/

#include "inc/globals.h"
#include "inc/opcodes.h"
#include "inc/alu.h"
#include "inc/memory.h"

uint16_t pc;
uint16_t ir;
uint16_t ac;

void initalise(void)
{
	pc = 0x0000; 
	ir = 0x0000;
	ac = 0x0000;
}

void tick(void)
{
	// Tick the processor
	if (updateID() != 0)
		return 1;
	if (updateALU() != 0)
		return 1;
	if (updateMemory() != 0)
		return 1;
	return 0;
}

int main(void)
{
	for (int clock_cycle = 0; true; clock_cycle++) {
		printf("%d %d %d\n", clock_cycle, data);
		tick()
	}
}