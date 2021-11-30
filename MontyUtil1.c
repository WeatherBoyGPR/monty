#include "monty.h"

/**
 * num_get - Will get atoi a number from a token
 * @l: number to atoi token from
 * @err: error indicator
 *
 * Return: integer from token, 0 on error
 */
int num_get(char *l, char *err)
{
	char *buf = NULL;
	int res = 1;

	if (l)
	{
		if (*l == '-')
		{
			l++;
			res *= -1;
		}
		for (buf = l; *buf != '\0'; buf++)
			if ((*buf < '0' || *buf > '9'))
			{
				*err += 1;
				return (0);
			}
		return (atoi(l) * res);
	}
	*err += 1;
	return (0);
}

/**
 * mal_error - prints malloc error messages, calls breakdown
 * @point: current stack
 * @mode: current mode
 * @line: line to free
 */
void mal_error(stack_t **point, char mode, char *line)
{
	if (line)
		free(line);
	fprintf(stderr, "Error: malloc failed\n");
	if (*point)
		breakdown(*point, mode, EXIT_FAILURE);
	else
		breakdown(NULL, mode, EXIT_FAILURE);
}

/**
 * breakdown - frees stack, exits
 * @point: stack to free
 * @mode: current mode
 * @stat: status to exit with
 */
void breakdown(stack_t *point, char mode, int stat)
{
	if (point)
	{
		if (mode == 's')
			freestack_hd(point);
		if (mode == 'q')
			freestack_tl(point);
	}
	exit(stat);
}

/**
 * freestack_hd - will free a stack from the head
 * @head: head of the stack
 */
void freestack_hd(stack_t *head)
{
	stack_t *spear;

	if (!head)
		return;

	while (head->prev != NULL)
		head = head->prev;
	spear = head;
	while (head != NULL)
	{
		spear = spear->next;
		free(head);
		head = spear;
	}
}

/**
 * freestack_tl - will free a stack from the tail
 * @tail: tail of the stack
 */
void freestack_tl(stack_t *tail)
{
	stack_t *spear;

	if (!tail)
		return;

	while (tail->next != NULL)
		tail = tail->next;
	spear = tail;
	while (tail != NULL)
	{
		spear = spear->prev;
		free(tail);
		tail = spear;
	}
}
