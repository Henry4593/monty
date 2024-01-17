#include "monty.h"

/**
 * func_queue - Sets the behavior of the stack to queue mode
 * @head: A double pointer to the head node of the stack
 * @counter: The line number count
 *
 * Description: This function sets the behavior of the stack to queue mode.
 * It takes a double pointer to the head node of the stack and the line
 * number count as parameters. In this mode, elements are added to the end
 * of the stack (queue) rather than the top (LIFO).
 *
 * Return: None
 */

void func_queue(stack_t **head, unsigned int counter)
{
	(void)head;
	(void)counter;
	program_context.lifi = 1;
}

/**
 * addqueue - Adds a node to the end of the stack (queue)
 * @head: A double pointer to the head node of the stack
 * @n: The integer value to be added to the stack
 *
 * Description: This function adds a node with the given integer value
 * to the end of the stack (queue). It takes a double pointer to the head
 * node of the stack and the integer value as parameters.
 *
 * Return: None
 */

void addqueue(stack_t **head, int n)
{
	stack_t *new_node, *current_head;

	current_head = *head;
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		printf("Error\n");
	}
	new_node->n = n;
	new_node->next = NULL;
	if (current_head)
	{
		while (current_head->next)
			current_head = current_head->next;
	}
	if (!current_head)
	{
		*head = new_node;
		new_node->prev = NULL;
	}
	else
	{
		current_head->next = new_node;
		new_node->prev = current_head;
	}
}
