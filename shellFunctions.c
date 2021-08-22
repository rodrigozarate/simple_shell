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


int checkPipes(char text[]){ /*verificamos si hay pipes*/
	if(strchr(text, '|')!=NULL){
		return (1);
	}
	return (0);
}


int checkRedirection(char text[]){ /*verificamos si hay simbolo de redireccion*/
	if(strchr(text, '>')!=NULL){
		return (1);
	}
	return (0);
}

void split(char text[], char *splittedText[], char DELIM[]){ /*dividimos el texto en 2: en antes de .. y en despues de...*/

	char *tokenPointer;
	int i = 0;
	tokenPointer = strtok(text, DELIM);

	while(tokenPointer != NULL){
		splittedText[i] = tokenPointer;
		tokenPointer = strtok(NULL, DELIM);
		i++;
	}
}

void finalTokensFunction(char * finalTokens[], char text[]) /*llena c/posicion del arreglo finalTokns con cada token presente en el texto*/
{
	char *tokenPointer;
	int i = 0;
	tokenPointer = strtok(text, " ");

	while(tokenPointer != NULL){
		finalTokens[i] = tokenPointer;
		tokenPointer = strtok(NULL, " ");
		i++;
	}
	finalTokens[i]=NULL;
}

void execute (char text[])
{
	int textSize = getStringLength(text);
	int checkPipes = checkPipes(text);
	int checkRedirection = checkRedirection(text);
	char copy[textSize];
	int cantTokens;

	strcpy(copyText, text);

	if(checkPipes==0 && ckeckRedirection==0)
	{
		int cantTokens = countSpaces(copyText);
		char *finalTokens[cantTokens+1];
		finalTokensFunction(finalTokens, text);
		executeCommand(finalTokens,text);
	}
	else if(checkPipes != 0 && checkRedirection == 0)
	{
		char *splittedText[2];
		split(copyText, splittedText, "|");

		char copy1[getStringLength(splittedText[0])]; /*separamos tokens del primer subarreglo*/
		strcpy(copy1, splittedText[0]);
		int SizeFirstArray = countSpaces(copy1);
		char *tokensFirstArray[sizeFirstArray+1];
		finalTokensFunction(tokensFirstArray, splittedText[0]);

		char copy2[getStringLength(splittedText[1])]; /*separamos tokens del 2do subarreglo*/
		strcpy(copy2, splittedText[1]);
		int SizeSecondArray = countSpaces(copy2); /*ls /home*/
		char *tokensSecondArray[sizeSecondArray+1];
		finalTokensFunction(tokensSecondArray, splittedText[1]);
	}
}


/**
para la variable de retorno del path, podriamos usar
int main(int argc, char *argv[], char *env[])
{

const char *ruta = NULL;
while (*env)
{
char *str = *env++;
if(str[0] == 'P' && str[1] == 'A' && str[2] == 'T' && str[3] == 'H')
{
ruta = str;
break;
}
}
printf("las rutas del path son: %s", ruta)
return (0);
}
