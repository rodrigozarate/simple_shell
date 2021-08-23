/*
* run_command.c - Call functions of shell project
* Author: Joana Casallas and Rodrigo Zárate A
* Date: August 21, 2021
*/

#include "simple_shell.h"

/**
* run_command - Run the given command
* @args: pointer
* @bilist: char built in list
* Return: war
*/

int run_command(char **args, char **builtinlist)
{
int i;

int (*builtinfunc[])(char **) = {&bi_env, &bi_exit};

printf("inside run_command-0\n");
	if (args[0] == NULL)
	{
		printf("inside run_command-1 arg = 0\n");
		/* Null error */
		return (1);
	}
	/* walk array of builtins */
	for (i = 0; i <= builtins(builtinlist); i++)
	{
		printf("inside run_command-2\n");
		/* 0, if the s1 and s2 are equal */
		if (strcmp(args[0], builtinlist[i]) == 0)
		{
			printf("inside run_command-3\n");
			printf("funn %s\n", builtinlist[i]);
			/* set the corresponding function */
			return ((*builtinfunc[i])(args));
		}
	}
/* ignition secuence started */
printf("to rok\n");
return (rocket(args));

}
