/*

Harry Beadle
hb11g15@soton.ac.uk

Date Created: 10/02/2017
memory.h

> Headers for the memory.
> memory_control takes on of MEM_HIZ, MEM_SET or MEM_ENB.
>> Behaviour is not defined for other inputs.

ELEC2204 Computer Engineering
Coursework: Computer Emulation

*/

#ifndef _MEMORY_H_
	#define _MEMORY_H_

	#define MEMORY_SIZE 1024

	#define MEM_HIZ 0x0
	#define MEM_SET 0x1
	#define MEM_ENB 0x2

	// Memory
	int memory_control;
	int memory[MEMORY_SIZE];
	int data;
	int addr;

	int updateMemory(void);

	#include "../memory.c"

#endif