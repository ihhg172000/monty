#include "monty.h"

/**
 * stack_mode - sets the format of the data to a stack (LIFO).
 * @stack: a pointer to the stack.
 * @line_number: the line number.
 */
void stack_mode(stack_t **stack, unsigned int line_number)
{
	(void) stack;
	(void) line_number;

	global.queue_mode = false;
}

/**
 * queue_mode - sets the format of the data to a queue (FIFO).
 * @stack: a pointer to the stack.
 * @line_number: the line number.
 */
void queue_mode(stack_t **stack, unsigned int line_number)
{
	(void) stack;
	(void) line_number;

	global.queue_mode = true;
}
