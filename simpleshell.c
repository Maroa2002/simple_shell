#include "simple_shell.h"
/**
  *showprompt - function to displat prompt on terminal
  *
  */
void showprompt(void)
{
	if (isatty(STDIN_FILENO))
	{
	char *promptptr = "$ ";

	write(STDOUT_FILENO, promptptr, 2);
	}
}
/**
  *executemd - function to execute external command using execve
  *@input_command: command to be executed
  */
void executemd(char **input_command)
{
	pid_t ourpid;
	int status;
	char *filecmd;

	ourpid = fork();
	if (ourpid == -1)
	{
		perror("Fork error");
		return;
	}
	else if (ourpid == 0)
	{
		if (access(input_command[0], X_OK) == 0)
		{
			if (execve(input_command[0], input_command, environ) == -1)
			{
				perror("Error");
				exit(EXIT_FAILURE);
			}
		}
		else
		{
			filecmd = find_executable(input_command[0]);
			if (filecmd == NULL)
			{
				perror("Error");
				exit(EXIT_FAILURE);
			}
			if (execve(filecmd, input_command, environ) == -1)
			{
				perror("Exec error");
				exit(EXIT_FAILURE);
			}
			free(filecmd);
		}
	}
	else
		wait(&status);
}
/**
 * EOF_handler - handles EOF
 * @inputptr: command read
 **/
void EOF_handler(char *inputptr)
{
	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "\n", 1);
	free(inputptr);
	exit(0);
}
/**
 * printenv - prints env
 ***/
void printenv(void)
{
	int i = 0, env_len = 0;

	while (environ[i])
	{
		env_len = str_len(environ[i]);
		write(STDOUT_FILENO, environ[i], env_len);
		write(STDOUT_FILENO, "\n", 1);
		i++;
	}
}
/**
  *main - accepts command line arguments
  *@argc: number of command line arguments
  *@argv: array of arguments
  *Return: 0
  */
int main(int argc, char *argv[])
{
	char *inputptr = NULL, **tkn_command = NULL;
	size_t s = 0;
	ssize_t bytesread;
	int i;

	(void)argc;
	(void)argv;
	while (1)
	{
		showprompt();
		bytesread = getline(&inputptr, &s, stdin);

		if (bytesread == EOF)
			EOF_handler(inputptr);
		else if (bytesread == -1)
		{
			perror("Error reading input");
			free(inputptr);
			exit(EXIT_FAILURE);
		}
		inputptr[bytesread - 1] = '\0';
		tkn_command = get_token(inputptr, bytesread);
		if (tkn_command != NULL && tkn_command[0] != NULL)
		{
			if (_strcmp(tkn_command[0], "exit") == 0)
				exit(EXIT_SUCCESS);
			else if (_strcmp(tkn_command[0], "cd") != 0)
				_cd(tkn_command[1]);
			else
				executemd(tkn_command);
			for (i = 0; tkn_command[i] != NULL; i++)
				free(tkn_command[i]);
			free(tkn_command);
		}
	}
	free(inputptr);
	return (0);
}
