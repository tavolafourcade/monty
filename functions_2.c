#include "monty.h"
/**
 * sub - subtracts the two elements at the top
 * @stack: stack memory
 * @line_number: line number of the file opened
 * Return: void
 */
void sub(stack_t **stack, unsigned int line_number)
{
	if (!(*stack) || !(*stack)->next)
	{
		dprintf(STDERR_FILENO, "L%i: can't sub, stack too short\n",
			line_number);
		free_listint(*stack);
		free(fd_flags->exec_opcode);
		free(fd_flags->buffer);
		fclose(fd_flags->fd_open);
		free(fd_flags);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n = (*stack)->next->n - (*stack)->n;
	*stack = (*stack)->next;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
/**
 * mul - multiplies the two elements at the top
 * @stack: stack memory
 * @line_number: line number of the file opened
 * Return: void
 */
void mul(stack_t **stack, unsigned int line_number)
{
	if (!(*stack) || !(*stack)->next)
	{
		dprintf(STDERR_FILENO, "L%i: can't mul, stack too short\n",
			line_number);
		free_listint(*stack);
		free(fd_flags->exec_opcode);
		free(fd_flags->buffer);
		fclose(fd_flags->fd_open);
		free(fd_flags);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n = (*stack)->next->n * (*stack)->n;
	*stack = (*stack)->next;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
/**
 * pstr - prints the string starting at the top of the stack, followed by a new
 * line
 * @stack: stack memory
 * @line_number: line number of the file opened
 * Return: void
 */
void pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *aux = *stack;

	(void)line_number;
	while (aux && aux->n > 0)
	{
		if (aux->n < 0 || aux->n > 127)
			break;
		putchar(aux->n);
		aux = aux->next;
	}
	putchar('\n');
}
/**
 * rotr - rotates the stack to the bottom
 * @stack: stack memory
 * @line_number: line number of the file opened
 * Return: void
 */
void rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *aux = NULL;

	(void)line_number;
	if (*stack && (*stack)->next)
	{
		aux = *stack;
		while (aux->next)
			aux = aux->next;
		aux->prev->next = NULL;
		aux->next = *stack;
		aux->prev = NULL;
		(*stack)->prev = aux;
		*stack = aux;
	}
}
/**
 * superfree - frees all
 * @stack: stack
 * Return: void
 */
void superfree(stack_t *stack)
{
	free_listint(stack), free(fd_flags->exec_opcode);
	fclose(fd_flags->fd_open), free(fd_flags->buffer);
	free(fd_flags);
	exit(EXIT_FAILURE);
}
