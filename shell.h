#ifndef SHELL_H
#define SHELL_H

#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

/********************main.c*****************************/
int main(int arg, char **argv, char **env);
void prompt(void);
void handle(int signals);
void _end_of_file(char *buffer);
void exit_shell(char **command);











#endif
