#include "monty.h"
/**
 * add - adds the top two elements of the stack.
 * @stack: a pointer to the stack.
 * @line_number: the line number.
 */
void add(stack_t **stack, unsigned int line_number)
{
	if (!*stack || !(*stack)->next)
		exit_with_ferror("L%u: can't add, stack too short\n", line_number);
	(*stack)->next->n += (*stack)->n;
	pop(&*stack, line_number);
}
