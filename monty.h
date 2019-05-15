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
#define ERR_FILE "Error: Can't open file %s\n"
#define ERR_OPCODE "L%d: unknown instruction %s\n"
#define ERR_MALLOC "Error: malloc failed\n"
#define ERR_PINT "L%d: can't pint, stack empty\n"
#define ERR_PUSH "L%d: usage: push integer\n"
#define ERR_POP "L%d: can't pop an empty stack\n"
#define ERR_SWAP "L%d: can't swap, stack too short\n"
#define ERR_ADD "L%d: can't add, stack too short\n"
#define ERR_SUB "L%d: can't sub, stack too short\n"
#define ERR_DIV "L%d: can't div, stack too short\n"
#define ERR_MUL "L%d: can't mul, stack too short\n"

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
	FILE *fp;
	stack_t *stack;
	unsigned int line_number;
	char **words;
	int num_words;
	char *line;
} data_t;

#define INIT_DATA {NULL, NULL, 1, NULL, 0, NULL}

#include "lists.h"

/* interpreter.c */
int interpret(int ac, char **av);
void parse_opcodes();
int exec_opcode(char *word);

/* stack.c */
int push(stack_t **head, int n);
int pop(stack_t **head);
int peek(stack_t **head);
int is_empty(stack_t **head);
void pall(stack_t *head);

/* data.c */
data_t *data(void);
void free_data(int all);

/* token.c */
char **strtow(char *str, char *d);
int is_delim(char c, char *delim);
void ffree(char **pp);
int is_num(char *str);

/* opcodes1.c */
void opcode_push(stack_t **stack, unsigned int line_number);
void opcode_pop(stack_t **stack, unsigned int line_number);
void opcode_pint(stack_t **stack, unsigned int line_number);
void opcode_pall(stack_t **stack, unsigned int line_number);
void opcode_swap(stack_t **stack, unsigned int line_number);

/* opcodes2.c */
void opcode_nop(__attribute__((unused))stack_t **stack,
	__attribute__((unused))unsigned int line_number);
void opcode_add(__attribute__((unused))stack_t **stack,
	__attribute__((unused))unsigned int line_number);
void opcode_sub(__attribute__((unused))stack_t **stack,
	__attribute__((unused))unsigned int line_number);
void opcode_div(__attribute__((unused))stack_t **stack,
	__attribute__((unused))unsigned int line_number);
void opcode_mul(__attribute__((unused))stack_t **stack,
	__attribute__((unused))unsigned int line_number);

#endif