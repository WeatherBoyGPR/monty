#include "monty.h"

/**
 * main - will feed input into the monty core and hold data between commandd
 * @argc: number of commandline arguments
 * @argv: command line arguments, a single filename
 *
 * Return: EXIT_SUCCESS or EXIT_FAILURE
 */
int main(int argc, char **argv)
{
	FILE *FD = NULL;
	int ex = EXIT_SUCCESS, line = 1;
	size_t len = 0;
	char mode = 's', *l = NULL;
	stack_t *stk = NULL;
	instruction_t mfunc[] = {
		{"push", push_s},
		{"pall", pall_s},
		{"pint", pint_s},
		{"queue", queue_set},
		{"pop", pop_s},
		{NULL, NULL},
		{"push", push_q},
		{"pall", pall_q},
		{"pint", pint_q},
		{"pop", pop_q},
		{"stack", stack_set},
		{NULL, NULL}
	};
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		breakdown(NULL, mode, EXIT_FAILURE);
	}
	FD = fopen(argv[1], "r");
	if (!FD)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		breakdown(NULL, mode, EXIT_FAILURE);
	}
	while (getline(&l, &len, FD) != -1)
	{
		mode = M_core(l, line, mfunc, mode, &stk);
		line++;
	}
	fclose(FD), free(l);
	breakdown(stk, mode, ex);
	return (ex);
}

/**
 * M_core - Will process commands and provide them to functions
 * @l: line to process
 * @line: current line number
 * @mfunc: array of functions to invoke on command
 * @mode: s while stack, q while queue
 * @stk: current data stack
 *
 * Return: present mode
 */
char M_core(char *l, int line, instruction_t *mfunc, char mode, stack_t **stk)
{
	int n = 0;
	char *tk[2] = {NULL, NULL};
	const char *del = " \t\n";
	char *ln;

	if (!l)
		return (mode);
	if (mode == 'q')
		n = 6;
	ln = malloc((strlen(l) + 1) * sizeof(char));
	if (ln == NULL)
		mal_error(stk, mode, l);
	strcpy(ln, l);
	tk[0] = strtok(ln, del);

	if (tk[0] != NULL && *(tk[0]) != '#')
	{
		tk[1] = strtok(NULL, del);
		while ((mfunc[n]).opcode && tk[0] && strcmp(tk[0], (mfunc[n]).opcode))
			n++;
		if (tk[0] && (mfunc[n]).opcode)
		{
			mode = (mfunc[n].f)(l, tk[1], line, stk);
		}
		else
		{
			fprintf(stderr, "L%d: unknown instruction %s\n", line, tk[0]);
			free(ln);
			breakdown(NULL, mode, EXIT_FAILURE);
		}
	}
	free(ln);
	return (mode);
}
