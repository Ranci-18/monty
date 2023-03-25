#include "monty.h"
/**
 *add_doublynode - adds a new node to the doubly linked list
 *@head: head node
 *@n: node values
 *
 *Return: the new node
 */
stack_t *add_doublynode(stack_t **head, const int n)
{
	stack_t *new_node = NULL;

	new_node = malloc(sizeof(stack_t));
	if (!new_node)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free(new_node);
		exit(EXIT_FAILURE);
	}
	new_node->n = n;
	if (*head == NULL)
	{
		new_node->next = *head;
		new_node->prev = NULL;
		*head = new_node;
		return (new_node);
	}
	(*head)->prev = new_node;
	new_node->next = *head;
	new_node->prev = NULL;
	*head = new_node;
	return (new_node);
}
/**
 *free_doubly_ll - frees the doubly linked list
 *@head: head node
 *
 *Return: nothing
 */
void free_doubly_ll(stack_t *head)
{
	stack_t *current = head;

	while (head != NULL)
	{
		head = head->next;
		free(current);
	}
}
