#include "shell.h"

int main()
{
	char input[MAX_COMMAND_LEN];

	while(1)
	{
		display_prompt();
		ssize_t read_size = read(STDIN_FILENO, input, sizeof(input));

		if(read_size == 0)
		{
			printf("\n");
			break;
		}

		if(input[read_size -1] == '\n')
		{
			input[read_size -1] = '\0';
		}

		char *argv[MAX_ARGS];
		int argc = parse_command(input, argv);

		if(argc == 0)
		{
			continue;
		}

		if(execute_command(argv) == -1)
		{
			return (EXIT_FAILURE);
		}

		free_arguments(argv);
	}

	return (0);

}
