#include "monty.h"

/**
 * opcode_mod - 
 * @stack: pointer to pointer to first node
 * @n: int value to be in added node
 * Return:
 **/
void opcode_mod(__attribute__((unused))stack_t **stack,
	__attribute__((unused))unsigned int line_number)
{
	int n;
	int m;

	if (!get_dnodeint_at_index(*stack, 1))
	{
		dprintf(STDERR_FILENO, ERR_MOD, data()->line_number);
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
	insert_dnodeint_at_index(stack, 0, m % n);
}