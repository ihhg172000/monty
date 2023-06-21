#include "monty.h"

/**
 * pint - prints the value at the top of the stack.
 * @stack: a pointer to the stack.
 * @line_number: the line number.
 */
void pint(stack_t **stack, unsigned int line_number)
{
	if (!(*stack))
		exit_with_ferror("L%d: can't pint, stack empty\n", line_number);

	printf("%d\n", (*stack)->n);
}
