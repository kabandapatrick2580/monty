#include "monty.h"

/**
 * execute - Function that checks for a command "opcode" and execute the
 * function if there's a match.
 * @tokenizer: Tokane containing the opcode to execute.
 * @stack: Doubly linked list representation of a stack.
 * @linenum: Line number where the opcode was found.
 * Return: EXIT_SUCCESS in success, or EXIT_FAILURE on failure.
 */

int execute(char **tokenizer, stack_t **stack, unsigned int linenum)
{
	unsigned int i = 0;

	instruction_t bs[] = {
		{"pall", pk_pall},
		{"pint", pk_pint},
		{"pop", pk_pop},
		{"swap", pk_swap},
		{"add", pk_add},
		{"sub", pk_sub},
		{"mul", pk_mul},
		{"div", pk_div},
		{"mod", pk_mod},
		{"pchar", pk_pchar},
		{"pstr", pk_pstr},
		{"rotl", pk_rotl},
		{"rotr", pk_rotr},
		{"null", NULL}
	};

	for (i = 0; i < 14; i++)
	{
		if (strcmp(bs[i].opcode, tokenizer[0]) == 0)
		{
			bs[i].f(stack, linenum);
			return (EXIT_SUCCESS);
		}
	}
	stck_free(stack);
	fprintf(stderr, "L%i: unknown instruction %s\n", linenum, tokenizer[0]);
	return (EXIT_FAILURE);
}

/**
  * pk_push - A function that pushes an element to stack.
  * @stack: The pointer to the stck struct.
  * @tokenizer: The pointer to command.
  * @linenum: The number of the line.
  * Return: EXIT_SUCCESS on success, or EXIT_FAILURE on failure.
  */
int pk_push(stack_t **stack, char **tokenizer, unsigned int linenum)
{
	stack_t *new;
	int i = 0;

	if (tokenizer[1] == NULL)
		return (show_f_errors(0, linenum));
	while (tokenizer[1][i])
	{
		if (tokenizer[1][i] == '-' && i == 0)
		{
			i++;
			continue;
		}
		if (tokenizer[1][i] < '0' || tokenizer[1][i] > '9')
		{
			stck_free(stack);
			return (show_f_errors(0, linenum));
		}
		i++;
	}

	new = malloc(sizeof(stack_t));
	if (new == NULL)
		return (error_usage(0));

	new->n = atoi(tokenizer[1]);
	if ((*stack) != NULL)
		(*stack)->prev = new;
	new->next = *stack;
	new->prev = NULL;
	*stack = new;
	return (EXIT_SUCCESS);
}

/**
 * pk_pushq - A function that pushes an element to queue.
 * @stack: The pointer to the stck struct.
 * @tokenizer: The pointer to command.
 * @linenum: The number of the line.
 * Return: EXIT_SUCCESS on success, or EXIT_FAILURE on failure.
 */
int pk_pushq(stack_t **stack, char **tokenizer, unsigned int linenum)
{
	stack_t *new, *tmp = NULL;
	int i = 0;

	if (tokenizer[1] == NULL)
		return (show_f_errors(0, linenum));
	while (tokenizer[1][i])
	{
		if (tokenizer[1][i] == '-' && i == 0)
		{
			i++;
			continue;
		}
		if (tokenizer[1][i] < '0' || tokenizer[1][i] > '9')
		{
			stck_free(stack);
			return (show_f_errors(0, linenum));
		}
		i++;
	}
	new = malloc(sizeof(stack_t));
	if (new == NULL)
		return (error_usage(0));
	new->next = NULL;
	new->prev = NULL;
	new->n = atoi(tokenizer[1]);
	if (!stack || !(*stack))
	{
		(*stack) = new;
		return (EXIT_SUCCESS);
	}
	else
	{
		tmp = *stack;
		while (tmp->next)
			tmp = tmp->next;
		new->prev = tmp;
		tmp->next = new;
		return (EXIT_SUCCESS);
	}
	return (EXIT_FAILURE);
}

/**
 * pk_pall - A function that prints the values of the stack_t.
 * @stack: The pointer to the top of a stack_t.
 * @linenum: The number of the line.
 * Return: Nothing.
 */
void pk_pall(stack_t **stack, unsigned int linenum)
{
	stack_t *tmp = *stack;
	(void)linenum;

	while (tmp != NULL)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}
