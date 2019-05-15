#include "lists.h"

/**
 * add_dnodeint - Adds new node at beginning of linked list
 * @head: pointer to pointer to first node
 * @n: int value to be help in added node
 * Return: address to new node, NULL if failed
 **/
dlistint_t *add_dnodeint(dlistint_t **head, const int n)
{
	dlistint_t *newNode;
	dlistint_t *tmp;

	if (!head)
		return (NULL);

	tmp = *head;
	newNode = malloc(sizeof(dlistint_t));

	if (!newNode)
		return (NULL);

	newNode->n = n;

	if (!*head)
	{
		*head = newNode;
		newNode->prev = NULL;
		newNode->next = NULL;
		return (newNode);
	}

	tmp->prev = newNode;
	newNode->prev = NULL;
	newNode->next = tmp;
	*head = newNode;
	return (newNode);
}

/**
 * insert_dnodeint_at_index - inserts node at given index
 * @h: address of pointer to current head node
 * @idx: the index to at which to insert
 * @n: the value of the inserted node
 *
 * Return: new node or NULL
 */
dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
	dlistint_t *new = malloc(sizeof(dlistint_t)), *node;

	if (!h || !new)
		return (new ? free(new), NULL : NULL);
	node = *h;
	new->n = n;
	if (!idx)
	{
		new->prev = NULL;
		new->next = node ? node : NULL;
		if (node)
			node->prev = new;
		return (*h = new);
	}
	for (; node; node = node->next, idx--)
	{
		if (idx - 1 == 0)
		{
			new->prev = node;
			new->next = node->next;
			if (new->next)
				new->next->prev = new;
			node->next = new;
			return (new);
		}
	}
	return (free(new), NULL);
}

/**
 * get_dnodeint_at_index - gets node from specific index declared in 5-main.c
 * @head: pointer to first node of linked list
 * @index: index of requested node
 * Return: node at specified index or NULL if failed
**/
dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
	size_t i = 0;

	while (head && i < index)
	{
		head = head->next;
		i++;
	}
	return (head);
}

/**
 * delete_dnodeint_at_index - deletes node at given index
 * @head: address of pointer to current head node
 * @index: the index to at which to insert
 *
 * Return: 1 on success or -1 on failure
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *node, *temp;

	if (!head)
		return (-1);
	node = *head;
	if (!index)
	{
		if (!node)
			return (-1);
		*head = node->next;
		if (*head)
			(*head)->prev = NULL;
		free(node);
		return (1);
	}
	for (; node; node = node->next, index--)
	{
		if (index - 1 == 0)
		{
			temp = node->next;
			if (!temp)
				break;
			node->next = temp->next;
			if (temp->next)
				temp->next->prev = node;
			free(temp);
			return (1);
		}
	}
	return (-1);
}

/**
 * free_dlistint - frees doubly linked list
 * @head: pointer to the first node of linked list
**/
void free_dlistint(dlistint_t *head)
{
	while (head->next)
	{
		head = head->next;
		free(head->prev);
	}

	free(head);
}
