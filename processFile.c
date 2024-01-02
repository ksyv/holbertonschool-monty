#include "monty.h"
/**
 * processFile - check if the user's command respect usage
 * @file : file would be open and process
 */
void processFile(char *file)
{
	FILE *openFile;
	size_t readSize = 0;
	void (*opcode_func)(stack_t **, unsigned int);
	int line_number = 1;
	stack_t *new;

	openFile = fopen(file, "r");
	if (!openFile)
	{
		dprintf(STDERR_FILENO, "Error: Can't open file %s\n", file);
		exit(EXIT_FAILURE);
	}
	while (getline(&buffer, &readSize, openFile))
	{
		opcode_func = commandChecker();
		if (opcode_func == 0)
		{
			dprintf(STDERR_FILENO, "L%i: unknown instruction %s", line_number, buffer);
			exit(EXIT_FAILURE);
		}
		opcode_func(&new, line_number);
		line_number++;
	}
	free(buffer);
	free(new);
	fclose(openFile);
}
