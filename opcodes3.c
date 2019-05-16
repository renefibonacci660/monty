#include "monty.h"

/**
 * opcode_mod - opcode for modulus (%)
 * @stack: pointer to pointer to first node
 * @line_number: number of line
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

/**
 * opcode_pchar - opcode for modulus (%)
 * @stack: pointer to pointer to first node
 * @line_number: number of line
 **/
void opcode_pchar(__attribute__((unused))stack_t **stack,
	__attribute__((unused))unsigned int line_number)
{
	int n;

	if (!get_dnodeint_at_index(*stack, 0))
	{
		dprintf(STDERR_FILENO, ERR_PCHAR, data()->line_number);
		free_data(1);
		exit(EXIT_FAILURE);
	}
	n = peek(stack);
	if (n < 0 || n > 127)
	{
		dprintf(STDERR_FILENO, ERR_NOCHAR, data()->line_number);
		free_data(1);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", n);
}

/**
 * opcode_str - prints str
 * @stack: pointer to pointer to first node
 * @line_number: number of line
 **/
void opcode_pstr(stack_t **stack,
	__attribute__((unused))unsigned int line_number)
{
	stack_t *node = get_dnodeint_at_index(*stack, 0);

	while (node && node->n > 0 && node->n < 128)
	{
		printf("%c", node->n);
		node = node->next;
	}
	printf("\n");
}

/**
 * opcode_rotl - rotates the stack (head) to end
 * @stack: pointer to pointer to first node
 * @line_number: number of line
 **/
void opcode_rotl(stack_t **stack,
	__attribute__((unused))unsigned int line_number)
{
	int n;

	if (!get_dnodeint_at_index(*stack, 1))
		return;

	n = pop(stack);

	add_dnodeint_end(stack, n);
}

/**
 * opcode_rotr - rotates the end of stack to head
 * @stack: pointer to pointer to first node
 * @line_number: number of line
 **/
void opcode_rotr(stack_t **stack,
	__attribute__((unused))unsigned int line_number)
{
	int len = dlistint_len(*stack);
	int n;
	stack_t *node;

	if (len < 2)
		return;

	node = get_dnodeint_at_index(*stack, len - 1);
	n = node->n;
	delete_dnodeint_at_index(stack, len - 1);

	add_dnodeint(stack, n);
}
