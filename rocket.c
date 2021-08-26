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
pid_t pid, w_pid;
int state;
char **env = environ;
int here = 0;
char concat;
int active;
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

i = 0;
j = 0;

active = statFunction(**pathdivided[i], concat[j]);
	if (active == -1)
{
		perror("Error");
}
	else
	{
pid = fork();
	if (pid == 0)
	{
		/* on path args should be changed */
		/* its child */
		if (execve(concat[0], args, env) == -1)
		{
			perror("Error");
		}
		exit(EXIT_FAILURE);
	}
	else if (pid < 0)
	{
		/* forking failed */
		perror("Fork failed");
	}
	else
	{
		/* Parent process */
		do {
			w_pid = waitpid(pid, &state, WUNTRACED);
			if (w_pid == 0)
			{
				here++;
			}
		} while (!WIFEXITED(state) && !WIFSIGNALED(state));
	}
	}
	/* always 1 */
return (1);
}
