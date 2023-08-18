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
/**
  *str_dup - function to return pointer to new memory
  *@str: string to copy
  *Return: NULL, pointer to memory
  */
char *str_dup(char *str)
{
	char *dup;
	int i, j;

	if (str == NULL)
		return (NULL);

	i = 0;
	while (str[i])
		i++;

	dup = malloc(sizeof(char) * (i + 1));

	if (dup == NULL)
	return (NULL);

	for (j = 0; str[j]; j++)
	{
		dup[j] = str[j];
	}
	dup[j] = '\0';
	return (dup);
}
/**
  **str_cat - function that concantenates
  *@dest: parameter to be appended
  *@src: parameter to be concantenated
  *Return: dest
  */
char *str_cat(char *dest, char *src)
{
	int i, j;

	for (i = 0; dest[i] != '\0';)
	{
		i++;
	}
	for (j = 0; src[j] != '\0';)
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest);
}
/**
  *path_finder - function that finds and returns value of PATH
  *Return: Value of path or NULL
  */
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
/**
  *find_executable - function to find executable after a command is given
  *@cmd: command
  *Return: NULL on failure
  */
char *find_executable(char *cmd)
{
	char *path = path_finder(), *tk, *filepth;
	int cmd_len = str_len(cmd), path_len;

	if (path == NULL)
	{
		perror("No match");
		return (NULL);
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
		str_cpy(filepth, tk);
		str_cat(filepth, "/");
		str_cat(filepth, cmd);
		if (access(filepth, X_OK) == 0)
			return (filepth);
		free(filepth);
		tk = strtok(NULL, ":");
	}
	return (NULL);
}
