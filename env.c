#include "simple_shell.h"

/**
 * getVariableFromEnviron - Find path
 * @variableName: env variable name
 * return: return path-line
 */

char *getVariableFromEnviron(char *variableName)
{
	int i = 0;
	int j = 0;

	for (; environ[i] != NULL; i++)
	{
		for (j = 0; variableName[j] == environ[i][j]; j++)
		{
		}
		if (variableName[j] == '\0' && environ[i][j] == '=')
		{
			return (environ[i] + j + 1);
		}
	}
	return (NULL);
}

/**
 * tokenize - extract directories within path
 * @string: directories name
 * return: return directories within the path
 */

char **tokenize(char *string)
{
	char **tokenized = NULL;
	size_t i = 0;

	tokenized = malloc(sizeof(char *) * 1024);
	tokenized[0] = strtok(string, ":");
	while (tokenized[i])
	{
		i++;
		tokenized[i] = strtok(NULL, ":");
	}
	return (tokenized);
}
