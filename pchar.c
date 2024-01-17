#include "monty.h"

/**
 * func_pchar - Prints the char at the top of the stack
 * @head: A double pointer to the head node of the stack
 * @counter: The line number count
 *
 * Description: This function prints the character at the top of the stack.
 * It takes a double pointer to the head node of the stack and the line
 * number count as parameters.
 *
 * Return: None
 */

void func_pchar(stack_t **head, unsigned int counter)
{
	stack_t *h;

	h = *head;
	if (!h)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", counter);
		fclose(program_context.file);
		free(program_context.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	if (h->n > 127 || h->n < 0)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", counter);
		fclose(program_context.file);
		free(program_context.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", h->n);
}
