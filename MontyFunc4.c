#include "monty.h"

/**
 * sub_s - will subtract top two members of stack, result in second from top
 * @l: line to free on error
 * @arg: arg to process into an integer
 * @line: current line number
 * @poi: position somewhere in stack
 *
 * Return: stack mode indicator
 */
char sub_s(char *l, char *arg, int line, stack_t **poi)
{
	int buf;
	stack_t *chk = NULL;

	(void) arg;
	if (poi)
		chk = *poi;
	if (chk == NULL || (chk->prev == NULL && chk->next == NULL))
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line);
		free(l);
		if (poi)
			breakdown(*poi, 's', EXIT_FAILURE);
		else
			breakdown(NULL, 's', EXIT_FAILURE);
	}
	buf = rm_tl(poi, NULL);
	chk = *poi;
	chk->n -= buf;

	return ('s');
}

/**
 * div_s - will add top two members of stack, result in second from top
 * @l: line to free on error
 * @arg: arg to process into an integer
 * @line: current line number
 * @poi: position somewhere in stack
 *
 * Return: stack mode indicator
 */
char div_s(char *l, char *arg, int line, stack_t **poi)
{
	int buf;
	stack_t *chk = NULL;

	(void) arg;
	if (poi)
		chk = *poi;
	if (chk == NULL || (chk->prev == NULL && chk->next == NULL))
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line);
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
	chk->n /= buf;

	return ('s');
}

