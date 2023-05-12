#include "lists.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * new_node - creates node
 * @n: num
 * @next: next
 * Return: return
 */
listint_t *new_node(int n, listint_t *next)
{
	listint_t *new;

	new = malloc(sizeof(listint_t));
	new->n = n;
	new->next = next;
	return (new);
}

/**
 * is_palindrome - check if palindrome
 * @head: head
 * Return: intBool
 */
int is_palindrome(listint_t **head)
{
	listint_t *p, *rev = NULL, *r;
	int i, mid, out = 1;

	p = *head;
	if (!p)
		return (1);
	for (i = 0; p; i++, p = p->next)
		rev = new_node(p->n, rev);
	mid = (i / 2) + (i % 2);
	p = *head, r = rev;
	for (i = 0; r; i++, rev = r)
	{
		if (p->n != r->n && i < mid)
		{
			out = 0;
		}
		p = p->next;
		r = r->next;
		free(rev);
	}
	return (out);
}