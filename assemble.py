from sys import argv

filename = argv[1]

comment = '#'

memory = []

opcode = {
	'ADD' : 0x0,
	'SUB' : 0x1,
	'AND' : 0x2,
	'OR'  : 0x3,
	'NOT' : 0x4,
	'JMP' : 0x5,
	'STO' : 0x6
}

with open(filename, 'r') as src:
	for line in src:
		sections = line.split(comment);
		if (comment not in sections[1]):
			symb = sections[1].split(" ")
			if (len(symb) == 2):
				memory.append(
					opcode[symb[0]] << 12 | 
					symb[]
				)

if len(argv) == 2:
	outputfile = "a.hex"
elif len(argv) == 3:
	outputfile = argv[2]

with open(outputfile, 'wb') as out:
	for int in memory