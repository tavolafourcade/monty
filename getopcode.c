#include "monty.h"
#include "global.h"
/**
 *getopcode - obtains the opcode of a Monty file from a global buffer
 *
 *Return: pointer to a string containing the opcode
 */
char *getopcode(void)
{
	int i = 0, j = 0;
	char *opcodebuffer;

	opcodebuffer = malloc(sizeof(char) * 10);
	if (opcodebuffer == NULL)
		return (NULL);

	while (line[i] == ' ')
		i++;
	while (line[i] != ' ' && line[i] != '\0')
	{
		opcodebuffer[j] = line[i];
		i++;
		j++;
	}
	opcodebuffer[j] = '\0';
	return (opcodebuffer);
}
