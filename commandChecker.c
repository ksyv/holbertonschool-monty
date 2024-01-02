#include "monty.h"

/**
 * check_opcodes - checks a valid opcode in the line
 * Return: opcode (char *)
 */

void (*check_opcodes(void))(stack_t **, unsigned int)
{
	int index = 0, index2;
	int valid_opcode;
	int lengthOpcode;

	instruction_t opcodes[] = {
		{"push", push},
		{"pall", pall},
		{NULL, NULL}
	};
	while (opcodes[index].opcode)
	{
		index2 = 0;
		valid_opcode = 1;
		lengthOpcode = strlen(opcodes[index].opcode);
		while (index2 < lengthOpcode)
		{
			if (opcodes[index].opcode[index2] != buffer[index2])
			{
				valid_opcode = 0;
				break;
			}
			index2++;
		}
		if (valid_opcode == 1 && (buffer[index2] == '\n'
			|| buffer[index2] == ' ' || buffer[index2] == '\0'))
			break;
		index++;
	}
	return (opcodes[index].f);
}
