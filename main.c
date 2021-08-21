/*
* main.c - Entry point for Simpe shell project
* Author: Joana Casallas and Rodrigo Zárate A
* Date: August 21, 2021
*/

/**
* main - Entry point
* @argc: int
* @argv: char double pointer
* Return: EXIT_SUCCESS
*/


int main(int argc, char **argv)
{
/* config */
/* loop for commands */

	int state
	char *input
	char **args

	do
	{
	/* define prompt */
	input = read_input();
	args = break_input(input);
	state = run_command(args);

	/* cleanup, free memory, etc */
	free(input);
	free(args);
	}
	while (state);

return EXIT_SUCCESS;
}
