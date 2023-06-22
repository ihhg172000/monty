#include "monty.h"

/**
 * _div - divides the second top element of the
 * stack by the top element of the stack.
 *
 * @stack: a pointer to the stack.
 * @line_number: the line number.
 */
void _div(stack_t **stack, unsigned int line_number)
{
	if (!*stack || !(*stack)->next)
		exit_with_ferror("L%u: can't div, stack too short\n", line_number);
	if ((*stack)->n == 0)
		exit_with_ferror("L%u: division by zero\n", line_number);
	(*stack)->next->n /= (*stack)->n;
	pop(&*stack, line_number);
}
