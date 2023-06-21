#include "monty.h"

char **tokens = NULL;

/**
 * main - interpreter for monty bytecode files.
 * @ac: argumnet count.
 * @av: argument vector.
 *
 * Return: EXIT_SUCCESS on success, EXIT_FAILURE on error.
 */
int main(int ac, char **av)
{
	FILE *file;

	if (ac != 2)
		exit_with_ferror("USAGE: monty file\n");

	file = fopen(av[1], "r");

	if (!file)
		exit_with_ferror("Error: Can't open file %s\n", av[1]);

	interpret(file);

	fclose(file);

	return (EXIT_SUCCESS);
}

/**
 * interpret - interprets a monty bytecode file.
 * @file: the file.
 */
void interpret(FILE *file)
{
	char *line = NULL;
	size_t n = 0;
	unsigned int line_number = 0;
	stack_t *stack = NULL;

	while (getline(&line, &n, file) != -1)
	{
		void (*f)(stack_t **stack, unsigned int line_number) = NULL;

		line_number++;
		line_split(line, " \t\n");

		if (tokens[0])
		{
			f = *find_instruction();

			if (f)
				f(&stack, line_number);
			else
				exit_with_ferror("L%d: unknown instruction %s\n",
						line_number,
						tokens[0]);
		}

		free(line);
		line = NULL;
		free(tokens);
		tokens = NULL;
	}

	free(line);
	free_stack(&stack);
}
