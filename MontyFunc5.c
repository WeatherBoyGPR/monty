#include "monty.h"

/**
 * mul_s - will multiply top two members of stack, result in second from top
 * @l: line to free on error
 * @arg: arg to process into an integer
 * @line: current line number
 * @poi: position somewhere in stack
 *
 * Return: stack mode indicator
 */
char mul_s(char *l, char *arg, int line, stack_t **poi)
{
	int buf;
	stack_t *chk;

	(void) arg;
	if (poi)
		chk = *poi;
	if (chk == NULL || (chk->prev == NULL && chk->next == NULL))
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line);
		free(l);
		if (poi)
			breakdown(*poi, 's', EXIT_FAILURE);
		else
			breakdown(NULL, 's', EXIT_FAILURE);
	}
	buf = rm_tl(poi, NULL);
	chk = *poi;
	chk->n *= buf;

	return ('s');
}

/**
 * mul_q - will multiply first two members of queue, result in second first
 * @l: line to free on error
 * @arg: arg to process into an integer
 * @line: current line number
 * @poi: position somewhere in stack
 *
 * Return: stack mode indicator
 */
char mul_q(char *l, char *arg, int line, stack_t **poi)
{
	int buf;
	stack_t *chk;

	(void) arg;
	if (poi)
		chk = *poi;
	if (chk == NULL || (chk->prev == NULL && chk->next == NULL))
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line);
		free(l);
		if (poi)
			breakdown(*poi, 'q', EXIT_FAILURE);
		else
			breakdown(NULL, 'q', EXIT_FAILURE);
	}
	buf = rm_hd(poi, NULL);
	chk = *poi;
	chk->n *= buf;

	return ('q');
}

