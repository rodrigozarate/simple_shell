/*
* str_comp.c - Compare strings
* Author: Rodrigo Zárate A. and Joana Casallas
* Date: August 24, 2021
*/

#include "simple_shell.h"

/**
* str_comp - Compare strings
* @str_a: char pointer
* @str_b: char pointer
* Return: int
*/

int str_comp(char *str_a, char *str_b)
{
	while ((*str_a != '\0' && *str_b != '\0') && *str_a == *str_b)
	{
	/* next position */
		str_a++;
		str_b++;
	}
	if (*str_a == *str_b)
	{
		/* reach end at equal position */
		/* match */
		return (0);
	}
	else
	{
		/* return difference */
		/* not zero */
		return (*str_a - *str_b);
	}
}
