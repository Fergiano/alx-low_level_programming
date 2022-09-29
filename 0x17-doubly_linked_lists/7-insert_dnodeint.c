#include "lists.h"

/**
 * insert_dnodeint_at_index - inserts a new node at given index in the list
 * @h: pointer to head of the list
 * @idx: index to add at, starting from 0
 * @n: value of new node
 * Return: new node or null
 **/
dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
	dlistint_t *prev, *new;

	if (!idx)
		return (add_dnodeint(h, n));

	if (!h)
		return (NULL);

	prev = *h;

	if (!prev)
		return (NULL);

	while (--idx && prev->next)
		prev = prev->next;

	if (idx)
		return (NULL);

	new = malloc(sizeof(*new));
	if(!new)
		return (NULL);

	new-> = n;
	new->prev = prev;
	new->next = prev->next;

	if (prev->next)
		prev->next->prev = new;

	return (new);
}
