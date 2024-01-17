#include "monty.h"

/**
 * func_pall - Prints all the elements of a stack
 * @head: A double pointer to the head node of the stack
 * @counter: The line number count
 *
 * Description: This function prints all the elements of the stack.
 * It takes a double pointer to the head node of the stack and the line
 * number count as parameters.
 *
 * Return: None
 */

void func_pall(stack_t **head, unsigned int counter)
{
	stack_t *h;
	(void)counter;

	h = *head;
	if (h == NULL)
		return;
	while (h)
	{
		printf("%d\n", h->n);
		h = h->next;
	}
}
