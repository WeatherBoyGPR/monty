#ifndef WILDWESTHERO
#define WILDWESTHERO

#define  _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	char (*f)(char *l, char *arg, int line, stack_t **poi);
} instruction_t;

/* MontyCore.c */
char M_core(char *l, int line, instruction_t *mfunc, char mode, stack_t **stk);

/* MontyUtil1.c */
int num_get(char *l, char *err);
void mal_error(stack_t **point, char mode, char *line);
void breakdown(stack_t *point, char mode, int stat);
void freestack_hd(stack_t *head);
void freestack_tl(stack_t *tail);

/* MontyUtil2.c */
stack_t *create_node(stack_t **poi, char mode, char *line);
int rm_tl(stack_t **poi, char *s);
int rm_hd(stack_t **poi, char *s);

/* MontyFunc1.c */
char push_s(char *l, char *arg, int line, stack_t **poi);
char push_q(char *l, char *arg, int line, stack_t **poi);
char stack_set(char *l, char *arg, int line, stack_t **poi);
char queue_set(char *l, char *arg, int line, stack_t **poi);
char pop_s(char *l, char *arg, int line, stack_t **poi);

/* MontyFunc2.c */
char pall_s(char *l, char *arg, int line, stack_t **poi);
char pall_q(char *l, char *arg, int line, stack_t **poi);
char pint_s(char *l, char *arg, int line, stack_t **poi);
char pint_q(char *l, char *arg, int line, stack_t **poi);
char pop_q(char *l, char *arg, int line, stack_t **poi);

/* MontyFunc3.c */
char swap_s(char *l, char *arg, int line, stack_t **poi);
char swap_q(char *l, char *arg, int line, stack_t **poi);

#endif
