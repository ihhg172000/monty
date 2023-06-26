#include "monty.h"

/**
 * rotr -  rotates the stack to the bottom.
 * @stack: a pointer to the stack.
 * @line_number: the line number.
 */
void rotr(stack_t **stack, __attribute__((unused)) unsigned int line_number)
{
	stack_t *curr;

	if (!(*stack) || !(*stack)->next)
		return;

	curr = *stack;

	while (curr->next)
		curr = curr->next;

	curr->prev->next = NULL;
	curr->next = *stack;
	curr->prev = NULL;
	*stack = curr;
}
