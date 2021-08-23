#ifndef SIMPLE_SHELL_H
#define SIMPLE_SHELL_H

#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

extern char **environ;
extern int errno;

char *read_input(void);
char **break_input(char *input);
int rocket(char **args);
int run_command(char **args);
int builtins(void);

#endif /* SIMPLE_SHELL_H */
