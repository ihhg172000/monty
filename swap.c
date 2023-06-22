#include "monty.h"
/**
 * swap - swaps the top two elements of the stack.
 * @stack: a pointer to the stack.
 * @line_number: the line number.
 */
void swap(stack_t **stack, unsigned int line_number)
{
	int temp;

	if (!*stack || !(*stack)->next)
		exit_with_ferror("L%u: can't swap, stack too short\n", line_number);
	temp = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = temp;
}
