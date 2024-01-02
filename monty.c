#include "monty.h"
/**
 * main - check if the user's command respect usage
 * @argc : number of argument
 * @argv : user's arguments
 * Return: 0 for succes
 */
int main(int argc, char **argv)
{
	if (argc != 2 || (strcmp(argv[0], "monty") != 0))
	{
		dprintf(STDERR_FILENO, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	processFile(argv[1]);
	return (0);
}
