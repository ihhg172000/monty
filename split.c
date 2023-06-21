#include "monty.h"

/**
 * line_split - splits line into tokens.
 * @line: the line.
 * @delim: a set of bytes that delimits the tokens.
 */
void line_split(char *line, char *delim)
{
	int i = 0;

	global.tokens = malloc(sizeof(char *));

	if (!(global.tokens))
		exit_with_ferror("Error: malloc failed\n");

	global.tokens[0] = strtok(line, delim);

	do {
		i++;
		global.tokens = realloc(global.tokens, (i + 1) * sizeof(char *));

		if (!(global.tokens))
			exit_with_ferror("Error: malloc failed\n");

		global.tokens[i] = strtok(NULL, delim);
	} while (global.tokens[i] != NULL);
}
