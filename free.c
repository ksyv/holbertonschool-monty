#include "monty.h"

/**
 * freeStack - Frees memory allocated for the stack.
 *
 * @stack: a pointer to the top of the stack.
 */
void freeStack(stack_t *stack)
{
	stack_t *currentNode = NULL;

	while (stack != NULL)
	{
		currentNode = stack;

		stack = stack->next;
		free(currentNode);
	}
}
