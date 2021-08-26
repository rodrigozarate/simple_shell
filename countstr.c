/*
 * countstr.c - count chars of strings
 * Author: Joana Casallas and Rodrigo Zárate Algecira
 * Date: August 24, 2021
 */

#include "simple_shell.h"

/**
 * countstr - count chars of string
 * @string: char pointer
 * Return: int
 */

int countstr(char *string)
{
	int cs;

	for (cs = 0; string[cs] != '\0'; cs++)
		;
	return (cs);
}
