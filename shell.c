#include "shell.h"

/**
 * display_prompt - displays prompt $.
 */
void display_prompt(void)
{
	write(STDOUT_FILENO, "$ ", 2);
}

/**
 * parse_command - tokenizing.
 * @input: input string.
 * @argv: double pointer to command.
 *
 * Return: count of arguments.
 */
int parse_command(char *input, char **argv)
{
	int argc = 0;
	char *token = strtok(input, " \t\n");

	while (token && argc < MAX_ARGS - 1)
	{
		argv[argc] = _strcpy(token);
		token = strtok(NULL, "\t\n");
		argc++;
	}

	argv[argc] = NULL;
	return (argc);
}

/**
 * free_arguments - frees args.
 * @argv: double pointer to arguments.
 */
void free_arguments(char **argv)
{
	int i;

	for (i = 0; argv[i] != NULL; i++)
	{
		free(argv[i]);
	}
}

/**
 * execute_command - executes the command.
 * @argv: double pointer to args.
 *
 * Return: int status.
 */
int execute_command(char **argv)
{
	pid_t child_pid = fork();

	if (child_pid == -1)
	{
		perror("fork");
		return (-1);
	}

	if (child_pid == 0)
	{
		execve(argv[0], argv, environ);

		char err = "Command not found: ";

		write(STDERR_FILENO, err, _strlen(err));
		write(STDERR_FILENO, argv[0], _strlen(argv[0]);
		write(STDERR_FILENO, "\n", 1);
		_exit(EXIT_FAILURE);
	}

	else
	{
		int status;

		if (waitpid(child_pid, &status, 0) == -1)
		{
			perror("waitpid");
			return (-1);
		}

		return (status);
	}
}
