#include "monty.h"

/**
 * digit - Checks if it's an integer.
 * @opcode: the string to check.
 * Return: 1 if the string is an integer, -1 otherwise.
 */
int digit(char *opcode)
{
	int index;

	if (opcode == NULL)
		return (-1);

	for (index = 0; opcode[index] != '\0'; index++)
	{
		if (opcode[index] != '-' && isdigit(opcode[index]) == 0)
			return (-1);
	}
	return (1);
}

/**
 * push - Push an element to the stack.
 *
 * @stack: a pointer to the stack.
 * @line_number: the line number.
 */
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *newNode = NULL;
	char *numberString = NULL;
	int number = 0;

	newNode = malloc(sizeof(stack_t));

	if (newNode == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	numberString = strtok(NULL, " \t\n");

	if (numberString == NULL || digit(numberString) == -1)
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	number = atoi(numberString);

	newNode->n = number;
	newNode->prev = NULL;

	if (*stack == NULL)
	{
		newNode->next = NULL;
		*stack = newNode;
	}
	else
	{
		newNode->next = *stack;
		(*stack)->prev = newNode;
		*stack = newNode;
	}
}
/**
 * pall - Prints all the values on the stack,
 *        starting from the top of the stack.
 *
 * @stack: a pointer to the top of the stack.
 * @line_number: the line number being executed (not used here).
 */
void pall(stack_t **stack, unsigned int line_number)
{
	(void)line_number;

	stack_t *currentNode = *stack;

	while (currentNode != NULL)
	{
		printf("%d\n", currentNode->n);
		currentNode = currentNode->next;
	}
}
