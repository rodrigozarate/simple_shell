/*
* builtins.c - List of buitins and functions
* Author: Rodrigo Zárate Algecira and Joana Casallas
* Date: August 22, 2021
*/

#include "simple_shell.h"

/**
* builtins - List of builtins
* Return: int
*/

int builtins()
{
	return (sizeof(builtinlist) / sizeof(char *));
}