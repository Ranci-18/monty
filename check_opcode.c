#include "monty.h"
/**
 *check_opcode - selects the correct opcode to perform
 *@op: passed opcode
 *
 *
 *
 *Return: pointer to the function opcode
 */
void (*check_opcode(char *op))(stack_t **stack, unsigned int line_number)
{
	instruction_t opcde[] = {
		{"push", stack_push},
		{"pall", stack_pall},
		{"pint", stack_pint},
		{"pop", stack_pop},
		{"swap", stack_swap},
		{NULL, NULL}
	};
	int j;

	for (j = 0; opcde[j].opcode; j++)
	{
		if (strcmp(opcde[j].opcode, op) == 0)
			break;
	}
	return (opcde[j].f);
}
