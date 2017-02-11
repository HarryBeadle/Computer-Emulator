/*

Harry Beadle
hb11g15@soton.ac.uk

Date Created: 10/02/2017
memory_test.c

> Tests for all inputs and modes for the memory.

ELEC2204 Computer Engineering
Coursework: Computer Emulation

*/

#include <stdio.h>
#include <assert.h>

#include "../inc/memory.h"

int main(void) {
	for (int a = 0x0000; a < MEMORY_SIZE; a++) {
		for (int d = 0x0000; d <= 0xFFFF; d++) {
			memory_control = MEM_SET;
			addr = a;
			data = d;
			updateMemory();
			memory_control = MEM_ENB;
			addr = a;
			updateMemory();
			if (data != d) {
				printf("-- DEBUG INFO --\n");
				printf("Address %d, %d\n", a, addr);
				printf("Data    %d, %d\n", d, data);
				printf("Mem Ctl %d\n", memory_control);
				printf("--  END INFO  --\n");
			}
			assert (data == d);
		}
	}
	printf("All Tests Passed.\n");
	return 1;
}