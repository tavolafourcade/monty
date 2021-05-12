#include "monty.h"
/**
 * _open - open a file
 * @file_name: Path to the file
 */
void _open(char *file_name)
{
	fd_flags->fd_open = NULL;
	fd_flags->fd_open = fopen(file_name, "r");
	if (!fd_flags->fd_open)
	{
		dprintf(STDERR_FILENO, "Error: Can't open file %s\n",
			file_name);
		free(fd_flags);
		exit(EXIT_FAILURE);
	}
}
/**
 * checkdigits - function to check all the digits in the string
 * @s: string to evaluate
 * Return: 0 if they are not digits and 1 if they are
 */
int checkdigits(char *s)
{
	int a = 0;

	while (s[a] == '-')
	{
		a++;
		if (s[a] == '\0')
			return (0);
	}
	for (; s[a] != '\0'; a++)
	{
		if (!_isdigit(s[a]))
			return (0);
	}
	return (1);
}
/**
 * _isdigit - determinate if the character is a digit
 * @c: character to determinate
 * Return: Always 0. success
 */
int _isdigit(int c)
{
	if ((c >= '0') && (c <= '9'))
		return (1);
	else
		return (0);
}
/**
 * add - add the two elements at the top
 * @stack: stack memory
 * @line_number: line number of the file opened
 * Return: void
 */
void add(stack_t **stack, unsigned int line_number)
{
	if (!(*stack) || !(*stack)->next)
	{
		dprintf(STDERR_FILENO, "L%i: can't add, stack too short\n",
			line_number);
		free_listint(*stack);
		free(fd_flags->exec_opcode);
		free(fd_flags->buffer);
		fclose(fd_flags->fd_open);
		free(fd_flags);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n = (*stack)->n + (*stack)->next->n;
	pop(stack, line_number);
	(*stack)->prev = NULL;
}
/**
 * nop - do nothing like me
 * @stack: stack memory
 * @line_number: line number of the file opened
 * Return: void
 */
void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}
