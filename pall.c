#include "monty.h"

/**
 * pall - prints all the values on the stack.
 * @stack: a pointer to the stack.
 * @line_number: the line number.
 */
void pall(stack_t **stack, __attribute__((unused)) unsigned int line_number)
{
	stack_t *curr = *stack;

	while (curr)
	{
		printf("%d\n", curr->n);
		curr = curr->next;
	}
}
