#include "monty.h"

/**
 * push - pushes an element to the stack.
 * @stack: a pointer to the stack.
 * @line_number: the line number.
 */
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new;
	int number;

	if (!is_number(global.tokens[1]))
		exit_with_ferror("L%d: usage: push integer\n", line_number);

	number = atoi(global.tokens[1]);

	new = malloc(sizeof(stack_t));

	if (!new)
		exit_with_ferror("Error: malloc failed");

	new->n = number;
	new->prev = NULL;
	new->next = NULL;

	if (!(*stack))
	{
		*stack = new;
		return;
	}

	(*stack)->prev = new;
	new->next = *stack;
	*stack = new;
}
