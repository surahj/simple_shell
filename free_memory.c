#include "shell.h"

/**
 * free_command - frees all the memory allocated for command.
 * @command: The pointer to allocated memory to free.
 * Return: Nothing.
 */
void free_command(char **command)
{
	size_t i = 0;

	if (command == NULL)
		return;

	while (command[i])
	{
		free(command[i]);
		i++;
	}

	if (command[i] == NULL)
		free(command[i]);
	free(command);
}


/**
 * exit_failure - A function that frees all the memory allocated and exit.
 * @command: The pointer to allocated command memory to free.
 * Return: Nothing.
 */
void exit_failure(char **command)
{
	size_t i = 0;

	if (command == NULL)
		return;

	while (command[i])
	{
		free(command[i]);
		i++;
	}

	if (command[i] == NULL)
		free(command[i]);
	free(command);
	exit(EXIT_FAILURE);
}

/**
 * msgerror - prints message not found.
 * @name: The name of the shell.
 * @command: The pointer to tokenized command.
 * Return: Nothing.
 */
void msgerror(char *name, char **command)
{
	write(STDOUT_FILENO, name, strlen(name));
	write(STDOUT_FILENO, ": ", 3);
	write(STDOUT_FILENO, command[0], strlen(command[0]));
	write(STDOUT_FILENO, ": not found\n", 13);
}
