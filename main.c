#include "shell.h"

/**
 * main - Entry Point to shell.
 *
 * Return: Success(0).
 */

int main(void)
{
	char input[MAX_COMMAND_LEN];
	ssize_t r = read(0, input, MAX_COMMAND_LEN);
	char newline = '\n';
	char *argv[MAX_ARGS];
	int argc = parse_command(input, argv);

	while (1)
	{
		display_prompt();
		if (r == 0)
		{
			write(1, &newline, 1);
			break;
		}
		if (input[r - 1] == '\n')
		{
			input[r - 1] = '\0';
		}

		if (argc == 0)
		{
			continue;
		}

		if (write(1, "exit", 4) != -1 && _strcmp(argv[0], "exit"))
		{
			break;
		}
		if (execute_command(argv) == -1)
		{
			return (EXIT_FAILURE);
		}
	}
	return (0);
}
