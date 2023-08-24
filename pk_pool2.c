#include "monty.h"

/**
 * pk_mul - A function that multiply the two top values of a stack.
 * @stack: The pointer to the stack list.
 * @line_number: The line number of a Monty bytecodes file.
 * Description: The result is stored in the second value node
 *              from the top and the top value  is removed.
 */
void pk_mul(stack_t **stack, unsigned int line_number)
{
	int temp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		show_f_errors(8, line_number);
		exit(EXIT_FAILURE);
	}
	temp = (*stack)->n * (*stack)->next->n;
	(*stack)->next->n = temp;
	pk_pop(stack, line_number);
}

/**
 * pk_div - A function that divides the second value from the top of a
 * stack linked by the top value.
 * @stack: The pointer to the stack list.
 * @line_number: The line number of a Monty bytecodes file.
 * Description: The result is stored in the second node
 *              from the top and the top value is removed.
 */
void pk_div(stack_t **stack, unsigned int line_number)
{
	int temp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		show_f_errors(6, line_number);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		show_f_errors(7, line_number);
		exit(EXIT_FAILURE);
	}
	temp = (*stack)->next->n / (*stack)->n;
	(*stack)->next->n = temp;
	pk_pop(stack, line_number);
}

/**
 * pk_mod - A function that modules the second value from the top of a
 * stack linked by the top value.
 * @stack: The pointer to the stack list.
 * @line_number: The line number of a Monty bytecodes file.
 * Description: The result is stored in the second node
 *              from the top and the top value is removed.
 */
void pk_mod(stack_t **stack, unsigned int line_number)
{
	int temp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		show_f_errors(9, line_number);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		show_f_errors(7, line_number);
		exit(EXIT_FAILURE);
	}
	temp = (*stack)->next->n % (*stack)->n;
	(*stack)->next->n = temp;
	pk_pop(stack, line_number);
}

/**
 * pk_pchar - A function that prints char at top value of the stack.
 * @stack: The pointer to the stack list.
 * @line_number: The current working line number of a Monty bytecodes file.
 */
void pk_pchar(stack_t **stack, unsigned int line_number)
{
	int number = 0;
	stack_t *tmp = *stack;

	if (!tmp)
	{
		show_f_errors(11, line_number);
		exit(EXIT_FAILURE);
	}
	number = tmp->n;
	if (number < 0 || number > 127)
	{
		show_f_errors(10, line_number);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", tmp->n);
}

/**
 * pk_pstr - A function that prints the string starting at the top of the
 * stack, followed by a new line.
 * @stack: The pointer to the stack list.
 * @line_number: The current working line number of a Monty bytecodes file.
 */
void pk_pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;
	(void)line_number;

	if (stack == NULL || *stack == NULL)
	{
		printf("\n");
		return;
	}
	while (tmp != NULL)
	{
		if (tmp->n > 0 && tmp->n <= 127)
		{
			printf("%c", tmp->n);
			tmp = tmp->next;
		}
		else
			break;
	}
	printf("\n");
}
