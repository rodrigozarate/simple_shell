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

printf("inside rocket-0\n");
pid = fork();
	if (pid == 0)
	{
		printf("inside rocket-1\n");
		/* its child */
		if (execve(args[0], args, env) == -1)
		{
			printf("inside rocket-2\n");
			perror("No argument");
		}
		exit(EXIT_FAILURE);
	}
	else if (pid < 0)
	{
		printf("inside rocket-3\n");
		/* forking failed */
		perror("Fork failed");
	}
	else
	{
		printf("inside rocket-4\n");
		/* Parent process */
		do {
			printf("inside rocket-5\n");
			w_pid = waitpid(pid, &state, WUNTRACED);
		} while (!WIFEXITED(state) && !WIFSIGNALED(state));
	}
/* always 1 */
return (1);
}
