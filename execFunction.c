#include "monty.h"

/**
 * execFunction - Executes Monty bytecode instructions.
 * @stack: ptr to stack.
 * @opcode: string to execute.
 * @line_number: the line number.
 * Return: 0 if success.
 */
int execFunction(stack_t **stack, char *opcode, unsigned int line_number)
{
	int index = 0;

	instruction_t instructions[] = {
		{"push", push},
		{"pall", pall},
		{"pop", pop},
		{"add", add},
		{"pint", pint},
		{"swap", swap},
		{NULL, NULL}
	};

	while (instructions[index].opcode != NULL)
	{
		if (strcmp(opcode, instructions[index].opcode) == 0)
		{
			instructions[index].f(stack, line_number);
			return (0);
		}
		index++;
	}

	fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
	exit(EXIT_FAILURE);
}
