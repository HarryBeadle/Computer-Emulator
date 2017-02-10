/*

Harry Beadle
hb11g15@soton.ac.uk

Date Created: 10/02/2017
alu.h

> Header for the ALU of the Processor.
> alu_control takes the opcode for ALU operations.

ELEC2204 Computer Engineering
Coursework: Computer Emulation

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