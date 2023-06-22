#include "monty.h"

/**
 * sub - subtracts the top element of the stack
 * from the second top element
 *
 * @stack: a pointer to the stack.
 * @line_number: the line number.
 */
void sub(stack_t **stack, unsigned int line_number)
{
	if (!*stack || !(*stack)->next)
		exit_with_ferror("L%u: can't sub, stack too short\n", line_number);
	(*stack)->next->n -= (*stack)->n;
	pop(&*stack, line_number);
}
