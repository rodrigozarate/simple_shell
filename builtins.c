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
char *builtinlist[] = {
, ., [, alias, bg, bind, break, builtin,
case, cd, command, compgen, complete, continue, declare, dirs, disown, echo, enable, eval,
exec,  exit,  export,  fc,  fg,  getopts, hash, help, history, if, jobs, kill, let, local,
logout, popd, printf, pushd, pwd, read,  readonly,  return,  set,  shift,  shopt,  source,
suspend,  test,  times,  trap,  type, typeset, ulimit, umask, unalias, unset, until, wait,
while.
}
	return (sizeof(builtin_str) / sizeof(char *));
}
