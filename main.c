#include <stdio.h>
#include "monty.h"

program_context_t program_context = {NULL, NULL, NULL, 0};

/**
 * main - Monty byte code interpreter
 * @argc: Argument count
 * @argv: Argument vector
 *
 * Description: Opens Monty byte code file.
 * Reads file line by line and interprets each opcode,
 * manipulating a stack linked list based on commands.
 * Counts line numbers. Calls execute for each instruction.
 * Frees data and closes file before exiting.
 *
 * Return: 0 on success
 */

int main(int argc, char *argv[])
{
	char *content;
	FILE *file;
	size_t size = 0;
	ssize_t read_line = 1;
	stack_t *stack = NULL;
	unsigned int counter = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	program_context.file = file;
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (read_line > 0)
	{
		content = NULL;
		read_line = _getline(&content, &size, file);
		program_context.content = content;
		counter++;
		if (read_line > 0)
		{
			execute(content, &stack, counter, file);
		}
		free(content);
	}
	free_stack(stack);
	fclose(file);
return (0);
}
