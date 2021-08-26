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
	int i;
	int state;

	state = stat(stringsPath, &statbuf);

	if (state == -1)
	{
		perror("not found");
		exit(1);
	}
	else
	{
		for (i = 0; state != -1; i++)
		{
			if (statbuf.st_mode &  S_IFDIR)
			{
				rocket(args);
			}
			else
			{
				perror("not found");
			}
		}
	}
			return (0);
		}
