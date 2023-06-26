#include "monty.h"

global_t global;

/**
 * main - interpreter for monty bytecode files.
 * @ac: argumnet count.
 * @av: argument vector.
 *
 * Return: EXIT_SUCCESS on success, EXIT_FAILURE on error.
 */
int main(int ac, char **av)
{
	init_global();

	if (ac != 2)
		exit_with_ferror("USAGE: monty file\n");

	global.file = fopen(av[1], "r");

	if (!(global.file))
		exit_with_ferror("Error: Can't open file %s\n", av[1]);

	interpret();

	fclose(global.file);

	return (EXIT_SUCCESS);
}

/**
* init_global - initializes global variable.
*/
void init_global(void)
{
	global.file = NULL;
	global.line = NULL;
	global.n = 0;
	global.tokens = NULL;
	global.stack = NULL;
	global.queue_mode = false;
}

/**
 * interpret - interprets a monty bytecode file.
 */
void interpret(void)
{
	unsigned int line_number = 0;

	while (getline(&(global.line), &(global.n), global.file) != -1)
	{
		void (*f)(stack_t **stack, unsigned int line_number) = NULL;

		line_number++;
		line_split(global.line, " \t\n");

		if (global.tokens[0] && global.tokens[0][0] != '#')
		{
			f = *find_instruction();

			if (f)
				f(&(global.stack), line_number);
			else
				exit_with_ferror("L%d: unknown instruction %s\n",
						line_number,
						global.tokens[0]);
		}

		free(global.line);
		global.line = NULL;
		free(global.tokens);
		global.tokens = NULL;
	}

	free(global.line);
	free_stack(&(global.stack));
}
