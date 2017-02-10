#ifndef _MEMORY_H_
	#define _MEMORY_H_

	#define MEMORY_SIZE 1024
	#define MEM_HIZ 0x0
	#define MEM_SET 0x1
	#define MEM_ENB 0x2

	// Memory
	int memory_control;
	int memory[MEMORY_SIZE];
	int data;
	int addr;

	int updateMemory(void);

#endif