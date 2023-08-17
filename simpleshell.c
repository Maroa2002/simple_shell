#include "simple_shell.h"

void showprompt(void)
{
	char *promptptr = "GHshell $ ";

	write(STDOUT_FILENO, promptptr, 10);
}

void executemd(char **input_command)
{
	pid_t ourpid;
	int status;
	char *filecmd = find_executable(input_command[0]);

	ourpid = fork();
	if (ourpid == -1)
		perror("Fork error");
	else if (ourpid == 0)
	{
		if (execve(filecmd, input_command, environ) == -1)
		{
			perror("Exec error");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		wait(&status);
	}
}

int main(int argc, char *argv[])
{
	char *inputptr;
	size_t s = 0;
	ssize_t bytesread;
	char **tkn_command;

	(void)argc; (void)argv;

	while (1)
	{
		showprompt();
		bytesread = getline(&inputptr, &s, stdin);

		if (bytesread == EOF)
		{
			write(STDOUT_FILENO, "\n", 1);
			exit(0);
		}
		else if (bytesread == -1)
		{
			perror("Error");
			exit(EXIT_FAILURE);
		}

		inputptr[bytesread -1] = '\0';
		tkn_command = get_token(inputptr, bytesread);
		executemd(tkn_command);
	}

	free(inputptr);

	return (0);
}
