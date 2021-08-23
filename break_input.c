/*
* break_input.c - Tokenizer for Simpe shell project
* Author: Joana Casallas and Rodrigo Zárate A
* Date: August 22, 2021
*/

#include "simple_shell.h"

#define TOKEN_BUFFER 64
#define TOKEN_DELIMITATOR " \a\r\t\n"

/**
* break_input - Create tokens
* @input: char pointer
* Return: char double pointer
*/

char **break_input(char *input)
{
int buffertoken = TOKEN_BUFFER, position = 0;
char **alltokens = malloc(buffertoken * sizeof(char *));
char *token;

printf("inside break_input-0\n");

	if (!alltokens)
	{
		exit(EXIT_FAILURE);
	}

	token = strtok(input, TOKEN_DELIMITATOR);
	while (token != NULL)
	{
		printf("inside break_input-1\n");
		alltokens[position] = token;
		printf("tok: %s \n", alltokens[position]);
		position++;

		if (position >= buffertoken)
		{
			printf("inside break_input-2\n");
			buffertoken += TOKEN_BUFFER;
			/* change realloc as is forbiden */
			alltokens = realloc(alltokens, buffertoken * sizeof(char *));
			if (!alltokens)
			{
				exit(EXIT_FAILURE);
			}
		}
	token = strtok(NULL, TOKEN_DELIMITATOR);
	}
/* end */
alltokens[position] = NULL;
/* send to execute command */
return (alltokens);
}
