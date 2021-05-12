#include "monty.h"
/**
 * freedp - frees a double pointer
 * @str: double pointer
 * Return: void
 */
void freedp(char **str)
{
	int i = 0;

	while (str[i])
		free(str[i]), i++;
	free(str);
}
/**
 * init_instruction - initializes the function pointer array
 * Return: A pointer to the funciton pointer or NULL on error
 */
instruction_t *init_instruction(void)
{
	instruction_t _list[] = {
		{"push", push}, {"pall", pall}, {"pint", pint}, {"pop", pop},
		{"swap", swap}, {"add", add}, {"nop", nop}, {"sub", sub},
		{"div", _div}, {"mul", mul}, {"mod", mod}, {"pchar", pchar},
		{"pstr", pstr}, {"rotl", rotl}, {"rotr", rotr}, {NULL, NULL}
	};
	instruction_t *init_f = NULL;
	int i = 0;

	init_f = malloc(sizeof(instruction_t) * 16);
	if (!init_f)
	{
		dprintf(STDERR_FILENO, "Error: malloc failed\n");
		fclose(fd_flags->fd_open);
		free(fd_flags);
		exit(EXIT_FAILURE);
	}
	while (i < 16)
		init_f[i] = _list[i], i++;
	return (init_f);
}
/**
 * check - auxiliar check for queue, stack command or comments
 * @str: pointer to the command
 * @stack: stack
 * Return: 1 if there is one this command 0 if not
 */
int check(char *str, stack_t **stack)
{
	int aux = 0;

	if (str && !strcmp(str, "queue"))
		fd_flags->queueFlag = 1, fd_flags->stack_index = 0, aux = 1;
	if (str && !strcmp(str, "stack"))
		fd_flags->queueFlag = 0, aux = 1;
	if (str && str[0] == '#')
		nop(stack, fd_flags->linecounter), aux = 1;

	return (aux);
}
/**
 * _run - executes the bytecode line by line
 * Return: void
 */
void _run(void)
{
	int j = 0;
	size_t len = 0;
	stack_t *stack = NULL;

	fd_flags->exec_opcode = NULL, fd_flags->linecounter = 1;
	fd_flags->stack_index = 0, fd_flags->queueFlag = 0;
	fd_flags->lines = NULL, fd_flags->exec_opcode = init_instruction();
	fd_flags->buffer = NULL, fd_flags->integer = NULL;
	while (getline(&(fd_flags->buffer), &len, fd_flags->fd_open) != EOF)
	{
		fd_flags->lines = strtok(fd_flags->buffer, " \t\n");
		fd_flags->integer = strtok(NULL, " \t\n");
		if (check(fd_flags->lines, &stack) || !fd_flags->lines)
		{
			free(fd_flags->buffer), fd_flags->lines = NULL;
			fd_flags->buffer = NULL, fd_flags->integer = NULL;
			fd_flags->linecounter++;
			continue;
		}
		while (j < 16)
		{
			if (fd_flags->exec_opcode[j].f == NULL)
			{
				dprintf(STDERR_FILENO,
					"L%i: unknown instruction %s\n",
					fd_flags->linecounter, fd_flags->lines);
				superfree(stack);
			}
			if (!strcmp(fd_flags->exec_opcode[j].opcode,
					fd_flags->lines))
			{
				fd_flags->exec_opcode[j].f(&stack,
					fd_flags->linecounter);
				break;
			} j++;
		} j = 0, fd_flags->linecounter++;
		free(fd_flags->buffer), fd_flags->lines = NULL;
		fd_flags->buffer = NULL, fd_flags->integer = NULL;
	} free_listint(stack), free(fd_flags->exec_opcode);
}
/**
 * main - entry point
 * @argc: number of arguments supplied to the program by the command line
 * @argv: arrays of pointers to the arguments supplied to the program
 * Return: EXIT_SUCCESS on success or EXIT_FAILURE on failure
 */
int main(int argc, char *argv[])
{
	char *file_name = NULL;

	file_name = argv[1];
	if (argc != 2)
	{
		dprintf(STDERR_FILENO, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	fd_flags = malloc(sizeof(info));
	if (!fd_flags)
	{
		dprintf(STDERR_FILENO, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	_open(file_name);/* open file */
	_run();
	free(fd_flags->buffer);
	fclose(fd_flags->fd_open);
	free(fd_flags);
	return (EXIT_SUCCESS);
}
