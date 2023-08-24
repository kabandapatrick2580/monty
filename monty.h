#ifndef __MONTY_H__
#define __MONTY_H__
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO project
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

int main(int ac, char **av);

void stck_free(stack_t **stack);

int pk_run(FILE *fd);
char **tok_en(char *line, char *delim);
int get_line(char *line, char *delims);

int execute(char **token, stack_t **stack, unsigned int linenum);
int pk_push(stack_t **stack, char **token, unsigned int linenum);
int pk_pushq(stack_t **stack, char **token, unsigned int linenum);
void pk_pall(stack_t **stack, unsigned int linenum);
void pk_pint(stack_t **stack, unsigned int linenum);
void pk_pop(stack_t **stack, unsigned int linenum);
void pk_swap(stack_t **stack, unsigned int linenum);
void pk_sub(stack_t **stack, unsigned int linenum);
void pk_add(stack_t **stack, unsigned int linenum);
void pk_mul(stack_t **stack, unsigned int line_number);
void pk_div(stack_t **stack, unsigned int line_number);
void pk_mod(stack_t **stack, unsigned int line_number);
void pk_pchar(stack_t **stack, unsigned int line_number);
void pk_pstr(stack_t **stack, unsigned int line_number);
void pk_rotl(stack_t **stack, unsigned int line_number);
void pk_rotr(stack_t **stack, unsigned int line_number);
int error_usage(int drapeau);
int open_error(char *filename);
int show_f_errors(int drapeau, unsigned int linenum);

#endif /* __MONTY_H__ */
