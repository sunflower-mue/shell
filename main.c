#include "shell.h"

/**
 * main - Entry Point to shell.
 *
 * Return: Success(0).
 */

int main(void)
{
	char input[MAX_COMMAND_LEN];
	ssize_t r;
	char newline;
	char *argv[MAX_ARGS];
	int argc, status;

	while (1)
	{
		display_prompt();
		r = read(0, input, MAX_COMMAND_LEN);
		
		if (r < 0)
		{
			perror("Read error");
			exit(1);
		}

		if (!r)
		{
			newline = '\n';
			write(1, &newline, 1);
			break;
		}

		if (input[r - 1] == '\n')
		{
			input[r - 1] = '\0';
		}

		if (_strcmp(input, "exit"))
		{
			exit(0);
		}
		argc = parse_command(input, argv);

		if (argc > 0)
		{
			if (access(argv[0], X_OK) == 0)
			{
				status = execute_command(argv);
				if (status == -1)
				{
					perror("Execution error");
				}
			}
			else
			{
				printf("Command not found: %s\n", argv[0]);
			}

			free_arguments(argv);
		}
		
	}
		return (0);
}
