#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <wait.h>
#include <sys/types.h>
#include "shell.h"

int gestStringLength(char *string);

int main(){

	char *prompt = "$:";
	char *text;
	size_t textSize = 0;
	int charactersRead = 0;
	pid_t pid; /*identificador de proceso*/

	while (1) /*mientras sea interactivo*/
	{
		write(STDOUT_FILENO, prompt, getStringLength(prompt)); /*escribimos la linea de texto y la mostramos en el prompt*/
		charactersRead = getline(&text, &textSize, stdin); /*guardamos la linea en la variable text*/
		pid_t pid = fork();/*creamos un proceso hijo, c/proceso tendra una salida distinta*/
		if(pid == -1)
		{
			exit (-1)
				}
		if (pid == 0) /*comprobamos que se ha creado el proceso hijo*/
		{
			execute(text);
		}
		if (pid == 1) /*nos encontramos en el proceso padre*/
		{
			wait(); /*esperamos a que proceso hijo ejecute y muera*/
		}
		return (0);
	}
}

int getStringLength(char *string)
{
	int i = 0;
	while (string[i])
	{
		i++;
	}
}
