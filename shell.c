#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <wait.h>
#include <sys/types.h>
#include "shell.h"

int main(){

	char *prompt = "$:";
	char *text;
	size_t textSize = 0;
	int charactersRead = 0;
	pid_t pid; /*identificador de proceso*/

	while (1) /*mientras sea interactivo*/
	{
		if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, prompt, getStringLength(prompt)); /*imprime signo del promp y lo muestra por pantalla*/
		charactersRead = getline(&text, &textSize, stdin); /*guardamos la linea de texto en la variable text..  */
		if (text != NULL)
		{
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

		pid_t pid = fork();/*creamos un proceso hijo, c/proceso tendra una salida distinta*/
		if(pid == -1)
		{
			exit (-1);
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
