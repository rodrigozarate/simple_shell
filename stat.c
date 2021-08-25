#include "simple_shell.h"
#include <sys/stat.h>

/**
 * statFunction - find and excecute the command in the path.
 * @args: arguments
 * @stringsPath: divided PATH
 * Return: 0: exit or -1: failed
 */
int statFunction(char **args, char **stringsPath)
{
	struct stat statbuf;
	int pid, execute, buffer;

	if (stat(stringsPath[0], &statbuf) == -1)
	{
		perror("not found");
		exit(1);
	}
	if (statbuf.st_mode &  S_IFDIR)
	{
		pid = fork();
		if (pid == -1)
		{
			perror("Error:");
			return (1);
		}
		if (pid == 0)
		{
			execute = execve(buffer, args, environ);
			if (execute == -1)
				exit(98);
		}
	}
	else
	{
		perror("not found");
		return (0);
	}
}
