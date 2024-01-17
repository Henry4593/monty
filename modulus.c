#include "monty.h"

/**
 * func_mod - Computes modulo of second node % top node
 * @head: A double pointer to the head node of the stack
 * @counter: Line number count
 *
 * Description: Checks for at least 2 nodes, checks
 * for divide by 0 error. Gets node values,
 * computes modulo, stores result in second node.
 * Advances head, frees old top node.
 * Prints errors and exits if checks fail.
 *
 * Return: None
 */

void func_mod(stack_t **head, unsigned int counter)
{
	stack_t *h;
	int length = 0, aux;

	h = *head;
	while (h)
	{
		h = h->next;
		length++;
	}
	if (length < 2)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", counter);
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
	aux = h->next->n % h->n;
	h->next->n = aux;
	*head = h->next;
	free(h);
}
