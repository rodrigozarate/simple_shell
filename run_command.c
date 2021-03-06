/*
 * run_command.c - Call functions of shell project
 * Author: Joana Casallas and Rodrigo Zárate A
 * Date: August 21, 2021
 */

#include "simple_shell.h"

/**
 * run_command - Run the given command
 * @args: pointer
 * @builtinlist: char built in list
 * Return: war
 */

int run_command(char **args, char **builtinlist)
{

int i, lar;

	int (*builtinfunc[])() = {&bi_env, &bi_exit};

lar = sizeof(builtinfunc)/sizeof(builtinfunc[0]);

	if (args[0] == NULL)
	{
		/* Null error */
		return (1);
	}
	/* walk array of builtins */
	for (i = 0; i < lar; i++)
	{
		/* 0, if the s1 and s2 are equal */
		if (str_comp(args[0], builtinlist[i]) == 0)
		{
			/* set the corresponding function */
			return ((*builtinfunc[i])(args));
		}
	}
	/* ignition secuence started */
	return (rocket(args));
}
