#include "monty.h"

/**
 * pchar -  prints the char at the top of the stack,
 * followed by a new line.
 *
 * @stack: a pointer to the stack.
 * @line_number: the line number.
 */
void pchar(stack_t **stack, unsigned int line_number)
{
	if (!*stack)
		exit_with_ferror("L%u: can't pchar, stack empty\n", line_number);
	if ((*stack)->n >= 0 && (*stack)->n <= 127)
		printf("%c\n", (*stack)->n);
	else
		exit_with_ferror("L%u: can't pchar, value out of range\n", line_number);
}
