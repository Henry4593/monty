#include "monty.h"

/**
 * func_sub - Subtracts the top element of the stack from the second
 * top element
 * @head: A double pointer to the head node of the stack
 * @counter: The line number count
 *
 * Description: This function subtracts the top element of the stack from
 * the second top element. It takes a double pointer to the head node of the
 * stack and the line number count as parameters. It checks for a stack with
 * at least two elements, and updates the second top element with the result.
 *
 * Return: None
 */

void func_sub(stack_t **head, unsigned int counter)
{
	stack_t *current_head;
	int result_subtr, nodes;

	current_head = *head;
	for (nodes = 0; current_head != NULL; nodes++)
		current_head = current_head->next;
	if (nodes < 2)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", counter);
		fclose(program_context.file);
		free(program_context.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	current_head = *head;
	result_subtr = current_head->next->n - current_head->n;
	current_head->next->n = result_subtr;
	*head = current_head->next;
	free(current_head);
}
