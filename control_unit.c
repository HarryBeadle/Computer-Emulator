/*

Harry Beadle
hb11g15@soton.ac.uk

Date Created: 10/02/2017
control_unit.h

> Code for the Control Unit emulation.

ELEC2204 Computer Engineering
Coursework: Computer Emulation

*/

#include "inc/control_unit.h"

int updateCU(void)
{
	// Move to the next state.
	state = next_state;
	// Decode opcode, a, b and c from the instruction register.
	int opcode = (instruction_register & 0xF000) >> 12;
	int a = (instruction_register & 0x0FC0) >> 6;
	int b = instruction_register & 0x003F;
	int c = instruction_register & 0x0FFF;
	switch (state) {
		case DECODE:
			// Decode the instruction in the IR.
			switch (opcode) {
				case JMP:
					// Jump to the instruction at address c.
					program_counter = c;
					next_state = GET_INSTRUCTION;
					break;
				case STO:
					// Store the value of the accumulator at address 
					// c.
					addr = c;
					data = accumulator;
					memory_control = MEM_SET;
					next_state = INC_COUNTER;
					break;
				case ADD:
				case SUB:
				case AND:
				case OR:
				case NOT:
					// Do an ALU computation.
					// Get value at A.
					addr = a;
					memory_control = MEM_ENB;
					next_state = ALU_SETAGETB;
					break;
				default:
					// Not a defined opcode: panic!
					return 1;
			}
			break;
		case ALU_SETAGETB:
			// Set Buffer A, get data at b.
			alu_buffer_a = data;
			addr = b;
			memory_control = MEM_ENB;
			next_state = ALU_SETBEXEC;
			break;
		case ALU_SETBEXEC:
			// Set buffer B, start the execution of the ALU command.
			alu_buffer_b = data;
			memory_control = MEM_HIZ;
			alu_control = opcode;
			alu_in_a = alu_buffer_a;
			alu_in_b = alu_buffer_b;
			next_state = INC_COUNTER;
			break;
		case INC_COUNTER:
			// Increment the PC before getting the instruction at that
			// address.
			accumulator = data;
			memory_control = MEM_HIZ;
			program_counter++;
			next_state = GET_INSTRUCTION;
			break;
		case GET_INSTRUCTION:
			// Get the instruction from the address in the program 
			// counter.
			addr = program_counter;
			memory_control = MEM_ENB;
			next_state = SET_INSTRUCTION;
			break;
		case SET_INSTRUCTION:
			// Set the IR to the current value of the data bus.
			instruction_register = data;
			memory_control = MEM_HIZ;
			next_state = DECODE;
			break;
	}
	return 0;
}