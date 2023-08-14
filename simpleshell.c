#include "simple_shell.h"

void showprompt(void)
{
	char *promptptr = "GHshell $ ";

	write(STDOUT_FILENO, promptptr, 10);
}

int main(int argc, char *argv[])
{
	char *inputptr;
	size_t s = 0;
	ssize_t bytesread;

	(void)argc;

	while (1)
	{
		showprompt();
		bytesread = getline(&inputptr, &s, stdin);

		if (bytesread == EOF)
		{
			write(STDOUT_FILENO, "\n", 1);
			exit(0);
		}
		printf("%ld\n", bytesread);
		printf("%ld\n", strlen(inputptr));

		executemd(argv);

	}
	return (0);
}

void executemd(char *argv[])
{
	pid_t ourpid;
	int status;
	char *path = NULL;

	ourpid = fork();
	if (ourpid == -1)
		perror("Fork error");
	else if (ourpid == 0)
	{
		path = argv[0];
		if (execve(path, argv, NULL) == -1)
			perror("Exec error");
	}
	else
	{
		wait(&status);
	}
}
