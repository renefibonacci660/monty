#include "monty.h"

/**
 * opcode_push - pushes an element to the stack
 * @stack: pointer to pointer to first node
 * @line_number: number of line
 **/
void opcode_push(stack_t **stack,
__attribute__((unused))unsigned int line_number)
{
	if (data()->num_words < 2 || !is_num(data()->words[1]))
	{
		dprintf(STDERR_FILENO, ERR_PUSH, data()->line_number);
		free_data(1);
		exit(EXIT_FAILURE);
		return;
	}

	if (!push(stack, atoi(data()->words[1])))
	{
		dprintf(STDERR_FILENO, ERR_MALLOC);
		free_data(1);
		exit(EXIT_FAILURE);
	}
}

/**
 * opcode_pop - removes the top (ever only) element of the stack
 * @stack: pointer to pointer to first node
 * @line_number: number of line
 **/
void opcode_pop(stack_t **stack,
__attribute__((unused))unsigned int line_number)
{
	if (!get_dnodeint_at_index(*stack, 0))
	{
		dprintf(STDERR_FILENO, ERR_POP, data()->line_number);
		free_data(1);
		exit(EXIT_FAILURE);
	}
	pop(stack);
}

/**
 * opcode_pint - prints top stack value, followed by \n
 * @stack: pointer to pointer to first node
 * @line_number: number of line
 **/
void opcode_pint(stack_t **stack,
__attribute__((unused))unsigned int line_number)
{
	if (!get_dnodeint_at_index(*stack, 0))
	{
		dprintf(STDERR_FILENO, ERR_PINT, data()->line_number);
		free_data(1);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", peek(stack));
}

/**
 * opcode_pall - prints all the values from top down on stack
 * @stack: pointer to pointer to first node
 * @line_number: number of line
 **/
void opcode_pall(stack_t **stack,
__attribute__((unused))unsigned int line_number)
{
	print_dlistint(*stack);
}

/**
 * opcode_pall - pushes and element to the stack (head)
 * @stack: pointer to pointer to first node
 * @line_number: number of line
 **/
void opcode_swap(stack_t **stack,
__attribute__((unused))unsigned int line_number)
{
	int n;

	if (!get_dnodeint_at_index(*stack, 1))
	{
		dprintf(STDERR_FILENO, ERR_SWAP, data()->line_number);
		free_data(1);
		exit(EXIT_FAILURE);
	}
	n = pop(stack);
	insert_dnodeint_at_index(stack, 1, n);
}
