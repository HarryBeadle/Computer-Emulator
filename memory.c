#include "includes/memory.h"

#define MEMORY_SIZE 1024
#define MEM_HIZ 0x0
#define MEM_SET 0x1
#define MEM_ENB 0x2

// Memory
int memory_control;
int memory[MEMORY_SIZE];
int data;
int addr;

int updateMemory(void)
{
	switch (memory_control) {
		case MEM_HIZ:
			break;
		case MEM_SET:
			memory[addr] = data;
			break;
		case MEM_ENB:
			data = memory[addr];
			break;
		default:
			return 1;
	}
	return 0;
}