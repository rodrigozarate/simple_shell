#ifndef SIMPLE_SHELL_H
#define SIMPLE_SHELL_H

#define JR_PROMPT "$ "

#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <errno.h>
#include <sys/stat.h>
#include <fcntl.h>

extern char **environ;

/* char *read_input(void); */
char *read_input(char **input, size_t *bufferinput);
char **break_input(char *input);
int rocket(char **args);
int run_command(char **args, char **builtinlist);
int bi_env(void);
int bi_exit(void);
int builtins(char **builtinlist);
/* util */
int _strlen(char *string);
int str_comp(char *str_a, char *str_b);
/* to do PATH */
char *getVariableFromEnviron(char *variableName);
char *str_concat(char *s1, char *s2);
char **tokenize(char *string);
#endif /* SIMPLE_SHELL_H */
