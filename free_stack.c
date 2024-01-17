#include "monty.h"

/**
 * free_stack - Frees a stack_t linked list
 * @head: Pointer to the head node of the stack
 *
 * Description: Iterates through the stack freeing one node
 * at a time by holding a pointer to the next node, freeing
 * the current node, advancing to the next until end is NULL.
 *
 * Return: Nothing
 */

void free_stack(stack_t *head)
{
	stack_t *tmp_node;

	tmp_node = head;
	while (head)
	{
		tmp_node = head->next;
		free(head);
		head = tmp_node;
	}
}
