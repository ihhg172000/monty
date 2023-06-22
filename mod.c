#include "monty.h"

/**
 * mod - computes the rest of the division of the second
 * top element of the stack by the top element of the stack.
 *
 * @stack: a pointer to the stack.
 * @line_number: the line number.
 */
void mod(stack_t **stack, unsigned int line_number)
{
	if (!*stack || !(*stack)->next)
		exit_with_ferror("L%u: can't mod, stack too short\n", line_number);
	if ((*stack)->n == 0)
		exit_with_ferror("L%u: division by zero\n", line_number);
	(*stack)->next->n %= (*stack)->n;
	pop(&*stack, line_number);
}
