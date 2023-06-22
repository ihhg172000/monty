#ifndef MONTY_H
#define MONTY_H

#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

void init_global(void);

void line_split(char *line, char *delim);
void (*find_instruction())(stack_t **stack, unsigned int line_number);

void interpret(void);

void push(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);
void pint(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);
void swap(stack_t **stack, unsigned int line_number);

void free_stack(stack_t **stack);

void exit_with_ferror(char *format, ...);

int is_number(char *str);

/**
 * struct global_s - _
 * @file: _
 * @line: _
 * @n: _
 * @tokens: _
 * @stack: _
 */
typedef struct global_s
{
	FILE *file;
	char *line;
	size_t n;
	char **tokens;
	stack_t *stack;
} global_t;

extern global_t global;

#endif
