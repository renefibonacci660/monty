#include "monty.h"

/**
 * push - pushes node to stack (head)
 * @head: pointer to pointer to first node
 * @n: int value to be in added node
 * Return: 1 is added 0 otherwise
 **/
int push(stack_t **head, int n)
{
	if (data()->queue_mode)
		return (!!add_dnodeint_end(head, n));
	/* !!(x) converts any data type x into a boolean appropriately */
	return (!!add_dnodeint(head, n));
}

/**
 * pop - pops node from stack (head)
 * @head: pointer to pointer to first node
 * Return: n
 **/
int pop(stack_t **head)
{
	stack_t *node = get_dnodeint_at_index(*head, 0);
	int n = 0;

	n = node->n;
	delete_dnodeint_at_index(head, 0);
	return (n);
}

/**
 * peek - gets node at stack(head)
 * @head: pointer to pointer to first node
 * Return: node or Failure unreachable
 **/
int peek(stack_t **head)
{
	stack_t *node = get_dnodeint_at_index(*head, 0);

	if (node)
		return (node->n);
	return (FAILURE);
}

/**
 * is_empty - called if empty for correct return
 * @head: pointer to pointer to first node
 * Return: head index (of zero)
 **/
int is_empty(stack_t **head)
{
	return (!get_dnodeint_at_index(*head, 0));
}

/**
 * pall - prints all the values on the stack (starting with head)
 * @head: pointer to first node
 **/
void pall(stack_t *head)
{
	print_dlistint(head);
}
