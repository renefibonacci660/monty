#ifndef _LISTS
#define _LISTS

#include "monty.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef stack_t dlistint_t;

/* dlist1.c */
size_t print_dlistint(const dlistint_t *h);
size_t dlistint_len(const dlistint_t *h);
int sum_dlistint(dlistint_t *head);
dlistint_t *add_dnodeint_end(dlistint_t **head, const int n);

/* dlist2.c */
dlistint_t *add_dnodeint(dlistint_t **head, const int n);
dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n);
dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index);
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index);
void free_dlistint(dlistint_t *head);

#endif
