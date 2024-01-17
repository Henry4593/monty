#include "monty.h"

/**
 * func_mul - Multiplies the top two elements of a stack_t linked list
 * @head: A double pointer to the head node of the stack
 * @counter: The line number count
 *
 * Description: Checks that there are at least two nodes in the stack.
 * Gets the data values stored in the top two nodes.
 * Multiplies the data values together and stores result in the second node.
 * Advances the head pointer to the second node.
 * Frees the former top node.
 * Prints error and exits if checks fail.
 *
 * Return: Nothing
 */

void func_mul(stack_t **head, unsigned int counter)
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
		fprintf(stderr, "L%d: can't mul, stack too short\n", counter);
		fclose(program_context.file);
		free(program_context.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	h = *head;
	aux = h->next->n * h->n;
	h->next->n = aux;
	*head = h->next;
	free(h);
}
