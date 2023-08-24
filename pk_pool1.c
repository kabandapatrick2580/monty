#include "monty.h"

/**
 * pk_pint - A function that prints the top value of the stack.
 * @stack: The pointer to the stack list.
 * @line_number: The current working line number of a Monty bytecodes file.
 */
void pk_pint(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;

	if (!tmp)
	{
		f_errors(1, line_number);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", tmp->n);
}


/**
 * pk_pop - A function that removes the top value in the stack.
 * @stack: The pointer to the stack_t list.
 * @line_number: The line number of a Monty bytecodes file.
 */
void pk_pop(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;

	if (!tmp)
	{
		f_errors(2, line_number);
		exit(EXIT_FAILURE);
	}

	if (tmp->next)
		tmp->next->prev = tmp->prev;
	*stack = tmp->next;
	free(tmp);
}

/**
 * pk_swap - A function that swaps the two values at the top of stack.
 * @stack: The pointer to the top of a stack list.
 * @line_number: The line number of a Monty bytecodes file.
 */
void pk_swap(stack_t **stack, unsigned int line_number)
{
	int tmp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		f_errors(3, line_number);
		exit(EXIT_FAILURE);
	}
	tmp = (*stack)->next->n;
	(*stack)->next->n = (*stack)->n;
	(*stack)->n = tmp;
}

/**
 * pk_add - A function that adds the two top values of a stack.
 * @stack: The pointer to the stack list.
 * @line_number: The line number of a Monty bytecodes file.
 * Description: The result is stored in the second value node
 *              from the top and the top value  is removed.
 */
void pk_add(stack_t **stack, unsigned int line_number)
{
	int temp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		f_errors(4, line_number);
		exit(EXIT_FAILURE);
	}
	temp = (*stack)->n + (*stack)->next->n;
	(*stack)->next->n = temp;
	pk_pop(stack, line_number);
}

/**
 * pk_sub - A function that subtracts the second value from the top of a
 * stack linked by the top value.
 * @stack: The pointer to the stack list.
 * @line_number: The line number of a Monty bytecodes file.
 * Description: The result is stored in the second node
 *              from the top and the top value is removed.
 */
void pk_sub(stack_t **stack, unsigned int line_number)
{
	int temp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		f_errors(5, line_number);
		exit(EXIT_FAILURE);
	}
	temp = (*stack)->next->n - (*stack)->n;
	(*stack)->next->n = temp;
	pk_pop(stack, line_number);
}
