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
Invoking:
Shellby can be invoked both interactively and non-interactively. If shellby is invoked with standard input not connected to a terminal, it reads and executes received commands in order.
Example:
```
$ echo "echo 'hello'" | ./shell_lex
'hello'
$
```
If shellby is invoked with standard input connected to a terminal (determined by isatty(3)), an interactive shell is opened. When executing interactively, shellby displays the prompt $ when it is ready to read a command.
Example:
```
$./shell_lex
$
```


