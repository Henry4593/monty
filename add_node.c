#include "monty.h"

/**
 * addnode - Adds a new node at the beginning of a stack_t linked list
 * @head: A double pointer to the head node of the stack
 * @n: The data to be inserted in the new node
 *
 * Description: Dynamically allocates memory for the new node.
 * Checks if allocation succeeded, exits with error if it failed.
 * Updates the next and prev pointers to insert new node at head.
 * Sets the data value n in the new node.
 * Updates the head pointer to point to new node.
 *
 * Return: Nothing
 */

void addnode(stack_t **head, int n)
{

	stack_t *new_node, *current_head;

	current_head = *head;
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		printf("Error\n");
		exit(0);
	}
	if (current_head)
		current_head->prev = new_node;
	new_node->n = n;
	new_node->next = *head;
	new_node->prev = NULL;
	*head = new_node;
}
