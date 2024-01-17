#include "monty.h"

/**
 * func_pint - Prints the top element of the stack as an integer
 * @head: A double pointer to the head node of the stack
 * @counter: The line number count
 *
 * Description: This function prints the integer value at the top of the stack.
 * It takes a double pointer to the head node of the stack and the line
 * number count as parameters.
 *
 * Return: None
 */

void func_pint(stack_t **head, unsigned int counter)
{
	if (*head == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", counter);
		fclose(program_context.file);
		free(program_context.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*head)->n);
}
