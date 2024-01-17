#include "monty.h"

/**
 * func_rotr - Rotates the stack to the bottom
 * @head: A double pointer to the head node of the stack
 * @counter: The line number count (unused)
 *
 * Description: This function rotates the stack to the bottom, moving the
 * bottom element to the top. It takes a double pointer to the head node
 * of the stack and the line number count (unused) as parameters.
 *
 * Return: None
 */

void func_rotr(stack_t **head, __attribute__((unused)) unsigned int counter)
{
	stack_t *copy;

	copy = *head;
	if (*head == NULL || (*head)->next == NULL)
	{
		return;
	}
	while (copy->next)
	{
		copy = copy->next;
	}
	copy->next = *head;
	copy->prev->next = NULL;
	copy->prev = NULL;
	(*head)->prev = copy;
	(*head) = copy;
}
