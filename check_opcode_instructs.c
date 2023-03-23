#include "monty.h"
/**
 *stack_push - pushes elements to the stack
 *@doubly: head of doubly linked list
 *@line_count: line number
 *
 *Return: nothing
 */
void stack_push(stack_t **doubly, unsigned int line_count)
{
	int i, element;

	if (!opcode.ptr)
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_count);
		free(opcode.ptr);
		exit(EXIT_FAILURE);
	}
	for (i = 0; opcode.ptr[i] != '\0'; i++)
	{
		if (!isdigit(opcode.ptr[i]) && opcode.ptr[i] != '-')
		{
			fprintf(stderr, "L%u: usage: push integer\n", line_count);
			free(opcode.ptr);
			exit(EXIT_FAILURE);
		}
	}
	element = atoi(opcode.ptr);
	add_doublynode(doubly, element);
}
/**
 *stack_pall - prints all the elements in the stack
 *@doubly: head of doubly linked list
 *@line_count: line number
 *
 *Return: nothing
 */
void stack_pall(stack_t **doubly, unsigned int line_count)
{
	stack_t *current;
	(void)line_count;

	current = *doubly;
	while (current)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
/**
 *stack_pint - print the element at stack top
 *@doubly: head node
 *@line_count: line number
 *
 *
 *Return: nothing
 */
void stack_pint(stack_t **doubly, unsigned int line_count)
{
	(void)line_count;

	if (doubly == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stak empty\n");
		free(opcode);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*doubly)->n);
}
