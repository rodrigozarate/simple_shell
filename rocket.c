/*
* rocket.c - Launch selected functions
* Author: Rodrigo Zárate Algecira and Joana Casallas
* Date: August 22, 2021
*/

#include "simple_shell.h"

/**
* rocket - launcher system
* @args: char
* Return: int
*/

int rocket(char **args)
{
	pid_t pid;
	char *concat;
	struct stat statbuf;
	char *variablePath = getVariableFromEnviron("PATH");
	char **pathdivided = tokenize(variablePath);
	char *concat_temp;
	int i = 0, status = 0, execute = 0;

for (i = 0; pathdivided[i] != NULL; i++)
{
	concat_temp = str_concat(pathdivided[i], "/");
	concat = str_concat(concat_temp, *args);
	if (stat(concat, &statbuf) == 0)
	{
		pid = fork();
		if (pid == -1)
		{
			perror("Error:");
			return (1);
		}
		if (pid == 0)
		{
		execute = execve(concat, args, environ);
		if (execute == -1)
			exit(errno);
		}
		else
		{
		wait(&status);
		break;
		}
	}
	free(concat_temp);
	free(concat);
}
return (1);
}
