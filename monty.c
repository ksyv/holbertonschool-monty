#include "monty.h"
/**
 * main - check if the user's command respect usage
 * @argc : number of argument
 * @argv : user's arguments
 * Return: 0 for succes
 */
int main(int argc, char *argv[])
{
	stack_t *stack = NULL;
	char *line = NULL;
	size_t length = 0;
	unsigned int lineNumber = 0;
	char *opcode = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	FILE *file = fopen(argv[1], "r");

	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while (getline(&line, &length, file) != EOF)
	{
		lineNumber++;
		opcode = strtok(line, " \t\n");
		if (opcode == NULL || *opcode == '#')
			continue;
		else
			execFunction(&stack, opcode, lineNumber);
	}

	fclose(file);
	if (opcode != NULL)
		free(opcode);
	freeStack(stack);

	return (0);
}
