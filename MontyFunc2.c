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

/**
 * pint_q - will print front of queue
 * @l: line to free on error
 * @arg: arg to process into an integer
 * @line: current line number
 * @poi: position somewhere in stack
 *
 * Return: current mode
 */
char pint_q(char *l, char *arg, int line, stack_t **poi)
{
	stack_t *front = NULL;

	(void) l;
	(void) arg;
	(void) line;
	if (poi)
		front = *poi;

	if (front == NULL)
		if (front == NULL)
		{
			fprintf(stderr, "L%d: can't pint, stack empty\n", line);
			breakdown(NULL, 'q', EXIT_FAILURE);
		}
	while (front->prev != NULL)
		front = front->prev;
	*poi = front;
	printf("%d\n", front->n);
	return ('q');
}

/**
 * pop_q - Will pop node on a queue
 * @l: line to free on error
 * @arg: arg to process into an integer
 * @line: current line number
 * @poi: position somewhere in stack
 *
 * Return: current mode
 */
char pop_q(char *l, char *arg, int line, stack_t **poi)
{
	stack_t *tar = NULL;

	(void) arg;
	if (poi != NULL)
		tar = *poi;
	if (tar == NULL)
	{
		free(l);
		fprintf(stderr, "L%d: can't pint, stack empty\n", line);
		if (poi)
			breakdown(*poi, 'q', EXIT_FAILURE);
		else
			breakdown(NULL, 'q', EXIT_FAILURE);
	}
	while (tar->prev != NULL)
		tar = tar->prev;
	*poi = tar->next;
	if (tar->next)
		tar->next->prev = NULL;
	free(tar);

	return ('q');
}
