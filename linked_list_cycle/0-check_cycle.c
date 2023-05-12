#include "lists.h"

/**
 * check_cycle - checks for cycle
 * @list: list
 * Return: int
 */
int check_cycle(listint_t *list)
{
	listint_t *t, *h;
	int first = 0;

	t = list, h = list;
	for (; t && h; t = t->next, h = h->next)
	{
		if (first && (h == t))
			return (1);
		first = 1;
		h = h->next;
		if (!h)
			break;
	}
	return (0);
}
