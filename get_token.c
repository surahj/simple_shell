#include "shell.h"

/**
 * tokening - A function that split and create a full string command.
 * @s: The delimiter for strtok.
 * @buffer: The pointer to input string.
 * Return: A string with full command.
 */
char **get_token(char *buffer, const char *s)
{
	char *token = NULL, **commands = NULL;
	size_t bufsize = 0;
	int i = 0;

	if (buffer == NULL)
		return (NULL);

	bufsize = strlen(buffer);
	commands = malloc((bufsize + 1) * sizeof(char *));
	if (commands == NULL)
	{
		perror("Unable to allocate buffer");
		free(buffer);
		free_command(commands);
		exit(EXIT_FAILURE);
	}

	token = strtok(buffer, s);
	while (token != NULL)
	{
		commands[i] = malloc(strlen(token) + 1);
		if (commands[i] == NULL)
		{
			perror("Unable to allocate buffer");
			free_command(commands);
			return (NULL);
		}
		strcpy(commands[i], token);
		token = strtok(NULL, s);
		i++;
	}
	commands[i] = NULL;
	return (commands);
}
