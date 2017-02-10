/*

Harry Beadle
hb11g15@soton.ac.uk

Date Created: 10/02/2017
opcodes.h

> opcodes for the simulated processor.
> Instructions are as follows:
>> [OPCODE (4)][OPERAND A (6)][OERAND B (6)]

ELEC2204 Computer Engineering
Coursework: Computer Emulation

*/

#ifndef _OPCODES_
	#define _OPCODES_

	// Mathmatical Operations
	#define ADD 0x0
	#define SUB 0x1
	
	// Logical Operations
	#define AND 0x2
	#define OR  0x3
	#define NOT 0x4

	// Movement
	#define JMP 0x5

#endif