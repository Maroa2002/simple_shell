#include "simple_shell.h"

void showprompt(void)
{
	char *promptptr = "GHshell $ ";

	write(STDOUT_FILENO, promptptr, 10);
}

void executemd(char *input_command)
{
	pid_t ourpid;
	int status;
	char *argv[2];

	argv[0] = input_command;
	argv[1] = NULL;
	ourpid = fork();
	if (ourpid == -1)
		perror("Fork error");
	else if (ourpid == 0)
	{
		if (execve(input_command, argv, environ) == -1)
			perror("Exec error");
		
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

		if (inputptr[bytesread - 1] == '\n')
			inputptr[bytesread -1] = '\0';

		printf("%s\n", inputptr);
		/* printf("%ld\n", bytesread); */
		/* printf("%ld\n", strlen(inputptr)); */

		executemd(inputptr);
	}
	free(inputptr);

	return (0);
}

