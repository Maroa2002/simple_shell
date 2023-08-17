#include "simple_shell.h"

/**
  *_strcmp - function to compare
  *@s1: function to be compared
  *@s2: function to be compared to
  *Return: 0
  */

int _strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	for (; s1[i] != '\0' && s2[i] != '\0';)
	{
		if (s1[i] != s2[i])
		{
			return (s1[i] - s2[i]);
		}
		i++;
	}
	return (0);
}

char *path_finder(void)
{
	char **ev = environ;

	while (*ev)
	{
		if (_strcmp(*ev, "PATH=") == 0)
			return (*ev + 5);
		ev++;
	}

	return (NULL);
}

char *find_executable(char *cmd)
{
	char *path = path_finder, *tk, filepth;
	int cmd_len = str_len(cmd), path_len;

	if (path = NULL)
	{
		perror("No match");
		exit(EXIT_FAILURE);
	}
	
	tk = strtok(path, ":");
	while (tk)
	{
		path_len = str_len(tk);
		filepth = malloc(cmd_len + path_len + 2);
		if (filepth == NULL)
		{
			perror("Malloc error");
			exit(EXIT_FAILURE);
		}
		str_dup(filepth, tk);
		str_cat(filepth, "/");
		str_cat(filepth, cmd);
		if (access(filepth, X_OK) == 0)
			return (filepth);
		else
		{
			perror("Executable not found");
			free(filepth);
			exit(EXIT_FAILURE);
		}	
		tk = strtok(NULL, ":");
	}
	return (NULL);
}
