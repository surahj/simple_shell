# shell_lex - simple_shell
A simple UNIX command interpreter written as part of the low-level programming and algorithm track at ALX

# Description
Shell_lex is a simple UNIX command language interpreter that reads commands from either a file or standard input and executes them.

# Basic Start
To run this shell with its respective commands its necessary to clone this reposotory in your terminal. Do it like this:

- HTTPS
git clone https://github.com/surahj/simple_shell.git

- SSH:

git@github.com:surahj/simple_shell.git

# Compiling, Debugging and Runing

- To compile your functions use:
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o shell_lex

- for debugging the shell, use valgrind:
```valgrind --leak-check=full ./shell_lex```

