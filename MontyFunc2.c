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
 * pint_s - will print top of stack
 * @l: line to free on error
 * @arg: arg to process into an integer
 * @line: current line number
 * @poi: position somewhere in stack
 *
 * Return: current mode
 */
char pint_s(char *l, char *arg, int line, stack_t **poi)
{
	stack_t *top = NULL;

	(void) l;
	(void) arg;
	(void) line;
	if (poi)
		top = *poi;
	if (top == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line);
		breakdown(NULL, 'q', EXIT_FAILURE);
	}

	while (top->next != NULL)
		top = top->next;
	*poi = top;
	printf("%d\n", top->n);
	return ('s');
}

