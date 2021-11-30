#include "Monty.h"

/**
 * create_node - Will create an empty node at the top/front of current stack
 * @poi: current position in stack, NULL is there is no stack
 * @mode: current mode
 * @line: line to free on error
 *
 * Return: newly created node
 */
stack_t *create_node(stack_t **poi, char mode, char *line)
{
	stack_t *spear, *newn;

	newn = malloc(sizeof(stack_t));
	if (newn == NULL)
		mal_error(poi, mode, line);
	newn->next = NULL;
	newn->prev = NULL;

	if (*poi == NULL)
	{
		*poi = newn;
		return (newn);
	}
	spear = *poi;
	while (spear->next)
		spear = spear->next;
	spear->next = newn;
	newn->prev = spear;
	return (newn);
}
