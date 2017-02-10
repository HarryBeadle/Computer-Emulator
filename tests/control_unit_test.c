#include <stdio.h>
#include <string.h>

#include "../inc/opcodes.h"
#include "../inc/globals.h"
#include "../inc/control_unit.h"

// static int test_program[] = {
// 	JMP << 12 | 0x0004, 
// 	0x0000,
// 	0x0001,
// 	0x0009,
// 	ADD << 12 | 0x02 << 6 | 0x03,
// 	STO << 12 | 0x0002,
// 	JMP << 12 | 0x0004
// };

static int test_program[] = {
	ADD << 12 | 2 << 6 | 3, 
	STO << 12 | 4,
	0x0001,
	0x0001,
	0x0000,
};

void memdump(int n)
{
	printf("Memory Dump:\n");
	for (int i = 0; i < n; i++) {
		printf("%d:%#06x O:%d A:%d B:%d C:%d\n", 
			i, 
			memory[i], 
			(memory[i] & 0xF000) >> 12,
			(memory[i] & 0x0FC0) >> 6,
			memory[i] & 0x003F,
			memory[i] & 0x0FFF
		);
	}
}

int main(void)
{
	printf("Setting Memory...\n");
	memcpy(memory, test_program, sizeof(test_program));
	memdump(10);
	printf("Initalising...\n");
	next_state = GET_INSTRUCTION;
	instruction_register = 0;
	accumulator = 5;
	program_counter = 0;
	printf("ADDR   DATA   PC     IR     ACC\n");
	for (int i = 0; i < 9; i++) {
		printf("%#06x %#06x %#06x %#06x %#06x\n", 
			addr,
			data,
			program_counter,
			instruction_register,
			accumulator
		);
		updateCU();
		updateALU();
		updateMemory();
	}
	memdump(10);

}