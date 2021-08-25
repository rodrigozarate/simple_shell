#include "simple_shell.h"

/**
 * exec - Create a new child process and executes a command
 * @arguments: Array of commands
 * Return: 0
 */


int exec(char **arguments)
{
	pid_t pid = 0; /**Child process id*/
	int stat = 0;
	int exe_stat = 0; /**status del child process*/

	pid = fork(); /**create process shild*/
	if (pid == -1) /**Failed*/
		perror("failed function\n");
	else if (pid == 0) /**this is the child process */
	{
		exe_stat = execve(arguments[0], arguments, environ); /**execute*/
		if (exe_stat == -1)
		{
			perror("failed function\n");
			exit(exe_stat);
		} /**Child process ends fine*/
		exit(0);
	}
	else /**Parent proces*/
		wait(&stat);/**sleep*/
	exe_stat = WEXITSTATUS(stat); /**WEXITSTATUS = exit status del proceso hijo*/
	return (exe_stat);
}
