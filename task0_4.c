#include "shell.h"

extern char **environ;

void display_prompt()
{
	write(STDOUT_FILENO, "$ ", 2);
}

int parse_command(char *input, char **argv)
{
	int argc = 0;
	char *token = strtok(input, " \t\n");

	while(token && argc < MAX_ARGS - 1)
	{
		argv[argc] = strdup(token);
		token = strtok(NULL, "\t\n");
		argc++;
	}

	argv[argc] = NULL;
	return (argc);
}

void free_arguments(char **argv)
{
	int i;

	for (i = 0; argv[i] !=NULL; i++)
	{
		free(argv[i]);
	}
}

int execute_command(char **argv)
{
	pid_t child_pid = fork();

	if(child_pid == -1)
	{
		perror("fork");
		return (-1);
	}

	if(child_pid == 0)
	{
		execve(argv[0], argv, environ);

		char error_message[100];
		snprintf(error_message, sizeof(error_message), "Command not found: %s\n", argv[0]);
		write(STDERR_FILENO, error_message, strlen(error_message));
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
