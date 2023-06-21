#include "monty.h"

/**
 * line_split - splits line into tokens.
 * @line: the line.
 * @delim: a set of bytes that delimits the tokens.
 */
void line_split(char *line, char *delim)
{
	int i = 0;

	tokens = malloc(sizeof(char *));

	if (!tokens)
		exit_with_ferror("Error: malloc failed\n");

	tokens[0] = strtok(line, delim);

	do {
		i++;
		tokens = realloc(tokens, (i + 1) * sizeof(char *));

		if (!tokens)
			exit_with_ferror("Error: malloc failed\n");

		tokens[i] = strtok(NULL, delim);
	} while (tokens[i] != NULL);
}
