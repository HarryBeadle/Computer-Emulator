/*

Harry Beadle
hb11g15@soton.ac.uk

Date Created: 10/02/2017
alu.h

> To be completed.

ELEC2204 Computer Engineering
Coursework: Computer Emulation

*/

// Program Counter
uint16_t program_counter;
uint8_t pc_ctl;

// Instruction Register
uint16_t intruction_register;
uint8_t ir_ctl;

// Accumulator
uint16_t accumulator;
uint8_t ac_ctl;

int updateRegisters(void)
{
	switch (pc_ctl) {
		case MEM_HIZ:

	}
}