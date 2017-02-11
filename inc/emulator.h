/*

Harry Beadle
hb11g15@soton.ac.uk

Date Created: 10/02/2017
emulator.h

> Header for the simulation wrapper.

ELEC2204 Computer Engineering
Coursework: Computer Emulation

*/
#ifndef _EMULATOR_H_
	#define _EMULATOR_H_

	#include <stdio.h>
	#include <string.h>

	#include "globals.h"
	#include "opcodes.h"
	#include "alu.h"
	#include "memory.h"
	#include "control_unit.h"

	char* null;

	int tick(void);
	int main(void);
	char* getStateString(int state);
	void memdump(int n);

	static int program[] = {
		JMP << 12 | 3,
		0,
		1,
		ADD << 12 | 1 << 6 | 2,
		STO << 12 | 1,
		JMP << 12 | 3
	};

#endif