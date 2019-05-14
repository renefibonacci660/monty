#include "lists.h"

/**
 * print_dlistint - prints all the elements of dlistint_t list in 0-main.c
 * @h: pointer to head node of linked list
 * Return: total num of nodes or 0 if nothing
 */
size_t print_dlistint(const dlistint_t *h)
{
	size_t i = 0;

	while (h)
	{
		printf("%d\n", h->n);
		h = h->next;
		i++;
	}
	return (i);
}

/**
 * dlistint_len - counts all the elements in dlistint_t list
 * @h: pointer to head node of linked list
 * Return: Num of nodes in list, 0 if NULL
 */
size_t dlistint_len(const dlistint_t *h)
{
	size_t i = 0;

	while (h)
	{
		h = h->next;
		i++;
	}
	return (i);
}

/**
 * sum_dlistint - returns sum of all data contained in linked list
 * @head: pointer to first node in linked list
 * Return: sum of all elements in linked list or 0 if list is empty
**/
int sum_dlistint(dlistint_t *head)
{
	int sum = 0;

	while (head)
	{
		sum = sum + head->n;
		head = head->next;
	}
	return (sum);
}

/**
 * add_dnodeint_end - Adds new node at the end of linked list
 * @head: pointer to pointer to first node
 * @n: int value to be help in added node
 * Return: address to new node, NULL if failed
 **/

dlistint_t *add_dnodeint_end(dlistint_t **head, const int n)
{
	dlistint_t *newNode;
	dlistint_t *tmp;

	if (!head)
		return (NULL);

	newNode = malloc(sizeof(dlistint_t));

	if (!newNode)
		return (NULL);

	newNode->n = n;

	if (!*head)
	{
		*head = newNode;
		newNode->next = NULL;
		return (newNode);
	}
	tmp = *head;

	while (tmp->next) /** has to loop or won't go to next value **/
		tmp = tmp->next;

	newNode->prev = tmp;
	tmp->next = newNode;
	newNode->next = NULL;
	return (newNode);
}
