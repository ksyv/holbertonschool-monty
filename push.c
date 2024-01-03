#include "monty.h"

/**
 * push - adds a node at stack
 * @stack: nodes
 * @lineNumber: file line number
 */

void push(stack_t **stack, unsigned int lineNumber)
{
	char **tokenisedLine;
	int number;
	stack_t *newNode;

	newNode = malloc(sizeof(stack_t));
	if (!newNode)
	{
		free(newNode);
		dprintf(STDERR_FILENO, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	tokenisedLine = tokenise(buffer, " ");

	number = atoi(tokenisedLine[1]);
	if (number == 0)
	{
		dprintf(STDERR_FILENO, "L%i: usage: push integer\n", lineNumber);
		exit(EXIT_FAILURE);
	}

	newNode->n = number;
	newNode->prev = NULL;
	newNode->next = *stack;

	if (*stack)
		(*stack)->prev = newNode;
	*stack = newNode;
	free(tokenisedLine);
}
/**
 * tokenise - split string in token according to a separator
 * @string: string
 * @separator: separator
 * Return: divided str
 */

char **tokenise(char *string, char *separator)
{
	char *token, **tokenisedLine;
	int index = 0;
	const int initialSize = 100;

	token = strtok(string, separator);
	tokenisedLine = (char **)malloc(initialSize * sizeof(char *));

	if (!tokenisedLine)
	{
		free(tokenisedLine);
		dprintf(STDERR_FILENO, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	while (token)
	{
		tokenisedLine[index] = token;
		token = strtok(NULL, separator);
		index++;
	}
	return (tokenisedLine);
}
/**
 * pall - prints all nodes
 * @stack: nodes
 * @line_number: file line number
 */

void pall(stack_t **stack, unsigned int line_number)
{
	(void)line_number;

	while (*stack)
	{
		printf("%i\n", (*stack)->n);
		stack = &(*stack)->next;
	}
}
