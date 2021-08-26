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
	char concat;
	struct stat statbuf; //error al compilar porque espacio desconocido
	char *variablePath = getVariableFromEnviron("PATH");
	char **pathdivided = tokenize(variablePath);
	char concat_temp;
	int i = 0;
	int j = 0;
	int x = 0;

for (i = 0; concat_temp[i] != NULL; i++)
{
	concat = str_concat(*concat_temp[i], *args);
	for (j = 0; pathdivided[j] != NULL; j++)
	{
		concat_temp[] = str_concat(*pathdivided[i][j], "/");
	}
	for (x = 0; temp[x] != NULL; x++)
	{
		free(concat_temp[x]);
	}
}

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
			exit(98);
	}
	else
	{
		wait(&status);
		break;
	}
}
}
return (0);
}
