#include "monty.h"
/**
 * push - pushes a item in the stack
 * @stack: stack memory
 * @line_number: line number of the file opened
 * Return: void
 */
void push(stack_t **stack, unsigned int line_number)
{

	if (!fd_flags->integer || !checkdigits(fd_flags->integer))
	{
		dprintf(STDERR_FILENO, "L%i: usage: push integer\n",
			line_number);
		free_listint(*stack);
		free(fd_flags->exec_opcode);
		free(fd_flags->buffer);
		fclose(fd_flags->fd_open);
		free(fd_flags);
		exit(EXIT_FAILURE);
	}
	if (!fd_flags->queueFlag) /* STACK */
	{
		if (!fd_flags->queueFlag)
			add_dnodeint(stack, _atoi(fd_flags->integer));
		else
			add_dnodeint_end(stack, _atoi(fd_flags->integer));
	}
	else /* QUEUE */
	{
		if (!fd_flags->queueFlag)
			add_dnode_at_index(stack, fd_flags->stack_index,
			_atoi(fd_flags->integer));
		else
			add_dnodeint_end(stack, _atoi(fd_flags->integer));
		fd_flags->stack_index++;
	}
}
/**
 * pall - prints all the values on the stack,
 * starting from the top of the stack
 * @stack: stack memory
 * @line_number: line number of the file opened
 * Return: void
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *aux = NULL;

	aux = *stack;
	(void)line_number;
	while (aux)
	{
		printf("%i\n", aux->n), aux = aux->next;
	}
}
/**
 * pint - prints the top of the stack
 * @stack: stack memory
 * @line_number: line number of the file opened
 * Return: void
 */
void pint(stack_t **stack, unsigned int line_number)
{
	if (!*stack)
	{
		dprintf(STDERR_FILENO, "L%i: can't pint, stack empty\n",
			line_number);
		free_listint(*stack);
		free(fd_flags->exec_opcode);
		free(fd_flags->buffer);
		fclose(fd_flags->fd_open);
		free(fd_flags);
		exit(EXIT_FAILURE);
	}
	printf("%i\n", (*stack)->n);
}
/**
 * pop - delete the top of the stack
 * @stack: stack memory
 * @line_number: line number of the file opened
 * Return: void
 */
void pop(stack_t **stack, unsigned int line_number)
{
	if (!*stack)
	{
		dprintf(STDERR_FILENO, "L%i: can't pop an empty stack\n",
			line_number);
		free_listint(*stack);
		free(fd_flags->exec_opcode);
		free(fd_flags->buffer);
		fclose(fd_flags->fd_open);
		free(fd_flags);
		exit(EXIT_FAILURE);
	}
	if (!(*stack)->next)
		free(*stack);
	else
	{
		*stack = (*stack)->next;
		free((*stack)->prev);
		(*stack)->prev = NULL;
	}
}
/**
 * swap - swap the two elements at the top
 * @stack: stack memory
 * @line_number: line number of the file opened
 * Return: void
 */
void swap(stack_t **stack, unsigned int line_number)
{
	if (!(*stack) ||  !(*stack)->next)
	{
		dprintf(STDERR_FILENO, "L%i: can't swap, stack too short\n",
			line_number);
		free_listint(*stack);
		free(fd_flags->exec_opcode);
		free(fd_flags->buffer);
		fclose(fd_flags->fd_open);
		free(fd_flags);
		exit(EXIT_FAILURE);
	}
	*stack = (*stack)->next;
	(*stack)->prev->next = (*stack)->next;
	(*stack)->prev->prev = *stack;
	(*stack)->next->prev = (*stack)->prev;
	(*stack)->next = (*stack)->prev;
	(*stack)->prev = NULL;
}
