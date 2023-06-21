#include "monty.h"

/**
 * is_number - checks if a string contains only number.
 * @str: the string.
 *
 * Return: 1 if its only number, 0 otherwise.
 */
int is_number(char *str)
{
	if (!str)
		return (0);

	if (*str == '-')
		str++;

	while (*str)
	{
		if (*str < '0' || *str > '9')
			return (0);

		str++;
	}

	return (1);
}
