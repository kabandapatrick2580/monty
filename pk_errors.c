#include "monty.h"

/**
 * open_error - A function that prints a file open error message.
 * @filename: Name of the file that failed to open.
 * Return: EXIT_FAILURE.
 */
int open_error(char *filename)
{
    fprintf(stderr, "Error: Can't open file %s\n", filename);
    return (EXIT_FAILURE);
}

/**
 * error_usage - A function that prints a usage error message.
 * @drapeau: Type of error: 0 malloc'd failed, or 1 usage.
 * Return: EXIT_FAILURE.
 */
int error_usage(int drapeau)
{
    char *fr_errors[2] = {"Error: malloc failed", "USAGE: monty file"};

    fprintf(stderr, "%s\n", fr_errors[drapeau]);
    return (EXIT_FAILURE);
}

/**
 * show_f_errors - A function that prints various errors.
 * @drapeau: The index to type of error.
 * @line_of_num: The number of line in file with error.
 * Return: EXIT_FAILURE.
 */
int show_f_errors(int drapeau, unsigned int line_of_num)
{
    char *fr_errors[] = {"usage: push integer", "can't pint, stack empty",
                         "can't pop an empty stack", "can't swap, stack too short",
                         /* ... (other error messages) */
                         "can't pchar, stack empty"};

    fprintf(stderr, "L%d: %s\n", line_of_num, fr_errors[drapeau]);
    return (EXIT_FAILURE);
}
