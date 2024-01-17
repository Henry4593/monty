#include "monty.h"

/**
 * func_rotl - Rotates the stack to the top
 * @head: A double pointer to the head node of the stack
 * @counter: The line number count (unused)
 *
 * Description: This function rotates the stack to the top, moving the
 * top element to the bottom. It takes a double pointer to the head node
 * of the stack and the line number count (unused) as parameters.
 *
 * Return: None
 */

void func_rotl(stack_t **head,  __attribute__((unused)) unsigned int counter)
{
	stack_t *temp_node = *head, *current_head;

	if (*head == NULL || (*head)->next == NULL)
	{
		return;
	}
	current_head = (*head)->next;
	current_head->prev = NULL;
	while (temp_node->next != NULL)
	{
		temp_node = temp_node->next;
	}
	temp_node->next = *head;
	(*head)->next = NULL;
	(*head)->prev = temp_node;
	(*head) = current_head;
}
