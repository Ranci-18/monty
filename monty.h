#ifndef MONTY_H
#define MONTY_H
#define _GNU_SOURCE
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

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
*global_s - global variable
*Description: global variable
*
*/
typedef struct global_s
{
	char *ptr;
	FILE *fd;
	stack_t *head;
} global;

extern global opcode;
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
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

void load_opcode_var(FILE *fd);
void stack_push(stack_t **doubly, unsigned int line_count);
void stack_pall(stack_t **doubly, unsigned int line_count);
void stack_pint(stack_t **doubly, unsigned int line_count);
void stack_pop(stack_t **doubly, unsigned int line_count);
void stack_swap(stack_t **doubly, unsigned int line_count);
stack_t *add_doublynode(stack_t **head, const int n);
void free_doubly_ll(stack_t *head);
void (*check_opcode(char *op))(stack_t **stack, unsigned int line_number);
#endif
