/*
* main.c - Entry point for Simpe shell project
* Author: Joana Casallas and Rodrigo Zárate A
* Date: August 21, 2021
*/

#include "simple_shell.h"

/**
* bi_exit - exit
* @args: double poniter
* Return: always zero to change state
*/

int bi_exit(char **args)
{
	printf("inside exit-0\n");
	return (0);
}

/**
* bi_env - gets environ vars
* @args: double poniter
* Return: always zero
*/

int bi_env(char **args)
{
int i = 0;

printf("inside env-0\n");
	/* get the environ */
	/* print the environ */
	while(i < 10)
	{
		write(1, environ[i], 20);
		write(1, "\n", 2);
		i++;
	}
	return (1);
}

/**
* main - Entry point
* @argc: int
* @argv: char double pointer
* Return: EXIT_SUCCESS
*/

int main(int argc, char **argv)
{
/* config */
/* loop for commands */

	int state;
	char *input;
	char **args;
	char *builtinlist[] = {"env", "exit"};

	do {
	/* define prompt */
	write(1, JR_PROMPT, 2);
	input = read_input();
	/* start tokenization process */
	args = break_input(input);
	/* obtain info to break the loop */
	state = run_command(args, builtinlist);
	printf("state: %i", state);
	/* cleanup, free memory, etc */
	free(input);
	free(args);
	/* again */
	} while (state);

return (EXIT_SUCCESS);
}
