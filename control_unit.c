#include <stdio.h>

#include "inc/control_unit.h"

int updateCU(void)
{
	state = next_state;
	// Decode opcode, a, b and c from the instruction register.
	int opcode = (instruction_register & 0xF000) >> 12;
	int a = (instruction_register & 0x0FC0) >> 6;
	int b = instruction_register & 0x003F;
	int c = instruction_register & 0x0FFF;
	switch (state) {
		case DECODE:
			printf(">>>DECODE ");
			// Decode the instruction in the IR.
			switch (opcode) {
				case JMP:
					printf("JMP<<<\n");
					// Jump to c
					program_counter = c;
					next_state = GET_INSTRUCTION;
					break;
				case STO:
					printf("STO<<<\n");
					// Store the value of AC at c.
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
					printf("ALU<<<\n");
					// Do an ALU computation.
					// Get value at A.
					addr = a;
					memory_control = MEM_ENB;
					next_state = ALU_SETAGETB;
					break;
			}
			break;
		case ALU_SETAGETB:
			printf(">>>ALU_SETAGETB<<<\n");
			// Set Buffer A, get data at b.
			alu_buffer_a = data;
			addr = b;
			memory_control = MEM_ENB;
			next_state = ALU_SETBEXEC;
			break;
		case ALU_SETBEXEC:
			printf(">>>ALU_SETBEXEC\n");
			alu_buffer_b = data;
			memory_control = MEM_HIZ;
			alu_control = opcode;
			printf("ALUCTL %d\n", alu_control);
			printf("BUFFA %d\n", alu_buffer_a);
			printf("BUFFB %d\n", alu_buffer_b);
			printf("<<<\n");
			alu_in_a = alu_buffer_a;
			alu_in_b = alu_buffer_b;
			next_state = INC_COUNTER;
			break;
		case INC_COUNTER:
			// Increment the PC before getting the instruction at that address.
			printf(">>>INC_COUNTER<<<\n");
			accumulator = data;
			memory_control = MEM_HIZ;
			program_counter++;
			next_state = GET_INSTRUCTION;
			break;
		case GET_INSTRUCTION:
			// Get the instruction from the address in the program counter.
			printf(">>>GET_INSTRUCTION<<<\n");
			addr = program_counter;
			memory_control = MEM_ENB;
			next_state = SET_INSTRUCTION;
			break;
		case SET_INSTRUCTION:
			// Set the IR to the current value of the data bus.
			printf(">>>SET_INSTRUCTION\n");
			printf("DATA %d\n", data);
			printf("SETTING IR...\n");
			instruction_register = data;
			printf("IR %d\n", data);
			printf("<<<\n");
			memory_control = MEM_HIZ;
			next_state = DECODE;
			break;
	}
}