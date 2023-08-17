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
  *_strdup - function to return pointer to new memory
  *@str: string to copy
  *Return: NULL, pointer to memory
  */
char *_strdup(char *str)
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
char *_getenv(char const *name)
