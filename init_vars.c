#include "monty.h"
/**
 * init_vars - init variables
 * @fd_flags: element of the struct
 * Return: 0 success
 */
int init_vars(info *fd_flags)
{
	fd_flags->fd_open = NULL;
	fd_flags->linecounter = 0;
	fd_flags->queueFlag = 0;
	fd_flags->integer = NULL;
	fd_flags->number = 0;
	fd_flags->stack_index = 0;
	fd_flags->buffer = NULL;
	fd_flags->lines = NULL;
	fd_flags->exec_opcode = NULL;
	exit(EXIT_SUCCESS);
}
