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
	stack_t *top = *stack;

	if (!top)
		exit_with_ferror("L%u: can't pchar, stack empty\n", line_number);
	if (top->n >= 0 && top->n <= 127)
		printf("%c\n", top->n);
	else
		exit_with_ferror("L%u: can't pchar, value out of range\n", line_number);
}
