#include "monty.h"

/**
 * func_add - Adds the top two elements of a stack_t linked list
 * @head: A double pointer to the head node of the stack
 * @counter: The line number counter
 *
 * Description: Checks that there are at least two nodes in the stack.
 * Gets the data values stored in the top two nodes.
 * Adds the data values together and stores result in the second node.
 * Advances the head pointer to the second node.
 * Frees the former top node.
 * If less than two nodes, prints error and exits.
 *
 * Return: None
 */

void func_add(stack_t **head, unsigned int counter)
{
	stack_t *h;
	int length = 0, sum_first_two_Nodes;

	h = *head;
	while (h)
	{
		h = h->next;
		length++;
	}
	if (length < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", counter);
		fclose(program_context.file);
		free(program_context.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	h = *head;
	sum_first_two_Nodes = h->n + h->next->n;
	h->next->n = sum_first_two_Nodes;
	*head = h->next;
	free(h);
}
