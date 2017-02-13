/*

Harry Beadle
hb11g15@soton.ac.uk

Date Created: 10/02/2017
emulator.c

> Wrapper for simulation of the processor.

ELEC2204 Computer Engineering
Coursework: Computer Emulation

*/

#include "inc/emulator.h"

int tick(void)
{
	// Simulte a rising clock edge.
	if (updateCU() != 0) {
		printf("CU UNDEF\n");
		return 1;
	}
	if (updateALU() != 0) {
		printf("ALU UNDEF\n");
		return 1;
	}
	if (updateMemory() != 0) {
		printf("MEM UNDEF\n");
		return 1;
	}
	return 0;
}

char* getStateString(int state) 
{
	// Return the a human-reabable string for the given state.
	switch (state) {
		case 0: return "DECODE         ";
		case 1: return "ALU_SETAGETB   ";
		case 2: return "ALU_SETBEXEC   ";
		case 3: return "INC_COUNTER    ";
		case 4: return "GET_INSTRUCTION";
		case 5: return "SET_INSTRUCTION";
	}
}

char* getMemState(void)
{
	// Return a human-reable string for the current state of the
	// memory.
	switch (memory_control) {
		case MEM_HIZ: return "High Z";
		case MEM_SET: return "Set   ";
		case MEM_ENB: return "Enable";
		default: return "      ";
	}
}

char* getOpcodeString(int opcode)
{
	// Return a human-readable stringr the given opcode.
	switch (opcode) {
		case ADD: return "ADD";
		case SUB: return "SUB";
		case AND: return "AND";
		case  OR: return "OR ";
		case NOT: return "NOT";
		case JMP: return "JMP";
		case STO: return "STO";
		default: return "Illegal";
	}
}

void load(void) 
{
	// Initalise and load the emulator with the program defined in 
	// emulator.h
	program_counter = 0;
	next_state = GET_INSTRUCTION;
	memcpy(memory, program, sizeof(program));
}

int main(void)
{
	// Initalise ncurses
	initscr();
	noecho();
	cbreak();
	nodelay(stdscr, TRUE);
	int row, col;
	getmaxyx(stdscr, row, col);

	// Add Input Prompt Message
	attron(A_REVERSE);
	msg = "Press Enter to Progress, L to load program.";
	mvprintw(0, 0, "%*s%*s"
		(col/2) + strlen(msg)/2, msg, col/2 - strlen(msg)/2, ""
	);
	attroff(A_REVERSE);

	// Loop forever...
	while (1) {

		// Output Memory Stats
		attron(A_BOLD);
		mvprintw(1, 0, "Memory:");
		attroff(A_BOLD);
		mvprintw(2, 0, getMemState());
		for (int i = 0; i < row - 2; i++) {
			if (i == addr) attron(A_UNDERLINE);
			mvprintw(i+3, 0, "%02X: %04X", i, memory[i]);
			if (i == addr) attroff(A_UNDERLINE);
		}

		// Output Control Unit Stats
		attron(A_BOLD);
		mvprintw(1, 10, "Control Unit:");
		attroff(A_BOLD);
		mvprintw(2, 10, "Opcode      %s", 
			getOpcodeString((instruction_register & 0xF000) >> 12)
		);
		mvprintw(3, 10, "State       %s", 
			getStateString(state)
		);
		mvprintw(4, 10, "Next State  %s", 
			getStateString(next_state)
		);
		mvprintw(5, 10, "PC          %04X", program_counter);
		mvprintw(6, 10, "IR          %04X", instruction_register);
		mvprintw(7, 10, "Accumulator %04X", accumulator);
		mvprintw(8, 10, "Buffer A    %04X", alu_buffer_a);
		mvprintw(9, 10, "Buffer B    %04X", alu_buffer_b);

		// Output ALU Stats
		attron(A_BOLD);
		mvprintw(11, 10, "ALU:");
		attroff(A_BOLD);
		mvprintw(12, 10, "A           %04X", alu_in_a);
		mvprintw(13, 10, "B           %04X", alu_in_b);
		mvprintw(14, 10, "Control     %s", 
			getOpcodeString(alu_control)
		);

		// Ouput Global Stats
		attron(A_BOLD);
		mvprintw(16, 10, "Globals:");
		attroff(A_BOLD);
		mvprintw(17, 10, "Data Bus    %04X", data);
		mvprintw(18, 10, "Address Bus %04X", addr);

		// Get user input and...
		refresh();
		switch (getch()) {
			case 'q':
				// quit.
				endwin();
				return 0;
			case 'l':
				// load the program.
				load();
			case '\n':
				// tick the proccessor.
				tick();
				break;
			default:
				break;
		}
	}
}