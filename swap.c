#include "monty.h"

/**
 * func_swap - Swaps the top two elements of the stack
 * @head: A double pointer to the head node of the stack
 * @counter: The line number count
 *
 * Description: This function swaps the top two elements of the stack.
 * It takes a double pointer to the head node of the stack and the line
 * number count as parameters. It checks for a stack with at least two
 * elements and performs the swap operation.
 *
 * Return: None
 */

void func_swap(stack_t **head, unsigned int counter)
{
	stack_t *h;
	int length = 0, temp_value;

	h = *head;
	while (h)
	{
		h = h->next;
		length++;
	}
	if (length < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", counter);
		fclose(program_context.file);
		free(program_context.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	h = *head;
	temp_value = h->n;
	h->n = h->next->n;
	h->next->n = temp_value;
}
