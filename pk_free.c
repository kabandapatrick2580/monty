#include "monty.h"

/**
 * stck_free - A function that frees the memory allocated for stack.
 * @stack: Pointer to the doubly linked list representation of a stack.
 * Return: Nothing.
 */

void stck_free(stack_t **stack)
{
	stack_t *tmp = *stack;

	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
}
