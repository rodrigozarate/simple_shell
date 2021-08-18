#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <wait.h>
#include <sys/types.h>
#include "shell.h"


int getStringLength(char *string)
{
	int i = 0;
	while (string[i])
	{
		i++;
	}
}


int countPipes(char text[]){ /*verificamos si hay pipes*/
	if(strchr(text, '|')!=NULL){
		return (1);
	}
	return (0);
}


int countRedirection(char text[]){ /*verificamos si hay simbolo de redireccion*/
	if(strchr(text, '>')!=NULL){
		return (1);
	}
	return (0);
}

void split(char text[], char *splittedtext[], char DELIM[]){ /*dividimos el texto en 2: en antes de .. y en despues de...*/
	char *tokenpointer;
	int i = 0;
	tokenpointer = strtok(text, DELIM);

	while(tokenpointer != NULL){
		splittedtext[i] = tokenpointer;
		tokenpointer = strtok(NULL, DELIM);
		i++;
	}
}
