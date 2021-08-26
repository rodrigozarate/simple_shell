# simple_shell
## Colaborative project
	Johana Casallas
	Rodrigo Zárate A.
## 0x16. C - Simple Shell
### Write a simple UNIX command interpreter.
## Learning Objectives

    How does a shell work
    What is a pid and a ppid
    How to manipulate the environment of the current process
    What is the difference between a function and a system call
    How to create processes
    What are the three prototypes of main
    How does the shell use the PATH to find the programs
    How to execute another program with the execve system call
    How to suspend the execution of a process until one of its children terminates
    What is EOF / “end-of-file”?

### List of allowed functions and system calls
    access (man 2 access)
    chdir (man 2 chdir)
    close (man 2 close)
    closedir (man 3 closedir)
    execve (man 2 execve)
    exit (man 3 exit)
    _exit (man 2 _exit)
    fflush (man 3 fflush)
    fork (man 2 fork)
    free (man 3 free)
    getcwd (man 3 getcwd)
    getline (man 3 getline)
    getpid (man 2 getpid)
    isatty (man 3 isatty)
    kill (man 2 kill)
    malloc (man 3 malloc)
    open (man 2 open)
    opendir (man 3 opendir)
    perror (man 3 perror)
    read (man 2 read)
    readdir (man 3 readdir)
    signal (man 2 signal)
    stat (__xstat) (man 2 stat)
    lstat (__lxstat) (man 2 lstat)
    fstat (__fxstat) (man 2 fstat)
    strtok (man 3 strtok)
    wait (man 2 wait)
    waitpid (man 2 waitpid)
    wait3 (man 2 wait3)
    wait4 (man 2 wait4)
    write (man 2 write)

## Compilation

The program must be compiled this way:

`gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh`

## How to use

Download or fork the repo, unzip and compile as ilustrated before.
Type `./hsh` after compilation ends.

### Simple command
At the prompt type usual commands like *ls* giving its full path **/bin/ls** in my case

`$ /bin/ls`

That will list the files and directories in the current working directory
if you dont give the PATH an error message will indicate Command not found
For future develop we will create a function that looks for the command in the PATH so you'll be able to use these comands just by typing the command itself.

	break_input.c 		main.c 			simple_shell.h
	builtins.c 		man_1_simple_shell 	str_comp.c'

### Simple command with argument
At the prompt type usual commands like ls giving its full path /bin/ls in my case and use the arguments -l in this case.

`$ /bin/ls`

That will list the files and directories in the current working directory in the LONG format meaning that it will show permissions and owner.
if you dont give the PATH an error message will indicate Command not found.

	-rw-r--r--  1 user  staff   1107 Aug 24 02:21 break_input.c
	-rw-r--r--  1 user  staff    323 Aug 24 02:18 builtins.c
	-rw-r--r--  1 user  staff   1345 Aug 24 02:37 main.c
	-rwxr--r--  1 user  staff    782 Aug 19 23:35 man_1_simple_shell
	-rw-r--r--  1 user  staff    580 Aug 24 02:15 simple_shell.h
	-rw-r--r--  1 user  staff    566 Aug 24 02:12 str_comp.c

### Non interactive mode
At the TERMINAL prompt outside the hsh program type: `echo "/bin/ls" | ./hsh`

That will send the instructions via pipe to ./hsh as arguments

The result should be the same as typing /bin/ls directly in the ./hsh program

### Non interactive mode with arguments
At the TERMINAL prompt outside the hsh program type: `echo "/bin/ls -l" | ./hsh`

That will send the instructions via pipe to ./hsh as arguments

The result should be the same as typing /bin/ls -l directly in the ./hsh program

### Built ins
Two builtins were implemented `env` and `exit`
### env
Display the vars in environ one by line.
Type **env** at the prompt of ./hsh program
You should see something like that in your screen

	TERM_PROGRAM=Apple_Terminal
	SHELL=/bin/bash
	TERM=xterm-256color
	TMPDIR=/var/folders/x3/99rxpk913hs7crrhgqyrc4gw0000gn/T/
	TERM_PROGRAM_VERSION=433
	OLDPWD=/Users/user
	TERM_SESSION_ID=40476BB1-FE99-4432-8EEF-5B7E19E0099A
	USER=user
	SSH_AUTH_SOCK=/private/tmp/com.apple.launchd.UHyOZuZfWC/Listeners
	PATH=/usr/local/bin:/usr/bin:/bin:/usr/sbin:/sbin:/usr/local/share/dotnet:~/.dotnet/tools:/Library/Frameworks/Mono.framework/Versions/Current/Commands
	PWD=/Users/user/simple_shell
	XPC_FLAGS=0x0
	XPC_SERVICE_NAME=0
	SHLVL=1
	HOME=/Users/user
	LOGNAME=user
	LC_CTYPE=UTF-8
	_=./hsh

### exit
End the execution of ./hsh program
Type **exit** at the prompt of ./hsh program
The prompt get back to the TERMINAL

#### Special Thanks to

	https://github.com/JuanDAC
	https://github.com/juanescorreap
	https://github.com/Cr1st14n0l101
	https://github.com/anversa-pro

for all the help

## Made the Holberton way, always give first.


