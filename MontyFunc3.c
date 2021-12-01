#include "monty.h"

/**
 * swap_s - will swap top two members of stack
 * @l: line to free on error
 * @arg: arg to process into an integer
 * @line: current line number
 * @poi: position somewhere in stack
 *
 * Return: stack mode indicator
 */
char swap_s(char *l, char *arg, int line, stack_t **poi)
{
	stack_t *fir = NULL, *sec = NULL;
	int buf;

	(void) arg;

	if (poi)
		fir = *poi;
	while (fir && fir->next != NULL)
		fir = fir->next;
	if (fir && fir->prev)
	{
		sec = fir->prev;
		buf = sec->n;
		sec->n = fir->n;
		fir->n = buf;
		return ('s');
	}
	fprintf(stderr, "L%d: can't swap, stack too short\n", line);
	free(l);
	if (poi)
		breakdown(*poi, 's', EXIT_FAILURE);
	else
		breakdown(NULL, 's', EXIT_FAILURE);
	return ('s');
}
/**
 * add_s - will add top two members of stack, result in second from top
 * @l: line to free on error
 * @arg: arg to process into an integer
 * @line: current line number
 * @poi: position somewhere in stack
 *
 * Return: stack mode indicator
 */
char add_s(char *l, char *arg, int line, stack_t **poi)
{
	int buf;
	stack_t *chk = NULL;

	(void) arg;
	if (poi)
		chk = *poi;
	if (chk == NULL || (chk->prev == NULL && chk->next == NULL))
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line);
		free(l);
		if (poi)
			breakdown(*poi, 's', EXIT_FAILURE);
		else
			breakdown(NULL, 's', EXIT_FAILURE);
	}
	buf = rm_tl(poi, NULL);
	chk = *poi;
	chk->n += buf;

	return ('s');
}

/**
 * mod_s - will add top two members of stack, result in second from top
 * @l: line to free on error
 * @arg: arg to process into an integer
 * @line: current line number
 * @poi: position somewhere in stack
 *
 * Return: stack mode indicator
 */
char mod_s(char *l, char *arg, int line, stack_t **poi)
{
	int buf;
	stack_t *chk = NULL;

	(void) arg;
	if (poi)
		chk = *poi;
	if (chk == NULL || (chk->prev == NULL && chk->next == NULL))
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line);
		free(l);
		if (poi)
			breakdown(*poi, 's', EXIT_FAILURE);
		else
			breakdown(NULL, 's', EXIT_FAILURE);
	}
	while (chk->next != NULL)
		chk = chk->next;
	if (chk->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line);
		free(l);
		breakdown(*poi, 's', EXIT_FAILURE);
	}
	buf = rm_tl(poi, NULL);
	chk = *poi;
	chk->n %= buf;

	return ('s');
}
