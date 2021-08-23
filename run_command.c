/*
* run_command.c - Call functions of shell project
* Author: Joana Casallas and Rodrigo Zárate A
* Date: August 21, 2021
*/

#include "simple_shell.h"

/**
* run_command - Run the given command
* @args: pointer
* Return: war
*/

int run_command(char **args)
{
int i;
char *builtinlist[] = {"env", "exit"};

int (*builtinfunc[])(char **) = {&bi_env, &bi_exit};

	if (args[0] == NULL)
	{
		/* Null error */
		return (1);
	}
	/* walk array of builtins */
	for (i = 0; i < builtins(); i++)
	{
		if (strcmp(args[0], builtinlist[i]) == 0)
		{
			/* set the corresponding function */
			return ((*builtinfunc[i])(args));
		}
	}
/* ignition secuence started */
return (rocket(args));
}
