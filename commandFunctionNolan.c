#include "monty.h"

/**
 * pall_function - print line per line the stack
 * @stack: stac of data
 * @line_number: file line number
*/
void pall(stack_t **stack, unsigned int line_number)
{
	(void)(line_number);
	while (*stack)
	{
		printf("%i\n", (*stack)->n);
		stack = &(*stack)->next;
	}
}

/**
 * pop - delete a line from the top of the stack
 * @stack: stac of data
 * @line_number: file line number
*/
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *delete = *stack;

	if (!*stack || !stack)
	{
		dprintf(STDERR_FILENO, "L%i: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}

	if ((*stack)->next)
	{
		*stack = delete->next;
		(*stack)->prev = NULL;
		free(stack);
	}
	else
	{
		free(*stack);
		*stack = NULL;
	}
}

/**
 * add - adds the top two nodes of the stack
 * @stack: nodes
 * @line_number: file line number
 */
void add(stack_t **stack, unsigned int line_number)
{
	stack_t *head = *stack;

	if (!*stack || !head->next)
	{
		dprintf(STDERR_FILENO, "L%i: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	(head->next)->n += head->n;
	pop(&head, line_number);
	*stack = head;
}
