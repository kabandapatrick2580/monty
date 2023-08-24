#include "monty.h"

/**
 * main - The entry point function for Monty Interpreter.
 * @ac: The number of arguments.
 * @av: The pointer to an array of inputed arguments.
 * Return: Always 0 (on Success).
 */
int main(int ac, char **av)
{
	FILE *dp = NULL;
	int exit_status = EXIT_SUCCESS;

	if (ac != 2)
		return (error_ussage(1));

	dp = fopen(av[1], "r");
	if (dp == NULL)
		return (open_error(av[1]));

	exit_status = pk_run(dp);
	fclose(dp);
	return (exit_status);
		open_error(av[1]);
	pk_run(dp);
	exit(EXIT_SUCCESS);
	return (0);
}
