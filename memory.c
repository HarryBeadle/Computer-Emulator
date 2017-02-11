/*

Harry Beadle
hb11g15@soton.ac.uk

Date Created: 10/02/2017
alu.h

> Defines behavior of the memory.

ELEC2204 Computer Engineering
Coursework: Computer Emulation

*/

#include "inc/memory.h"

int updateMemory(void)
{
	switch (memory_control) {
		case MEM_HIZ:
			break;
		case MEM_SET:
			memory[addr] = data;
			break;
		case MEM_ENB:
			data = memory[addr];
			break;
		default:
			return 1;
	}
	return 0;
}