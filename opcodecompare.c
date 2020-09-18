#include "global.h"
#include "monty.h"
/**
 *opcodecompare - compares opcodes and runs associated functions
 *@stack: pointer to the top of the stack
 *@line_number: line number of command
 *@opcode: the opcode for Monty interpretor
 *
 *Return: void
 */
void opcodecompare(stack_t **stack, unsigned int line_number, char *opcode)
{
	int i = 0;

	instruction_t ops[] = {
		{"push", push}, {"pall", pall}, {"pint", pint},
		{"pop", pop}, {"swap", swap}, {"add", add},
		{"nop", nop}, {"sub", sub}, {"div", divide},
		{"mul", mul}, {"mod", mod}, {"pchar", pchar},
		{NULL, NULL}
	};

	while (ops[i].opcode != NULL)
	{
		if (_strcmp(opcode, ops[i].opcode) == 0)
		{
			ops[i].f(stack, line_number);
			return;
		}
		i++;
	}

	printf("L%u: unknown instruction %s\n", line_number, opcode);
	exit(EXIT_FAILURE);
}
