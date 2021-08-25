/*
* read_input.c - reads stdin
* Author: Rodrigo Zárate Algecira and Joana Casallas
* Date: August 21, 2021
*/

#include "simple_shell.h"

/**
* read_input - Reads stdin
* Return: Char
*/

char *read_input(void)
{
char *input = NULL;
size_t bufferinput = 0;
ssize_t readchar;
readchar = getline(&input, &bufferinput, stdin);

	/* check if getline works */
	if (readchar == -1)
	{
		/* non zero if is set */
		/* change verification method */
		if (readchar == EOF)
		{
			/* reach the end */
			exit(EXIT_SUCCESS);
		}
		else
		{
			/* any error */
			perror("read_input");
			exit(EXIT_FAILURE);
		}
	}
return (input);
}
