#include "monty.h"

/**
 * clear_error - Afunction that prints usage error message.
 * @drapeau: Type of error: 0 malloc'd failed, or 1 usage.
 * Return: EXIT_FAILURE.
 */
int clear_error(int drapeau)
{
	char *fr_errors[2] = {"Error: malloc failed", "USAGE: monty file"};

	fprintf(stderr, "%s\n", fr_errors[drapeau]);
	return (EXIT_FAILURE);
}

/**
 * diffuse_error - A function that prints file open error message.
 * @filename: Name of file failed to open.
 * Return: EXIT_FAILURE.
 */
int diffuse_error(char *filename)
{
	fprintf(stderr, "Error: Can't open file %s\n", filename);
	return (EXIT_FAILURE);
}

/**
 * show_f_errors - A function that print the errors.
 * @drapeau: The index to type of error.
 * @line_of_num: The number of line in file with error.
 * Return: EXIT_FAILURE.
 */
int show_f_errors(int drapeau, unsigned int line_of_num)
{
	char *fr_errors[] = {"usage: push integer", "can\'t pint, stack empty",
	     "can\'t pop an empty stack", "can\'t swap, stack too short",
	     "can\'t add, stack too short", "can\'t sub, stack too short",
	     "can\'t div, stack too short", "division by zero",
	     "can\'t mul, stack too short", "can\'t mod, stack too short",
	     "can\'t pchar, value out of range", "can\'t pchar, stack empty"};

	fprintf(stderr, "L%d: %s\n", line_of_num, fr_errors[drapeau]);
	return (EXIT_FAILURE);
}
