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
	stack_t *chk = NULL;

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
	stack_t *chk = NULL;

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

/**
 * pchar_s - will print value at top of stack as ASCII char
 * @l: line to free on error
 * @arg: arg to process into an integer
 * @line: current line number
 * @poi: position somewhere in stack
 *
 * Return: stack mode indicator
 */
char pchar_s(char *l, char *arg, int line, stack_t **poi)
{
	stack_t *chk = NULL;

	(void) arg;
	if (poi)
		chk = *poi;
	if (chk == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line);
		free(l);
		if (poi)
			breakdown(*poi, 's', EXIT_FAILURE);
		else
			breakdown(NULL, 's', EXIT_FAILURE);
	}
	while (chk->next != NULL)
		chk = chk->next;
	if (chk->n < 0 || chk->n > 127)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line);
		free(l);
		breakdown(*poi, 's', EXIT_FAILURE);
	}
	putchar(chk->n);
	putchar('\n');
	return ('s');
}

/**
 * pchar_q - will print value at front of queue as ASCII char
 * @l: line to free on error
 * @arg: arg to process into an integer
 * @line: current line number
 * @poi: position somewhere in stack
 *
 * Return: stack mode indicator
 */
char pchar_q(char *l, char *arg, int line, stack_t **poi)
{
	stack_t *chk = NULL;

	(void) arg;
	if (poi)
		chk = *poi;
	if (chk == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line);
		free(l);
		if (poi)
			breakdown(*poi, 'q', EXIT_FAILURE);
		else
			breakdown(NULL, 'q', EXIT_FAILURE);
	}
	while (chk->prev != NULL)
		chk = chk->prev;
	if (chk->n < 0 || chk->n > 127)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line);
		free(l);
		breakdown(*poi, 'q', EXIT_FAILURE);
	}

	putchar(chk->n);
	putchar('\n');
	return ('q');
}

/**
 * rotr_s - will rotate stack to bottom
 * @l: line to free on error
 * @arg: arg to process into an integer
 * @line: current line number
 * @poi: position somewhere in stack
 *
 * Return: stack mode indicator
 */
char rotr_s(char *l, char *arg, int line, stack_t **poi)
{
	stack_t *tar = NULL;
	stack_t *des = NULL;

	(void) l;
	(void) arg;
	(void) line;

	if (poi == NULL)
		return ('s');
	if (*poi == NULL)
		return ('s');
	tar = *poi, des = *poi;
	if (tar->next == NULL && tar->prev == NULL)
		return ('s');
	while (tar->prev)
		tar = tar->prev;
	while (des->next)
		des = des->next;
	tar->next->prev = NULL;
	tar->next = NULL;
	des->next = tar;
	tar->prev = des;

	return ('s');
}
