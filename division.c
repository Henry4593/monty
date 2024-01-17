#include "monty.h"

/**
 * func_div - Divides the second node value by top node value
 * @head: A double pointer to head node of stack
 * @counter: Line count
 *
 * Description: Checks that stack has at least 2 nodes.
 * Checks for divide by 0 error.
 * Gets node values and divides them.
 * Stores result in second node, advances head pointer.
 * Frees old top node.
 * Prints errors and exits if checks fail.
 *
 * Return: Nothing
 */

void func_div(stack_t **head, unsigned int counter)
{
	stack_t *h;
	int length = 0, result_div;

	h = *head;
	while (h)
	{
		h = h->next;
		length++;
	}
	if (length < 2)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", counter);
		fclose(program_context.file);
		free(program_context.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	h = *head;
	if (h->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", counter);
		fclose(program_context.file);
		free(program_context.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	result_div = h->next->n / h->n;
	h->next->n = result_div;
	*head = h->next;
	free(h);
}
