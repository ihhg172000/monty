#include "monty.h"

/**
 * rotl -  rotates the stack to the top.
 * @stack: a pointer to the stack.
 * @line_number: the line number.
 */
void rotl(stack_t **stack, __attribute__((unused)) unsigned int line_number)
{
	stack_t *curr, *temp;

	if (!(*stack) || !(*stack)->next)
		return;

	temp = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;

	curr = *stack;

	while (curr->next)
		curr = curr->next;

	curr->next = temp;
	temp->prev = curr;
	temp->next = NULL;
}
