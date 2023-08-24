#include "monty.h"

/**
 * pk_run - A function that runs a Monty bytecodes script.
 * @dp: File descriptor for an open Monty bytecodes script.
 * Return: EXIT_SUCCESS on success, or EXIT_FAILURE on error.
 */
int pk_run(FILE *dp)
{
    stack_t *stack = NULL;
    char *line = NULL, **token = NULL, delim[] = " \n\t\a\b";
    size_t len = 0, mode = 1;
    unsigned int linenum = 0, exit_status = EXIT_SUCCESS;

    while (fgets(line, len, dp) != NULL)
    {
        linenum++;
        if (get_line(line, delim))
            continue;

        token = tok_en(line, delim);
        if (token[0][0] == '#' || strcmp(token[0], "nop") == 0)
        {
            free(token);
            continue;
        }
        else if (strcmp(token[0], "stack") == 0)
            mode = 1;
        else if (strcmp(token[0], "queue") == 0)
            mode = 0;
        else if (strcmp(token[0], "push") == 0 && mode == 0)
            exit_status = pk_pushq(&stack, token, linenum);
        else if (strcmp(token[0], "push") == 0 && mode == 1)
            exit_status = pk_push(&stack, token, linenum);
        else
            exit_status = execute(token, &stack, linenum);
        free(token);
        if (exit_status == EXIT_FAILURE)
            break;
    }
    stck_free(&stack);
    free(line);
    return (exit_status);
}

/**
 * tok_en - A function that splits the line.
 * @line: The pointer to the bytecode line.
 * @delim: Array with 5 delimiters " \n\t\a\b".
 * Return: The pointer to tokens.
 */
char **tok_en(char *line, char *delim)
{
    char *tokens = NULL, **token = NULL;
    size_t bufsize = 0;
    int i = 0;

    if (line == NULL || !*line)
        return (NULL);

    bufsize = strlen(line);
    if (bufsize == 0)
        return (NULL);
    token = malloc(bufsize * sizeof(char *));
    if (token == NULL)
    {
        fprintf(stderr, "Memory allocation error\n");
        exit(EXIT_FAILURE);
    }
    tokens = strtok(line, delim);
    if (tokens == NULL)
    {
        free(token);
        return (NULL);
    }
    while (tokens != NULL)
    {
        token[i] = tokens;
        i++;
        tokens = strtok(NULL, delim);
    }
    token[i] = NULL;
    return (token);
}

/**
 * get_line - A function that checks if the line only contains delimiters.
 * @line: The pointer to the line.
 * @delims: The string with delimiter characters.
 * Return: 1 if the line only contains delimiters, otherwise 0.
 */
int get_line(char *line, char *delims)
{
    int i, j;

    for (i = 0; line[i]; i++)
    {
        for (j = 0; delims[j]; j++)
        {
            if (line[i] == delims[j])
                break;
        }
        if (delims[j] == '\0')
            return (0);
    }

    return (1);
}

