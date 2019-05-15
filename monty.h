#ifndef __MONTY__H
#define __MONTY__H

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdarg.h>
#include <errno.h>

#define FAILURE 0
#define USAGE "USAGE: monty file\n"
#define ERR_SWAP "L<%d>: can't swap, stack too short\n"
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
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
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
		char *opcode;
		void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct data - paramater pattern
 * @file_ptr: file_ptr to opened file
 *
 * Description: parameter pattern
 */
typedef struct data
{
	FILE *file_ptr;
	stack_t *stack;
	unsigned int line_number;
	char **words;
	int num_words;
} data_t;

#define INIT_DATA {NULL, NULL, 1, NULL, 0}

extern data_t data;

#include "lists.h"


/* stack.c */
int push(stack_t **head, int n);
int pop(stack_t **head);
int peek(stack_t **head);
int is_empty(stack_t **head);
void pall(stack_t *head);

/* token.c */
char **strtow(char *str, char *d);
int is_delim(char c, char *delim);
void ffree(char **pp);

/* opcodes1.c */
void opcode_push(stack_t **stack, unsigned int line_number);
void opcode_pop(stack_t **stack, unsigned int line_number);
void opcode_pint(stack_t **stack, unsigned int line_number);
void opcode_pall(stack_t **stack, unsigned int line_number);
void opcode_swap(stack_t **stack, unsigned int line_number);

/* opcodes1.c */
void opcode_nop(__attribute__((unused))stack_t **stack,
	__attribute__((unused))unsigned int line_number);

#endif