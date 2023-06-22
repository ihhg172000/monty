#include "monty.h"

/**
 * find_instruction - finds the opcode.
 *
 * Return: a pointer to opcode function.
 */
void (*find_instruction())(stack_t **stack, unsigned int line_number)
{
	int i;
	instruction_t instructions[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{NULL, NULL}
	};

	for (i = 0; instructions[i].opcode; i++)
	{
		if (!strcmp(global.tokens[0], instructions[i].opcode))
			return (instructions[i].f);
	}

	return (NULL);
}
