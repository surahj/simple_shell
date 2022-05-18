#include "shell.h"

/**
 * create_child_process - A function that creates a child process.
 * @name: The pointer to the name of shell.
 * @command: The pointer to tokenized command
 * @env: The pointer to the enviromental variables.
 * Return: Nothing.
 */
void create_child_process(char *name, char **command, char **env)
{
	pid_t pid = 0;
	int status = 0;
	int waitpid_error = 0;

	if (!(_strcmp(command[0], "env")))
		print_env(env);

	pid = fork();
	if (pid < 0)
	{
		perror(name);
		exit_failure(command);
	}
	else if (pid == 0)
	{
		execute(name, command, env);
	}
	else
	{
		waitpid_error = waitpid(pid, &status, 0);
		if (waitpid_error < 0)
		{
			exit_failure(command);
		}
		free_command(command);
	}
}


/**
 * execute - A function that executes a command.
 * @command: The pointer to tokienized command
 * @name: The name of the shell.
 * @env: The pointer to the enviromental variables.
 * Return: Nothing.
 */
void execute(char *name, char **command, char **env)
{
	char **all_path = NULL, *command_path = NULL;
	struct stat st;
	unsigned int i = 0;

	if (stat(command[0], &st) == 0)
	{
		if (execve(command[0], command, env) < 0)
		{
			perror(name);
			exit_failure(command);
		}
	}
	else
	{
		all_path = get_path(env);


		while (all_path[i])
		{
			command_path = _strcat(all_path[i], command[0]);
			i++;
			if (stat(command_path, &st) == 0)
			{
				if (execve(command_path, command, env) < 0)
				{
					perror(name);
					free_command(all_path);
					exit_failure(command);
				}
				return;
			}
		}
		msgerror(name, command);
		free_command(all_path);
	}
}

/**
 * get_path - gets the full path value from
 * enviromental variable PATH.
 * @env: The pointer to enviromental variables.
 * Return: All tokenized path for commands.
 */
char **get_path(char **env)
{
	char *pathvalue = NULL, **all_path = NULL;
	unsigned int i = 0;

	pathvalue = strtok(env[i], "=");
	while (env[i])
	{
		if (!(_strcmp(pathvalue, "PATH")))
		{
			pathvalue = strtok(NULL, "\n");
			all_path = get_token(pathvalue, ":");
			return (all_path);
		}
		i++;
		pathvalue = strtok(env[i], "=");
	}
	return (NULL);
}
