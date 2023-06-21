#include "monty.h"

/**
 * exit_with_ferror - exits the program with a formatted error message.
 * @format: the message format.
 */
void exit_with_ferror(char *format, ...)
{
	va_list list;

	va_start(list, format);
	vfprintf(stderr, format, list);
	va_end(list);

	exit(EXIT_FAILURE);
}
