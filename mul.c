#include "monty.h"

/**
 * mul - multiplies the second top element of
 * the stack with the top element of the stack.
 *
 * @stack: a pointer to the stack.
 * @line_number: the line number.
 */
void mul(stack_t **stack, unsigned int line_number)
{
	if (!*stack || !(*stack)->next)
		exit_with_ferror("L%u: can't mul, stack too short\n", line_number);
	(*stack)->next->n *= (*stack)->n;
	pop(&*stack, line_number);
}
