#include "monty.h"

/**
 * opcode_nop - opcode for nop
 * @stack: pointer to pointer to first node
 * @line_number: number of line
 **/
void opcode_nop(__attribute__((unused))stack_t **stack,
	__attribute__((unused))unsigned int line_number)
{

}

/**
 * opcode_add - opcode for additon (+)
 * @stack: pointer to pointer to first node
 * @line_number: number of line
 **/
void opcode_add(__attribute__((unused))stack_t **stack,
	__attribute__((unused))unsigned int line_number)
{
	int n;
	int m;

	if (!get_dnodeint_at_index(*stack, 1))
	{
		dprintf(STDERR_FILENO, ERR_ADD, data()->line_number);
		free_data(1);
		exit(EXIT_FAILURE);
	}
	n = pop(stack);
	m = pop(stack);
	insert_dnodeint_at_index(stack, 0, n + m);
}

/**
 * opcode_sub - opcode for subtraction (-)
 * @stack: pointer to pointer to first node
 * @line_number: number of line
 **/
void opcode_sub(__attribute__((unused))stack_t **stack,
	__attribute__((unused))unsigned int line_number)
{
	int n;
	int m;

	if (!get_dnodeint_at_index(*stack, 1))
	{
		dprintf(STDERR_FILENO, ERR_SUB, data()->line_number);
		free_data(1);
		exit(EXIT_FAILURE);
	}
	n = pop(stack);
	m = pop(stack);
	insert_dnodeint_at_index(stack, 0, m - n);
}

/**
 * opcode_div - opcode for division (/)
 * @stack: pointer to pointer to first node
 * @line_number: number of line
 **/
void opcode_div(__attribute__((unused))stack_t **stack,
	__attribute__((unused))unsigned int line_number)
{
	int n;
	int m;

	if (!get_dnodeint_at_index(*stack, 1))
	{
		dprintf(STDERR_FILENO, ERR_DIV, data()->line_number);
		free_data(1);
		exit(EXIT_FAILURE);
	}
	n = pop(stack);
	m = pop(stack);
	if (!n)
	{
		dprintf(STDERR_FILENO, ERR_ZERO, data()->line_number);
		free_data(1);
		exit(EXIT_FAILURE);
	}
	insert_dnodeint_at_index(stack, 0, m / n);
}

/**
 * opcode_mul - opcode for multiplication (*)
 * @stack: pointer to pointer to first node
 * @line_number: number of line
 **/
void opcode_mul(__attribute__((unused))stack_t **stack,
	__attribute__((unused))unsigned int line_number)
{
	int n;
	int m;

	if (!get_dnodeint_at_index(*stack, 1))
	{
		dprintf(STDERR_FILENO, ERR_MUL, data()->line_number);
		free_data(1);
		exit(EXIT_FAILURE);
	}
	n = pop(stack);
	m = pop(stack);
	insert_dnodeint_at_index(stack, 0, m * n);
}
