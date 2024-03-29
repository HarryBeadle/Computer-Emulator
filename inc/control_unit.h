/*

Harry Beadle
hb11g15@soton.ac.uk

Date Created: 10/02/2017
control_unit.h

> Header for the Control Unit

ELEC2204 Computer Engineering
Coursework: Computer Emulation

*/

#ifndef _CONTROL_UNIT_H_
	#define _CONTROL_UNIT_H_

	#include "alu.h"
	#include "memory.h"

	int program_counter;
	int accumulator;
	int instruction_register;

	int alu_buffer_a;
	int alu_buffer_b;

	enum {
		DECODE, 
		ALU_SETAGETB, ALU_SETBEXEC,
		INC_COUNTER,
		GET_INSTRUCTION, SET_INSTRUCTION
	} state, next_state;

	int updateCU(void);

	#include "../control_unit.c"

#endif