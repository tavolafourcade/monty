#include "monty.h"
/**
 * _div - div the two elements at the top
 * @stack: stack memory
 * @line_number: line number of the file opened
 * Return: void
 */
void _div(stack_t **stack, unsigned int line_number)
{
	if (!(*stack) || !(*stack)->next)
	{
		dprintf(STDERR_FILENO, "L%i: can't div, stack too short\n",
			line_number);
		free_listint(*stack);
		free(fd_flags->exec_opcode);
		free(fd_flags->buffer);
		fclose(fd_flags->fd_open);
		free(fd_flags);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		dprintf(STDERR_FILENO, "L%i: division by zero\n", line_number);
		free_listint(*stack);
		free(fd_flags->exec_opcode);
		free(fd_flags->buffer);
		fclose(fd_flags->fd_open);
		free(fd_flags);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n = (*stack)->next->n / (*stack)->n;
	*stack = (*stack)->next;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
/**
 * mod - sub the two elements at the top
 * @stack: stack memory
 * @line_number: line number of the file opened
 * Return: void
 */
void mod(stack_t **stack, unsigned int line_number)
{
	if (!(*stack) || !(*stack)->next)
	{
		dprintf(STDERR_FILENO, "L%i: can't mod, stack too short\n",
			line_number);
		free_listint(*stack);
		free(fd_flags->exec_opcode);
		free(fd_flags->buffer);
		fclose(fd_flags->fd_open);
		free(fd_flags);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		dprintf(STDERR_FILENO, "L%i: division by zero\n", line_number);
		free_listint(*stack);
		free(fd_flags->exec_opcode);
		free(fd_flags->buffer);
		fclose(fd_flags->fd_open);
		free(fd_flags);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n = (*stack)->next->n % (*stack)->n;
	*stack = (*stack)->next;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
/**
 * pchar - prints the integer stored at the top of the stack
 * in the ASCII code
 * @stack: stack memory
 * @line_number: line number of the file opened
 * Return: void
 */
void pchar(stack_t **stack, unsigned int line_number)
{
	if (!(*stack))
	{
		dprintf(STDERR_FILENO, "L%i: can't pchar, stack empty\n",
			line_number);
		free_listint(*stack);
		free(fd_flags->exec_opcode);
		free(fd_flags->buffer);
		fclose(fd_flags->fd_open);
		free(fd_flags);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n < 0 || (*stack)->n > 127)
	{
		dprintf(STDERR_FILENO, "L%i: can't pchar, value out of range\n",
			line_number);
		free_listint(*stack);
		free(fd_flags->exec_opcode);
		free(fd_flags->buffer);
		fclose(fd_flags->fd_open);
		free(fd_flags);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", (*stack)->n);
}
/**
 * rotl - rotate the top of the stack to the bottom
 * @stack: stack memory
 * @line_number: line number of the file opened
 * Return: void
 */
void rotl(stack_t **stack, unsigned int line_number)
{
	int n;

	(void)line_number;
	if ((*stack) || (*stack)->next)
	{
		n = (*stack)->n;
		(*stack) = (*stack)->next;
		free((*stack)->prev);
		(*stack)->prev = NULL;
		add_dnodeint_end(stack, n);
	}
}
/**
 * _atoi - transform a char in an integer
 * @s: variable
 * Return: value
 */

int _atoi(char *s)
{
	int value = 0, i = 0, neg = -1;

	while (s[i] != '\0' && (s[i] < '0' || s[i] > '9'))
	{
		if (s[i] == '-')
			neg *= -1;
		i++;
	}
	while (s[i] != '\0' && (s[i] >= '0' && s[i] <= '9'))
		value = (value * 10) - (s[i++] - '0');
	return (value * neg);
}
