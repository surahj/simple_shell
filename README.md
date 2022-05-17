# shell_lex - simple_shell
A simple UNIX command interpreter written as part of the low-level programming and algorithm track at ALX

# Description
Shell_lex is a simple UNIX command language interpreter that reads commands from either a file or standard input and executes them.

# Basic Start
To run this shell with its respective commands its necessary to clone this reposotory in your terminal. Follow this steps:

- HTTPS
```
git clone https://github.com/surahj/simple_shell.git
```

- SSH:
```
git@github.com:surahj/simple_shell.git
```

# Compiling, Debugging and Invoking

- To compile your functions use:
```
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o shell_lex
```

- for debugging the shell, use valgrind:
```
valgrind --leak-check=full ./shell_lex
```
# Invoking:
Shell_lex can be invoked both interactively and non-interactively. If shell_lex is invoked with standard input not connected to a terminal, it reads and executes received commands in order.
-Example:
```
$ echo "echo 'hello'" | ./shell_lex
'hello'
$
```
If shell_lex is invoked with standard input connected to a terminal (determined by isatty(3)), an interactive shell is opened. When executing interactively, shell_lex displays the prompt $ when it is ready to read a command.
-Example:
```
$./shell_lex
$
```
# Command Execution
When the user types a command, getline() function reads an entire line from the stream and strtok() function breaks the inputted command into a sequence of non-empty tokens.
Next, it creates a separate child process suing fork() that performs the inputted command. Unless otherwise is specified, the parent process waits for the child to exit before continuing.
After tokening the command, execve() function brings and executes it, the it frees all allocated memory with free().
Finally, the program returns to main process: prints the prompt, and waits for another user input.

# Environment
Upon invocation, shell_lex receives and copies the environment of the parent process in which it was executed. This environment is an array of name-value strings describing variables in the format NAME=VALUE. A few key environmental variables are:

# Home
The home directory of the current user and the default directory argument for the cd builtin command.



