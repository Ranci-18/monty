#include "monty.h"
global opcode;
/**
 *
 *
 *
 *
 */
void load_opcode_var(FILE *fd)
{
	opcode.ptr = NULL;
	opcode.fd = fd;
	opcode.head = NULL;
}
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
	size_t size = 500;
	ssize_t read_line = 0;
	void (*f)(stack_t **stack, unsigned int line_number);
	char *line[2] = {NULL, NULL}, *buf = NULL;
	unsigned int line_count = 1;

	if (argv[1] == NULL || argc > 2)
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
	load_opcode_var(fd);
	read_line = getline(&buf, &size, fd);
	while (read_line != -1)
	{
		line[0] = strtok(buf, " \t\n");
		if (line[0])
		{
			f = check_opcode(line[0]);
			if (!f)
			{
				fprintf(stderr, "L%d: unknown instruction %s\n", line_count, opcode.ptr);
				free(buf);
				fclose(fd);
				exit(EXIT_FAILURE);
			}
			opcode.ptr = strtok(NULL, " \t\n");
			f(&opcode.head, line_count);
		}
		read_line = getline(&buf, &size, fd);
		line_count++;
	}
	free(buf);
	fclose(fd);
	return (0);
}
