#ifndef SIMPLE_SHELL_H
#define SIMPLE_SHELL_H

#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <stdio.h>
#include <sys/types.h>

char *read_input(void);
char **break_input(char *input);
int rocket(char **args);

#endif /* SIMPLE_SHELL_H */
