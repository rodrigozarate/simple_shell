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
  lsh_loop();

  /* cleanup, free memory, etc */

  return EXIT_SUCCESS;
}
