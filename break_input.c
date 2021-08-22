/*
* break_input.c - Tokenizer for Simpe shell project
* Author: Joana Casallas and Rodrigo Zárate A
* Date: August 22, 2021
*/

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
char **alltokens = malloc(buffertoken * sizeof(char*));
char *token;

	if (!alltokens)
	{
		fprintf(stderr, "Malloc fails\n");
		exit(EXIT_FAILURE);
	}

	token = strtok(input, TOKEN_DELIMITATOR);
	while (token != NULL)
	{
		alltokens[position] = token;
		position++;

		if (position >= buffertoken)
		{
			buffertoken += TOKEN_BUFFER;
			alltokens = realloc(alltokens, buffertoken * sizeof(char*));
			if (!alltokens)
			{
				fprintf(stderr, "Malloc fails\n");
				exit(EXIT_FAILURE);
			}
		}
	token = strtok(NULL, TOKEN_DELIMITATOR);
	}
/* end */
alltokens[position] = NULL;
return tokens;
}
