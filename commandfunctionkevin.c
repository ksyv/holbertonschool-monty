#include "monty.h"

/**
 * pint - prints the value at the top of the stack, followed by a new line.
 *
 * @stack: a pointer to the stack.
 * @line_number: the line number .
 */
void pint(stack_t **stack, unsigned int line_number)
{
	stack_t *currentNode = *stack;

	if (currentNode != NULL)
		printf("%d\n", currentNode->n);
	else
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
}
/**
 * swap - Swaps the top two elements of the stack.
 * @stack: a pointer to the stack.
 * @line_number: the line number.
 */
void swap(stack_t **stack, unsigned int line_number)
{
	int number = 0;
	stack_t *currentNode = NULL;

	currentNode = *stack;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	number = currentNode->n;
	currentNode->n = currentNode->next->n;
	currentNode->next->n = number;
}
/**
 * nop - doesn’t do anything
 * @stack: a pointer to the stack
 * @line_number: the line number
 */
void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}
