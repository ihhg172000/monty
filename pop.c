#include "monty.h"

/**
 * pop - removes the top element of the stack.-
 * @stack: a pointer to the stack.
 * @line_number: the line number.
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (!(*stack))
		exit_with_ferror("L%d: can't pop an empty stack\n", line_number);

	temp = (*stack)->next;
	free(*stack);
	*stack = temp;
}
