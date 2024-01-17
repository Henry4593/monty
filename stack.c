#include "monty.h"

/**
 * func_stack - Sets the behavior of the stack to stack mode
 * @head: A double pointer to the head node of the stack
 * @counter: The line number count
 *
 * Description: This function sets the behavior of the stack to stack mode.
 * It takes a double pointer to the head node of the stack and the line
 * number count as parameters. In this mode, elements are added to the top
 * of the stack (LIFO) rather than the end (queue).
 *
 * Return: None
 */

void func_stack(stack_t **head, unsigned int counter)
{
	(void)head;
	(void)counter;
	program_context.lifi = 0;
}
