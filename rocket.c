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

	pid = fork();
	if (pid == 0)
	{
		/* on path args should be changed */
		/* its child */
		if (execve(args[0], args, env) == -1)
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
/* always 1 */
return (1);
}
