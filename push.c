#include "monty.h"

/**
 * func_push - Pushes an integer onto the stack
 * @head: A double pointer to the head node of the stack
 * @counter: The line number count
 *
 * Description: This function pushes an integer onto the stack.
 * It takes a double pointer to the head node of the stack and the line
 * number count as parameters. It also checks for valid integer input and
 * handles error cases.
 *
 * Return: None
 */

void func_push(stack_t **head, unsigned int counter)
{
	int n, j = 0, flag = 0;

	if (program_context.arg)
	{
		if (program_context.arg[0] == '-')
			j++;
		for (; program_context.arg[j] != '\0'; j++)
		{
			if (program_context.arg[j] > 57 || program_context.arg[j] < 48)
				flag = 1; }
		if (flag == 1)
		{ fprintf(stderr, "L%d: usage: push integer\n", counter);
			fclose(program_context.file);
			free(program_context.content);
			free_stack(*head);
			exit(EXIT_FAILURE); }}
	else
	{ fprintf(stderr, "L%d: usage: push integer\n", counter);
		fclose(program_context.file);
		free(program_context.content);
		free_stack(*head);
		exit(EXIT_FAILURE); }
	n = atoi(program_context.arg);
	if (program_context.lifi == 0)
		addnode(head, n);
	else
		addqueue(head, n);
}
