#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <wait.h>
#include <sys/types.h>
#include "shell.h"

int main(){

	char text[100];
	pid_t pid; /*identificador de proceso*/

	while (1) /*mientras sea interactivo*/
	{
		printf("$ ");
		scanf(" %99[^\n]", text); /*%99[^\n] leer linea completa*/
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
