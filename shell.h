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
int main(int argc, char **argv, char **env);
void prompt(void);
void handle(int signals);
void _end_of_file(char *buffer);
void exit_shell(char **command);


/****************** free_memory.c **********************/

void free_command(char **command);
void exit_failure(char **command);
void msgerror(char *name, char **command);


/****************** get_token.c ***********************/

char **get_token(char *buffer, const char *s);





/***************** child_process.c ************************/

void create_child_process(char *name, char **command, char **env);
char **get_path(char **env);
void execute(char *name, char **command, char **env);

/**************** environment.c ***********************/
void print_env(char **env);


char *_strcat(char *dest, char *src);
#endif
