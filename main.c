/*
* main.c - Entry point for Simpe shell project
* Author: Joana Casallas and Rodrigo Zárate A
* Date: August 21, 2021
*/

#include "simple_shell.h"

/**
* bi_exit - exit
* Return: always zero to change state
*/

int bi_exit(void)
{
	return(0);
}

/**
* bi_env - gets environ vars
* Return: always zero
*/

int bi_env(void)
{
int i = 0;
int str_len;

	/* get the environ */
	while (environ[i] != NULL)
	{
		/* walk the environ to count */
		str_len = countstr(environ[i]);
		/* print the environ */
		write(1, environ[i], str_len);
		write(1, "\n", 2);
		i++;
	}
	return (1);
}

/**
* main - Entry point
* Return: EXIT_SUCCESS
*/

int main(void)
{
/* config */
/* loop for commands */

	int state;
	char *input = NULL;
	char **args;
	char *builtinlist[] = {"env", "exit"};
	size_t bufferinput = 0;

	do {
	/* define prompt */
	if (isatty(0))
	{
		write(1, JR_PROMPT, 2);
	}
	input = read_input(&input, &bufferinput);
	/* start tokenization process */
	args = break_input(input);
	/* obtain info to break the loop */

	state = run_command(args, builtinlist);
	/* cleanup, free memory, etc */

	free(args);
	/* again */
	} while (state);
	free(input);
return (EXIT_SUCCESS);
}
