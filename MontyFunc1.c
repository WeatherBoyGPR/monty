#include "monty.h"

/**
 * push_s - will push data to stack in stack mode
 * @l: line to free on error
 * @arg: arg to process into an integer
 * @line: current line number
 * @poi: position somewhere in stack
 *
 * Return: current mode
 */
char push_s(char *l, char *arg, int line, stack_t **poi)
{
	int n;
	char e = 0;
	stack_t *new = NULL;

	n = num_get(arg, &e);
	if (e)
	{
		free(l);
		fprintf(stderr, "L%d: usage: push integer\n", line);
		if (poi)
			breakdown(*poi, 's', EXIT_FAILURE);
		else
			breakdown(NULL, 'q', EXIT_FAILURE);
	}

	new = create_node(poi, 's', l);
	new->n = n;
	return ('s');
}

/**
 * push_q - will push data to stack in queue mode
 * @l: line to free on error
 * @arg: arg to process into an integer
 * @line: current line number
 * @poi: position somewhere in stack
 *
 * Return: current mode
 */
char push_q(char *l, char *arg, int line, stack_t **poi)
{
	int n;
	char e = 0;
	stack_t *new = NULL;

	n = num_get(arg, &e);
	if (e)
	{
		free(l);
		fprintf(stderr, "L%d: usage: push integer\n", line);
		if (poi)
			breakdown(*poi, 'q', EXIT_FAILURE);
		else
			breakdown(NULL, 'q', EXIT_FAILURE);
	}

	new = create_node(poi, 's', l);
	new->n = n;

	return ('q');
}

/**
 * stack_set - will set mode from queue to stack
 * @l: line to free on error
 * @arg: arg to process into an integer
 * @line: current line number
 * @poi: position somewhere in stack
 *
 * Return: stack mode indicator
 */
char stack_set(char *l, char *arg, int line, stack_t **poi)
{
	(void) l;
	(void) arg;
	(void) line;
	(void) poi;
	printf("TESTstack_set\n");
	return ('s');
}

/**
 * queue_set - will set mode from stack to queue
 * @l: line to free on error
 * @arg: arg to process into an integer
 * @line: current line number
 * @poi: position somewhere in stack
 *
 * Return: queue mode indicator
 */
char queue_set(char *l, char *arg, int line, stack_t **poi)
{
	(void) l;
	(void) arg;
	(void) line;
	(void) poi;
	printf("TESTqueue_set\n");
	return ('q');
}

/**
 * pop_s - Will pop node on stack
 * @l: line to free on error
 * @arg: arg to process into an integer
 * @line: current line number
 * @poi: position somewhere in stack
 *
 * Return: current mode
 */
char pop_s(char *l, char *arg, int line, stack_t **poi)
{
	stack_t *tar = NULL;

	(void) arg;
	if (poi != NULL)
		tar = *poi;
	if (tar == NULL)
	{
		free(l);
		fprintf(stderr, "L%d: can't pop an empty stack\n", line);
		if (poi)
			breakdown(*poi, 'q', EXIT_FAILURE);
		else
			breakdown(NULL, 'q', EXIT_FAILURE);
	}
	while (tar->next != NULL)
		tar = tar->next;
	*poi = tar->prev;
	if (tar->prev)
		tar->prev->next = NULL;
	free(tar);

	return ('s');
}
