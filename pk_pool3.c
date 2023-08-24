#include "monty.h"

/**
 * pk_rotl - A function that rotates the stack to the top.
 * @stack: The pointer to the stack list.
 * @line_number: The line number of a Monty bytecodes file.
 * Description: The top element of the stack becomes the last one,
 * and the second top element of the stack becomes the first one.
 */
void pk_rotl(stack_t **stack, unsigned int line_number)
{
	int temp;
	stack_t *curseur = *stack;
	(void)line_number;

	if (*stack)
	{
		temp = curseur->n;
		while (curseur->next != NULL)
		{
			curseur->n = curseur->next->n;
			curseur = curseur->next;
		}
		curseur->n = temp;
	}
}

/**
 * pk_rotr - A function that rotates the stack to the bottom.
 * @stack: The pointer to the stack list.
 * @line_number: The line number of a Monty bytecodes file.
 * Description: The last element of the stack becomes the top element
 * of the stack.
 */
void pk_rotr(stack_t **stack, unsigned int line_number)
{
	int temp;
	stack_t *curseur = *stack;
	(void)line_number;

	if (*stack)
	{
		while (curseur->next != NULL)
			curseur = curseur->next;
		temp = curseur->n;
		while (curseur->prev != NULL)
		{
			curseur->n = curseur->prev->n;
			curseur = curseur->prev;
		}
		curseur->n = temp;
	}
}
