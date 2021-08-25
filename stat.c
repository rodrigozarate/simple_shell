#include "simple_shell.h"
#include <sys/stat.h>

/**
 * statFunction - find and excecute the command in the path.
 * @args: arguments
 * @stringsPath: divided PATH
 * Return: 0: exit or -1: failed
 */


int statFunction(char **stringsPath, char **args)
{
	struct stat statbuf;

	if (stat(stringsPath, &statbuf) == -1)
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
			rocket(args);
		}
	}
	else
	{
		perror("not found");
	}
	return (0);
}
