#ifndef MONTY_H
#define MONTY_H

/* Libraries */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

/* Structures */

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
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
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;
/**
 * struct info - information about the file, flags and linecounter
 * @fd_open: file descriptor
 * @linecounter: count the lines
 * @number: number
 * @buffer: buffer getline
 * @queueFlag: flag to know is a queue
 * @integer: data of the integer
 * @stack_index: keep the index to add when a queue is on
 * @lines: content of the file in lines
 * @exec_opcode: opcodes
 */
typedef struct info
{
	FILE *fd_open;
	int linecounter;
	int queueFlag;
	char *integer;
	int number;
	int stack_index;
	char *buffer;
	char *lines;
	instruction_t *exec_opcode;
} info;

/* Global Variables */
info *fd_flags;
/* Prototypes */
int init_vars(info *fd_flags);
void _open(char *file_name);
void _run(void);
int check(char *str, stack_t **stack);
void push(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);
void pint(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);
void swap(stack_t **stack, unsigned int line_number);
void add(stack_t **stack, unsigned int line_number);
void nop(stack_t **stack, unsigned int line_number);
void sub(stack_t **stack, unsigned int line_number);
void mul(stack_t **stack, unsigned int line_number);
void _div(stack_t **stack, unsigned int line_number);
void mod(stack_t **stack, unsigned int line_number);
void pchar(stack_t **stack, unsigned int line_number);
void pstr(stack_t **stack, unsigned int line_number);
void rotl(stack_t **stack, unsigned int line_number);
void rotr(stack_t **stack, unsigned int line_number);
int checkdigits(char *s);
void free_listint(stack_t *stack);
int _isdigit(int c);
int _atoi(char *s);
stack_t *add_dnodeint(stack_t **stack, const int n);
stack_t *add_dnodeint_end(stack_t **stack, const int n);
stack_t *add_dnode_at_index(stack_t **stack, unsigned int idx, int n);
int delete_dnodeint_at_index(stack_t **stack, unsigned int index);
char **str_tok(char *str, char *delimiter);
void freedp(char **str);
void superfree(stack_t *stack);
char *_strtok(char *arg, char *dlm);


#endif /* MONTY_H */
