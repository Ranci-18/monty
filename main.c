#include "monty.h"
#include <stdio.h>
global opcode = {NULL, NULL};
/**
 *main - opens file and makes essential function calls
 *@argc: argument count
 *@argv: arguments
 *
 *
 *Return: nothing
 */
int main(int argc, char *argv[])
{
	FILE *fd;
	char *line = NULL, *head = NULL;
	size_t size = 500;
	ssize_t read = 0;
	int line_count = 1;
	void (*f)(stack_t **stack, unsigned int line_number);

	if (argv[1] == NULL || argc == 3)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	fd = fopen(argv[1], "r");
	if (!fd)
	{
		printf("Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	read = getline(&line, &size, fd);
	while (read != -1)
	{
		opcode.ptr = strtok(line, " \t\n");
		if (opcode.ptr)
		{
			f = check_opcode(opcode.ptr);
			if (!f)
			{
				fprintf(stderr, "L%d: unknown instruction %s\n", line_count, opcode.ptr);
				free(line);
				fclose(fd);
				exit(EXIT_FAILURE);
			}
			head = strtok(NULL, " \t\n");
			f(*head, line_count);
		}
		read = getline(&line, &size, fd);
		line_count++;
	}
	free(line);
	fclose(fd);
	return (0);
}
