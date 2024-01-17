#include "monty.h"

/**
 * func_pstr - Prints the string starting from the top of the stack
 * @head: A double pointer to the head node of the stack
 * @counter: The line number count
 *
 * Description: This function prints the string starting from the top
 * of the stack. It prints characters until it encounters a non-printable
 * ASCII character, a zero, or if the stack is empty.
 *
 * Return: None
 */

void func_pstr(stack_t **head, unsigned int counter)
{
	stack_t *h;
	(void)counter;

	h = *head;
	while (h)
	{
		if (h->n > 127 || h->n <= 0)
		{
			break;
		}
		printf("%c", h->n);
		h = h->next;
	}
	printf("\n");
}
