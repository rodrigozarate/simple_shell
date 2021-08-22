#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

/**
 * main: main function
 *
 * return: 0
 */

//int _getline(char **text, size_t *n, FILE *stream);

int main()
{
	char *prompt = "$";
	size_t numero_bytes = 0;
	char *cadena;
	int bytes_leidos;

	write(STDOUT_FILENO, prompt, strlen(prompt));
	bytes_leidos = getline(&cadena, &numero_bytes, stdin);
	if (bytes_leidos == -1)
	{
		puts("error");
	}
	else
	{
		puts(cadena);
	}
	return (0);
}
/**
int _getline(char **text, size_t *n, FILE *stream)
{
	char line = 1024;
	char *ptr;
	unsigned int len;

	if (text == NULL || n == NULL)
	{
		return -1;
	}
	fgets(line,256,stream);

	ptr = strchr(line,'\n');
	if (ptr)
		*ptr = '\0';

	len = strlen(line);

	if ((len+1) < 256)
	{
		ptr = realloc(*text, 256);
		if (ptr == NULL)
			return(-1);
		*text = ptr;
		*n = 256;
	}

	strcpy(*text,line);
	return(len);
}
*/
