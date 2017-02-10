/*
ALU.c

based on the 4-bit input (same as opcode for simplicitu _)
*/

#include "includes/alu.h"

int updateALU(void)
{
	switch (alu_control) {
		case ALU_HIZ:
			break;
		case ADD:
			data = alu_in_a + alu_in_b;
			break; 
		case SUB:
			data = alu_in_a - alu_in_b;
			break;
		case AND:
			data = alu_in_a & alu_in_b;
			break;
		case OR:
			data = alu_in_a | alu_in_b;
			break;
		case NOT:
			data = ~alu_in_a;
			break;
		default:
			return 1;
	}
	return 0;
}