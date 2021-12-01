#include "monty.h"

/**
 * create_node_s - Will create an empty node at the top of current stack
 * @poi: current position in stack, NULL is there is no stack
 * @mode: current mode
 * @line: line to free on error
 *
 * Return: newly created node
 */
stack_t *create_node_s(stack_t **poi, char mode, char *line)
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

/**
 * create_node_q - Will create an empty node at the back of current queue
 * @poi: current position in stack, NULL is there is no stack
 * @mode: current mode
 * @line: line to free on error
 *
 * Return: newly created node
 */
stack_t *create_node_q(stack_t **poi, char mode, char *line)
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
	while (spear->prev)
		spear = spear->prev;
	spear->prev = newn;
	newn->next = spear;
	return (newn);
}

/**
 * rm_tl - will remove tail/top of stack
 * @poi: position within stack
 * @s: err status. set to 1 on error
 *
 * Return: value held by top
 */
int rm_tl(stack_t **poi, char *s)
{
	stack_t *tar = NULL;
	int res;

	if (poi != NULL)
		tar = *poi;
	if (tar == NULL)
	{
		if (s)
			*s += 1;
		return (0);
	}
	while (tar->next != NULL)
		tar = tar->next;
	*poi = tar->prev;
	if (tar->prev)
		tar->prev->next = NULL;
	res = tar->n;
	free(tar);

	return (res);
}

/**
 * rm_hd - will remove head/front of queue
 * @poi: point within queue
 * @s: err status, set to 1 on error
 *
 * Return: value held by front
 */
int rm_hd(stack_t **poi, char *s)
{
	stack_t *tar = NULL;
	int res;

	if (poi != NULL)
		tar = *poi;
	if (tar == NULL)
	{
		if (s)
			*s += 1;
		return (0);
	}
	while (tar->prev != NULL)
		tar = tar->prev;
	*poi = tar->next;
	if (tar->next)
		tar->next->prev = NULL;
	res = tar->n;
	free(tar);

	return (res);
}

