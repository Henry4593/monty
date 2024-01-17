#include "monty.h"

/**
 * func_pop - Removes the top element of the stack
 * @head: A double pointer to the head node of the stack
 * @counter: The line number count
 *
 * Description: This function removes the top element of the stack.
 * It takes a double pointer to the head node of the stack and the line
 * number count as parameters.
 *
 * Return: None
 */

void func_pop(stack_t **head, unsigned int counter)
{
	stack_t *h;

	if (*head == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", counter);
		fclose(program_context.file);
		free(program_context.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	h = *head;
	*head = h->next;
	free(h);
}
