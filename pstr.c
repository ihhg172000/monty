#include "monty.h"

/**
 * pstr -  prints the string starting at the top of the stack.
 * @stack: a pointer to the stack.
 * @line_number: the line number.
 */
void pstr(stack_t **stack, __attribute__((unused)) unsigned int line_number)
{
	stack_t *temp = *stack;

	while (temp && temp->n != 0 && (temp->n >= 0 && temp->n <= 127))
	{
		printf("%c", temp->n);
		temp = temp->next;
	}

	printf("\n");
}
