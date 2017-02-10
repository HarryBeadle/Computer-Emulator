/*
ALU.h

based on the 4-bit input (same as opcode for simplicitu _)
*/

#ifndef _ALU_H_
	#define _ALU_H_

	#include "opcodes.h"
	#include "globals.h"

	#define ALU_HIZ 0xF

	int alu_control;
	int alu_in_a;
	int alu_in_b;

	int updateALU(void);

	#include "../alu.c"

#endif