#include "monty.h"

/**
 * add_to_start -  adds node to start of linked list.
 * @stack: a pointer to the stack.
 * @new: the new node.
 */
void add_to_start(stack_t **stack, stack_t *new)
{
	if (!(*stack))
	{
		*stack = new;
		return;
	}

	(*stack)->prev = new;
	new->next = *stack;
	*stack = new;
}

/**
 * add_to_end - adds node to the end of linked list.
 * @stack: a pointer to the stack.
 * @new: the new node.
 */
void add_to_end(stack_t **stack, stack_t *new)
{
	stack_t *curr;

	if (!(*stack))
	{
		*stack = new;
		return;
	}

	curr = *stack;

	while (curr->next)
		curr = curr->next;

	curr->next = new;
	new->prev = curr;
}

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

	if (global.queue_mode)
	{
		add_to_end(stack, new);
	}
	else
	{
		add_to_start(stack, new);
	}
}
