/*
* read_input.c - reads stdin
* Author: Rodrigo Zárate Algecira and Joana Casallas
* Date: August 21, 2021
*/

/**
* read_input - Reads stdin
* Return: Char
*/

char *read_input(void)
{
char *input = NULL;
ssize_t bufferinput = 0;

	/* check if getline works */
	if (getline(&input, &bufferinput, stdin) == -1)
	{
		if (feof(stdin))
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
