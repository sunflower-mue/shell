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
	int argc;

	while (1)
	{
		display_prompt();
		r = read(0, input, MAX_COMMAND_LEN);

		if (r < 0)
		{
			perror("Read error");
			exit(1);
		}

		if (r == 0)
		{
			newline = '\n';
			write(1, &newline, 1);
			break;
		}

		if (input[r - 1] == '\n')
		{
			input[r - 1] = '\0';
		}
		argc = parse_command(input, argv);

		if (argc == 0)
			continue;
		if (_strcmp(input, "exit\n") == 0)
		{
			exit(0);

		}
		
		if (execute_command(argv) == -1)
		{
			return (EXIT_FAILURE);
		}
	}
		return (0);
}
