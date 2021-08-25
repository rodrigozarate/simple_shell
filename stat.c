#include "simple_shell.h"
#include <sys/stat.h>

/**
 * statFunction - find and excecute the command in the path.
 * @argc: cant arguments
 * @argv: list arguments
 * Return: 0: exit or -1: failed
 */
int statFunction(int argc, char **argv)
{
	struct stat statbuf;
	int error = 0;
	int pid, execute, buffer, args;

	if (stat(argv[0], &statbuf) == -1)
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
		return (error);
	}
}
