#include "monty.h"

/**
 * main - interpreter for monty bytecodes files.
 * @ac: argumnet count.
 * @av: argument vector.
 *
 * Return: EXIT_SUCCESS on success, EXIT_FAILURE on error.
 */
int main(int ac, char **av)
{
	FILE *file;
	char *line = NULL;
	size_t n = 0;
	unsigned int line_number = 0;
	/* stack_t **stack; */

	if (ac != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	file = fopen(av[1], "r");

	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", av[1]);
		exit(EXIT_FAILURE);
	}

	while (getline(&line, &n, file) != -1)
	{
		line_number++;

		/* handle opcode here */

		/* next line just for testing */
		printf("%d: %s", line_number, line);

		free(line);
		line = NULL;
	}

	free(line);
	fclose(file);

	return (EXIT_SUCCESS);
}
