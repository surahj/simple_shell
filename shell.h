#ifndef _SHELL_H_
#define _SHELL_H_

#include <sys/wait.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <stdio.h>
#include <fcntl.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/stat.h>


#define END_OF_FILE -2
#define EXIT -3

/* Global history counter */
int hist;

/* Global environemnt */
extern char **environ;


/* Global program name */
char *name;

/**
 * struct alias_s - A new struct defining aliases.
 * @name: The name of the alias.
 * @value: The value of the alias.
 * @next: A pointer to another struct alias_s.
 */
typedef struct alias_s
{
	char *name;
	char *value;
	struct alias_s *next;
} alias_t;

/* Global aliases linked list */
alias_t *aliases;


/**
 * struct list_s - A new struct type defining a linked list.
 * @dir: A directory path.
 * @next: A pointer to another struct list_s.
 */
typedef struct list_s
{
	char *dir;
	struct list_s *next;
} list_t;

/**
 * struct builtin_s - A new struct type defining builtin commands.
 * @name: The name of the builtin command.
 * @f: A function pointer to the builtin command's function.
 */
typedef struct builtin_s
{
	char *name;
	int (*f)(char **argv, char **front);
} builtin_t;

/********************* builtin_alias.c ********************/
int shell_lex_alias(char **args, char __attribute__((__unused__)) **front);
void set_alias(char *var_name, char *value);
void print_alias(alias_t *alias);
char **replace_aliases(char **args);


/*************************** builtin_env.c *****************************/
int shell_lex_env(char **args, char __attribute__((__unused__)) **front);
int shell_lex_setenv(char **args, char __attribute__((__unused__)) **front);
int shell_lex_unsetenv(char **args, char __attribute__((__unused__)) **front);


/***************************** builtin_help.c ************************/
void help_all(void);
void help_alias(void);
void help_cd(void);
void help_exit(void);
void help_help(void);


/****************************** buitin.c ***********************************/
int (*get_builtin(char *command))(char **args, char **front);
int shell_lex_exit(char **args, char **front);
int shell_lex_cd(char **args, char __attribute__((__unused__)) **front);
int shell_lex_help(char **args, char __attribute__((__unused__)) **front);


/*************************** create_error.c *****************************/
int num_len(int num);
char *_itoa(int num);
int create_error(char **args, int err);


/*********************** environment.c ***********************************/
char **_copyenv(void);
void free_env(void);
char **_getenv(const char *var);

/************************ error_msg_1.c ***************************************/
char *error_env(char **args);
char *error_1(char **args);
char *error_2_exit(char **args);
char *error_2_cd(char **args);
char *error_2_syntax(char **args);

/************************* error_msg_2.c *************************************/
char *error_126(char **args);
char *error_127(char **args);

/************************* getline.c **********************************/
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
void assign_lineptr(char **lineptr, size_t *n, char *buffer, size_t b);
ssize_t _getline(char **lineptr, size_t *n, FILE *stream);

/********************************* help_builtin.c ***********************************/
void help_env(void);
void help_setenv(void);
void help_unsetenv(void);

/*********************************** helper_function.c ********************************/
void free_args(char **args, char **front);
char *get_pid(void);
char *get_env_value(char *beginning, int len);
void variable_replacement(char **args, int *exe_ret);


/******************************* helper_function2.c ******************************/

void handle_line(char **line, ssize_t read);
ssize_t get_new_len(char *line);
void logical_ops(char *line, ssize_t *new_len);

/******************************** input_helper ********************************/
char *get_args(char *line, int *exe_ret);
int call_args(char **args, char **front, int *exe_ret);
int run_args(char **args, char **front, int *exe_ret);
int handle_args(int *exe_ret);
int check_args(char **args);

/********************************** link_list.c **************************************/
alias_t *add_alias_end(alias_t **head, char *name, char *value);
void free_alias_list(alias_t *head);
list_t *add_node_end(list_t **head, char *dir);
void free_list(list_t *head);

/*************************************** locate.c ********************************/
char *fill_path_dir(char *path);
list_t *get_path_dir(char *path);

char *get_location(char *command);

/******************************************* proc.c ***********************************/
int cant_open(char *file_path);
int proc_file_commands(char *file_path, int *exe_ret);


/****************************************** strtok.c ************************************/
int token_len(char *str, char *delim);
int count_tokens(char *str, char *delim);
char **_strtok(char *line, char *delim);

/****************************************** string_func.c **********************************/

int _strlen(const char *s);
char *_strcpy(char *dest, const char *src);
char *_strcat(char *dest, const char *src);
char *_strncat(char *dest, const char *src, size_t n);

/**********************string_function.c **********************************************************/
char *_strchr(char *s, char c);
int _strspn(char *s, char *accept);
int _strcmp(char *s1, char *s2);
int _strncmp(const char *s1, const char *s2, size_t n);

/********************************** shell_lex_init.c *************************************/
int main(int argc, char *argv[]);
void sig_handler(int sig);
int execute(char **args, char **front);



#endif /* _SHELL_H_ */
