#include "monty.h"

/**
 * opcode_stack - sets list to stack mode
 * @stack: pointer to pointer to first node
 * @line_number: number of line
 **/
void opcode_stack(__attribute__((unused))stack_t **stack,
	__attribute__((unused))unsigned int line_number)
{
	data()->queue_mode = 0;
}

/**
 * opcode_queue - sets list to queue mode
 * @stack: pointer to pointer to first node
 * @line_number: number of line
 **/
void opcode_queue(__attribute__((unused))stack_t **stack,
	__attribute__((unused))unsigned int line_number)
{
	data()->queue_mode = 1;
}
