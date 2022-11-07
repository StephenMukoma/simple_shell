# 0x16. C - Simple Shell

## Learning Objectives

## General

- Who designed and implemented the original Unix operating system 
- Who wrote the first version of the UNIX shell 
- Who invented the B programming language (the direct predecessor to the C programming language) 
- Who is Ken Thompson 
- How does a shell work 
- What is a pid and a ppid 
- How to manipulate the environment of the current process 
- What is the difference between a function and a system call 
- How to create processes 
- What are the three prototypes of main 
- How does the shell use the PATH to find the programs 
- How to execute another program with the execve system call 
- How to suspend the execution of a process until one of its children terminates 
- What is EOF / “end-of-file”? 

## Requirements

- Allowed editors: vi, vim, emacs 
- All your files will be compiled on Ubuntu 20.04 LTS using gcc, using the options -Wall -Werror -Wextra -pedantic -std=gnu89 
- All your files should end with a new line 
- A README.md file, at the root of the folder of the project is mandatory 
- Your code should use the Betty style. It will be checked using betty-style.pl and betty-doc.pl 
- Your shell should not have any memory leaks 
- No more than 5 functions per file 
- All your header files should be include guarded 
- Use system calls only when you need to (why?) 
- Write a README with the description of your project 
- You should have an AUTHORS file at the root of your repository, listing all individuals having contributed content to the repository. Format, see Docker 

## Output

- Unless specified otherwise, your program must have the exact same output as sh (/bin/sh) as well as the exact same error output. 
- The only difference is when you print an error, the name of the program must be equivalent to your argv[0] 

## List of allowed functions and system calls

- access, chdir, close, closedir, execve, exit, \_exit, fflush, fork, free, getcwd, getline, getpid, isatty, kill 
- malloc, open, opendir, perror, read, readdir, signal, stat, lstat, fstat, strtok, wait, waitpid, wait3, wait4, write 

## Compilation

Your shell will be compiled this way:

- gcc -Wall -Werror -Wextra -pedantic -std=gnu89 \*.c -o hsh

## Testing

- Shell should work in interactive mode and in non-interactive mode.

## Tasks

### Task 0

Write a beautiful code that passes the Betty checks 

### Task 1

Write a UNIX command line interpreter. 

- Usage: simple\_shell 

Your Shell should: 

- Display a prompt and wait for the user to type a command. A command line always ends with a new line. 
- The prompt is displayed again each time a command has been executed. 
- The command lines are simple, no semicolons, no pipes, no redirections or any other advanced features. 
- The command lines are made only of one word. No arguments will be passed to programs. 
- If an executable cannot be found, print an error message and display the prompt again. 
- Handle errors. 
- You have to handle the “end of file” condition (Ctrl+D) 

You don’t have to: 

- use the PATH 
- implement built-ins 
- handle special characters : ", ', `, \, *, &, # 
- be able to move the cursor 
- handle commands with arguments 

### Task 2

Simple shell 0.1 + 

- Handle command lines with arguments 

### Task 3 

Simple shell 0.2 + 

- Handle the PATH 
- fork must not be called if the command doesn’t exist 

### Task 4

Simple shell 0.3 + 

- Implement the exit built-in, that exits the shell 
- Usage: exit 
- You don’t have to handle any argument to the built-in exit 

### Task 5 

Simple shell 0.4 + 

- Implement the env built-in, that prints the current environment 

### Task 6

Simple shell 0.1 +

- Write your own getline function 
- Use a buffer to read many chars at once and call the least possible the read system call 
- You will need to use static variables 
- You are not allowed to use getline
 
You don’t have to: 

- be able to move the cursor 

### Task 7

Simple shell 0.2 +

- You are not allowed to use strtok 

### Task 8

Simple shell 0.4 + 

- handle arguments for the built-in exit 
- Usage: exit status, where status is an integer used to exit the shell 

### Task 9

Simple shell 1.0 + 

Implement the setenv and unsetenv builtin commands 

- setenv 
 - Initialize a new environment variable, or modify an existing one 
 - Command syntax: setenv VARIABLE VALUE 
 - Should print something on stderr on failure 

- unsetenv 
 - Remove an environment variable 
 - Command syntax: unsetenv VARIABLE 
 - Should print something on stderr on failure 

### Task 10

Simple shell 1.0 + 

- Implement the builtin command cd: 

- Changes the current directory of the process. 
- Command syntax: cd [DIRECTORY] 
- If no argument is given to cd the command must be interpreted like cd $HOME 
- You have to handle the command cd - 
- You have to update the environment variable PWD when you change directory 
- man chdir, man getcwd 

### Task 11

Simple shell 1.0 +

- Handle the commands separator ; 

### Task 12

Simple shell 1.0 + 

- Handle the && and || shell logical operators 

### Task 13

Simple shell 1.0 + 

- Implement the alias builtin command 
- Usage: alias [name[='value'] ...] 
- alias: Prints a list of all aliases, one per line, in the form name='value' 
- alias name [name2 ...]: Prints the aliases name, name2, etc 1 per line, in the form name='value' 
- alias name='value' [...]: Defines an alias for each name whose value is given. If name is already an alias, replaces its value with value 

### Task 14

Simple shell 1.0 + 

- Handle variables replacement 
- Handle the $? variable 
- Handle the $$ variable 

### Task 15

Simple shell 1.0 + 

- Handle comments (\#) 

### Task 16 

Simple shell 1.0 + 

- Usage: simple_shell [filename] 
- Your shell can take a file as a command line argument 
- The file contains all the commands that your shell should run before exiting 
- The file should contain one command per line 
- In this mode, the shell should not print a prompt and should not read from stdin 























