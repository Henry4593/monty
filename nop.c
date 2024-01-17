#include "monty.h"

/**
 * func_nop - Doesn't do anything
 * @head: A double pointer to the head node of the stack
 * @counter: The line number count
 *
 * Description: A nop instruction doesn't do anything. This function
 * avoids unused parameter compiler warnings by casting them to void.
 *
 * Return: None
 */

void func_nop(stack_t **head, unsigned int counter)
{
	(void) counter;
	(void) head;
}
