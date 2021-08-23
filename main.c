/*
* main.c - Entry point for Simpe shell project
* Author: Joana Casallas and Rodrigo Zárate A
* Date: August 21, 2021
*/

#include "simple_shell.h"

/**
* bi_exit - exit
* @args: double poniter
* Return: always zero
*/

int bi_exit(char **args)
{
	return (0);
}

/**
* bi_env - gets environ vars
* @args: double poniter
* Return: always zero
*/

int bi_env(char **args)
{
	/* get the environ */
	/* print the environ */
	return (0);
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
	printf("JR_PROMPT");
	input = read_input();
	/* start tokenization process */
	args = break_input(input);
	/* obtain info to break the loop */
	state = run_command(args, builtinlist);

	/* cleanup, free memory, etc */
	free(input);
	free(args);
	printf("JR_PROMPT");
	} while (state);

return (EXIT_SUCCESS);
}
