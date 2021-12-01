#include "monty.h"

/**
 * pstr_s - will print values from top of stack as ASCII char
 * @l: line to free on error
 * @arg: arg to process into an integer
 * @line: current line number
 * @poi: position somewhere in stack
 *
 * Return: stack mode indicator
 */
char pstr_s(char *l, char *arg, int line, stack_t **poi)
{
	stack_t *chk = NULL;

	(void) l;
	(void) line;
	(void) arg;
	if (poi)
		chk = *poi;
	if (chk)
		while (chk->next != NULL)
			chk = chk->next;
	while (chk != NULL)
	{
		if (chk->n < 1 || chk->n > 127)
			break;
		putchar(chk->n);
		chk = chk->prev;
	}
	putchar('\n');
	return ('s');
}

/**
 * pstr_q - will print values from front of queue ASCII char
 * @l: line to free on error
 * @arg: arg to process into an integer
 * @line: current line number
 * @poi: position somewhere in stack
 *
 * Return: stack mode indicator
 */
char pstr_q(char *l, char *arg, int line, stack_t **poi)
{
	stack_t *chk = NULL;

	(void) l;
	(void) line;
	(void) arg;
	if (poi)
		chk = *poi;
	if (chk)
		while (chk->prev != NULL)
			chk = chk->prev;
	while (chk != NULL)
	{
		if (chk->n < 1 || chk->n > 127)
			break;
		putchar(chk->n);
		chk = chk->next;
	}
	putchar('\n');
	return ('q');
}

/**
 * rotl_s - will rotate stack
 * @l: line to free on error
 * @arg: arg to process into an integer
 * @line: current line number
 * @poi: position somewhere in stack
 *
 * Return: stack mode indicator
 */
char rotl_s(char *l, char *arg, int line, stack_t **poi)
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
	while (tar->next)
		tar = tar->next;
	while (des->prev)
		des = des->prev;
	tar->prev->next = NULL;
	tar->prev = NULL;
	des->prev = tar;
	tar->next = des;

	return ('s');
}

/**
 * rotl_q - will rotate queue
 * @l: line to free on error
 * @arg: arg to process into an integer
 * @line: current line number
 * @poi: position somewhere in stack
 *
 * Return: stack mode indicator
 */
char rotl_q(char *l, char *arg, int line, stack_t **poi)
{
	stack_t *tar = NULL;
	stack_t *des = NULL;

	(void) l;
	(void) arg;
	(void) line;

	if (poi == NULL)
		return ('q');
	if (*poi == NULL)
		return ('q');
	tar = *poi, des = *poi;
	if (tar->next == NULL && tar->prev == NULL)
		return ('q');
	while (tar->prev)
		tar = tar->prev;
	while (des->next)
		des = des->next;
	tar->next->prev = NULL;
	tar->next = NULL;
	des->next = tar;
	tar->prev = des;

	return ('q');
}
