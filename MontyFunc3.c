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
 * swap_q - will swap first two members of queue
 * @l: line to free on error
 * @arg: arg to process into an integer
 * @line: current line number
 * @poi: position somewhere in stack
 *
 * Return: stack mode indicator
 */
char swap_q(char *l, char *arg, int line, stack_t **poi)
{
	stack_t *fir = NULL, *sec = NULL;
	int buf = 0;

	(void) arg;

	if (poi)
		fir = *poi;
	while (fir && fir->prev != NULL)
		fir = fir->prev;
	if (fir && fir->next)
	{
		sec = fir->next;
		buf = sec->n;
		sec->n = fir->n;
		fir->n = buf;
		return ('q');
	}
	fprintf(stderr, "L%d: can't swap, stack too short\n", line);
	free(l);
	if (poi)
		breakdown(*poi, 'q', EXIT_FAILURE);
	else
		breakdown(NULL, 'q', EXIT_FAILURE);
	return ('q');
}
