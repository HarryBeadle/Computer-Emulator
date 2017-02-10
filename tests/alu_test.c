#include <stdio.h>
#include <assert.h>

#include "../includes/opcodes.h"
#include "../includes/alu.h"

int main(void)
{
	// Test ADD
	printf("Testing ADD... ");
	alu_control = ADD;
	for (int a = 0x000; a <= 0xFFF; a++) {
		for (int b = 0x000; b <= 0xFFF; b++) {
			alu_in_a = a;
			alu_in_b = b;
			updateALU();
			if (data != (a + b)) {
				printf("-- DEBUG INFO --\n");
				printf("CTL   ADD\n");
				printf("ALU A %d %d\n", a, alu_in_a);
				printf("ALU B %d %d\n", b, alu_in_b);
				printf("DATA  %d %d\n", a + b, data);
				printf("--  END INFO  --\n");
			}
			assert (data == (a + b));
		}
	}
	printf("Passed.\n");

	// Test SUB
	printf("Testing SUB... ");
	alu_control = SUB;
	for (int a = 0x000; a <= 0xFFF; a++) {
		for (int b = 0x000; b <= 0xFFF; b++) {
			alu_in_a = a;
			alu_in_b = b;
			updateALU();
			if (data != (a - b)) {
				printf("-- DEBUG INFO --\n");
				printf("CTL   SUB\n");
				printf("ALU A %d %d\n", a, alu_in_a);
				printf("ALU B %d %d\n", b, alu_in_b);
				printf("DATA  %d %d\n", a + b, data);
				printf("--  END INFO  --\n");
			}
			assert (data == (a - b));
		}
	}
	printf("Passed.\n");

	// Test AND
	printf("Testing AND... ");
	alu_control = AND;
	for (int a = 0x000; a <= 0xFFF; a++) {
		for (int b = 0x000; b <= 0xFFF; b++) {
			alu_in_a = a;
			alu_in_b = b;
			updateALU();
			if (data != (a & b)) {
				printf("-- DEBUG INFO --\n");
				printf("CTL   AND\n");
				printf("ALU A %d %d\n", a, alu_in_a);
				printf("ALU B %d %d\n", b, alu_in_b);
				printf("DATA  %d %d\n", a & b, data);
				printf("--  END INFO  --\n");
			}
			assert (data == (a & b));
		}
	}
	printf("Passed.\n");

	// Test OR
	printf("Testing OR...  ");
	alu_control = OR;
	for (int a = 0x000; a <= 0xFFF; a++) {
		for (int b = 0x000; b <= 0xFFF; b++) {
			alu_in_a = a;
			alu_in_b = b;
			updateALU();
			if (data != (a | b)) {
				printf("-- DEBUG INFO --\n");
				printf("CTL   OR\n");
				printf("ALU A %d %d\n", a, alu_in_a);
				printf("ALU B %d %d\n", b, alu_in_b);
				printf("DATA  %d %d\n", a | b, data);
				printf("--  END INFO  --\n");
			}
			assert (data == (a | b));
		}
	}
	printf("Passed.\n");

	// Test OR
	printf("Testing NOT... ");
	alu_control = NOT;
	for (int a = 0x000; a <= 0xFFF; a++) {
		for (int b = 0x000; b <= 0xFFF; b++) {
			alu_in_a = a;
			alu_in_b = b;
			updateALU();
			if (data != (~a)) {
				printf("-- DEBUG INFO --\n");
				printf("CTL   OR\n");
				printf("ALU A %d %d\n", a, alu_in_a);
				printf("ALU B %d %d\n", b, alu_in_b);
				printf("DATA  %d %d\n", ~a, data);
				printf("--  END INFO  --\n");
			}
			assert (data == (~a));
		}
	}
	printf("Passed.\n");

	// Finished Testing
	printf("Passed all tests.\n");
}
