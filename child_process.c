#include "shell.h"

/**
 * create_child - A function that creates a child process.
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

	pid = fork();
	if (pid < 0)
	{
		perror(name);
		exit_failure(command);
	}
	else if (pid == 0)
	{
		if (execve(command[0], command, env) < 0)
		{
			perror(name);
			exit_failure(command);
		}
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
