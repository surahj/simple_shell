#include "shell.h"

/**
 * main - it initialize our shell
 * @argc: The number of imputted argument
 * @argv: pointer to array of inputted argument
 * @env: pointer to enviromnet variables
 * Return: Always 0.
 */

int main(int argc, char **argv, char **env)
{
	char *buffer = NULL, **command = NULL;
	size_t buf_size = 0;
	ssize_t chars_readed = 0;
	(void)argc;
	signal(SIGINT, handle);

	while (1)
	{
		prompt();
		chars_readed = getline(&buffer, &buf_size, stdin);

		if (*buffer == '\n')
			free(buffer);

		else if (chars_readed == -1)
			_end_of_file(buffer);

		else
		{
			buffer[strlen(buffer) - 1] = '\0';
			command = get_token(buffer, " \0");

			if (!(strcmp(command[0], "exit")))
				exit_shell(command);
			else
				create_child_process(argv[0], command, env);
		}
		fflush(stdin);
		buffer = NULL;
	}
	if (chars_readed == -1)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

/**
 * exit_shell - exit a shell
 * @command: pointer to exit command
 * Return: nothing
 */

void exit_shell(char **command)
{
	int code = 0;

	if (command[1] == NULL)
	{
		free_command(command);
		exit(EXIT_SUCCESS);
	}

	code = atoi(command[1]);
	free_command(command);
	exit(code);
}

/**
 * prompt - A function that prints the prompt
 * Return: Nothing.
 */

void prompt(void)
{
	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "$ ", 3);
}

/**
 * _end_of_file - checcks if buffer is EOF
 * @buffer: buffer to check
 * Return: nothing
 */

void _end_of_file(char *buffer)
{
	if (buffer)
	{
		free(buffer);
		buffer = NULL;
	}

	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "\n", 2);

	free(buffer);
	exit(EXIT_SUCCESS);
}

/**
 * handle - handle Ctr + C signal.
 * @signals: The signal to handle.
 * Return: Nothing.
 */
void handle(int signals)
{
	(void)signals;
	write(STDOUT_FILENO, "\n$ ", 4);
}
