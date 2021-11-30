#include "monty.h"

/**
 * pall_s  - Will print entire stack
 * @l: line to free on error
 * @arg: arg to process into an integer
 * @line: current line number
 * @poi: position somewhere in stack
 *
 * Return: current mode
 */
char pall_s(char *l, char *arg, int line, stack_t **poi)
{
	stack_t *top = NULL;

	(void) l;
	(void) arg;
	(void) line;
	if (poi)
		top = *poi;
	if (top)
	{
		while (top->next != NULL)
			top = top->next;
		*poi = top;
		while (top)
		{
			printf("%d\n", top->n);
			top = top->prev;
		}
	}
	return ('s');
}

/**
 * pall_q - Will print entire queue
 * @l: line to free on error
 * @arg: arg to process into an integer
 * @line: current line number
 * @poi: position somewhere in stack
 *
 * Return: current mode
 */
char pall_q(char *l, char *arg, int line, stack_t **poi)
{
	stack_t *front = NULL;

	(void) l;
	(void) arg;
	(void) line;
	if (poi)
		front = *poi;
	if (front)
	{
		while (front->prev != NULL)
			front = front->prev;
		*poi = front;
		while (front)
		{
			printf("%d\n", front->n);
			front = front->next;
		}
	}
	return ('q');
}
