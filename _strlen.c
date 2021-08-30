/*
 * _strlen.c - count chars of strings
 * Author: Joana Casallas and Rodrigo Zárate Algecira
 * Date: August 24, 2021
 */

#include "simple_shell.h"

/**
 * _strlen - count chars of string
 * @string: char pointer
 * Return: int
 */

int _strlen(char *string)
{
	int i;

	for (i = 0; string[i] != '\0'; i++)
		;
	return (i);
}
