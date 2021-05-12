#include "monty.h"
/**
 * add_dnodeint - function that adds a new node at the beginning of a
 * stack_t list
 * @stack: stack of the list
 * @n: data (integer)
 * Return: address of the new element, or NULL if it failed
 */
stack_t *add_dnodeint(stack_t **stack, const int n)
{
	stack_t *new_node = NULL;

	if (!stack)
		return (NULL);
	new_node = malloc(sizeof(stack_t));
	if (!new_node)
	{
		dprintf(STDERR_FILENO, "Error: malloc failed\n");
		free_listint(*stack);
		free(fd_flags->exec_opcode);
		free(fd_flags->buffer);
		fclose(fd_flags->fd_open);
		free(fd_flags);
		exit(EXIT_FAILURE);
	}
	new_node->n = n;
	if (!*stack)
	{
		new_node->prev = *stack, new_node->next = NULL;
		*stack = new_node;
	}
	else
	{
		new_node->next = *stack, new_node->prev = NULL;
		new_node->next->prev = new_node, *stack = new_node;
	}

	return (new_node);
}
/**
 * add_dnodeint_end - function that adds a new node at the end of a stack_t
 * list
 * @stack: stack of the list
 * @n: data
 * Return: the address of the new element, or NULL if it failed
*/
stack_t *add_dnodeint_end(stack_t **stack, const int n)
{
	stack_t *new_node = NULL;

	if (!stack)
		return (NULL);
	new_node = malloc(sizeof(stack_t));
	if (!new_node)
	{
		dprintf(STDERR_FILENO, "Error: malloc failed\n");
		free_listint(*stack);
		free(fd_flags->exec_opcode);
		free(fd_flags->buffer);
		fclose(fd_flags->fd_open);
		free(fd_flags);
		exit(EXIT_FAILURE);
	}
	new_node->n = n;
	if (!*stack) /* Empty list */
	{
		new_node->next = NULL, new_node->prev = NULL;
		*stack = new_node;
	}
	else
	{
		new_node->next = *stack;
		while (new_node->next->next)
			new_node->next = new_node->next->next;
		new_node->next->next = new_node;
		new_node->prev = new_node->next;
		new_node->next = NULL;
	}

	return (new_node);
}
/**
 * add_dnode_at_index - function that inserts a new node at a given
 * position
 * @stack: head of the list
 * @idx: index
 * @n: data
 * Return: the address of the new node, or NULL if it failed
 */
stack_t *add_dnode_at_index(stack_t **stack, unsigned int idx, int n)
{
	stack_t *aux = NULL, *new_node = NULL;
	unsigned int i = 0;

	if (!stack)
		return (NULL);
	if (idx)
	{
		aux = *stack;
		while (aux && i < idx - 1)
			aux = aux->next, i++;
		if (!aux)
			return (NULL);
	}
	new_node = malloc(sizeof(stack_t));
	if (!new_node)
	{
		dprintf(STDERR_FILENO, "Error: malloc failed\n");
		free_listint(*stack);
		free(fd_flags->exec_opcode);
		free(fd_flags->buffer);
		fclose(fd_flags->fd_open);
		free(fd_flags);
		exit(EXIT_FAILURE);
	}
	new_node->n = n;
	if (!idx)
	{
		new_node->prev = NULL, new_node->next = *stack;
		*stack = new_node;
	}
	else
	{
		new_node->prev = aux, new_node->next = aux->next;
		aux->next = new_node;
	}
	if (new_node->next)
		new_node->next->prev = new_node;

	return (new_node);
}
/**
 *delete_dnodeint_at_index - function that deletes the node at index index of a
 *stack_t linked list
 *@stack: stack of the list
 *@index: index
 *Return: 1 if it succeeeded, -1 if it failed
 */
int delete_dnodeint_at_index(stack_t **stack, unsigned int index)
{
	stack_t *aux = NULL;
	unsigned int i = 0;

	if (!stack || !*stack)
		return (-1);
	aux = *stack;
	if (!index)
	{
		*stack = aux->next;
		if (aux->next)
			aux->next->prev = NULL;
		free(aux);
	}
	else
	{
		while (aux && i < index)
			aux = aux->next, i++;
		if (!aux)
			return (-1);
		if (aux->next)
			aux->next->prev = aux->prev;
		aux->prev->next = aux->next;
		free(aux);
	}
	return (1);
}
/**
 * free_listint - free the linked list.
 * @head: the inital pointer to the linked list
 * Return: void
 */
void free_listint(stack_t *head)
{
	stack_t *tmp;

	while (head)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
}
