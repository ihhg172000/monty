#include "monty.h"

/**
* free_stack - frees a stack.
* @stack: a pointer to the stack.
*/
void free_stack(stack_t **stack)
{
	stack_t *next;

	while (*stack)
	{
		next = (*stack)->next;
		free(*stack);

		*stack = next;
	}

	*stack = NULL;
}
