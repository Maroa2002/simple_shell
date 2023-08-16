#include "simple_shell.h"

/**
  *str_len - function to check string length
  *@s: paramter for string
  *Return: length of string
  */

int str_len(char *s)
{
	int i;

	for (i = 0; s[i] != '\0'; i++)
	{}
	return (i);
}

/**
 * str_cpy - string copy
 * @dest: destination to copy
 * @src: source to be copied from
 * Return: destination;
 */

char *str_cpy(char *dest, char *src)
{
	int c;

	for (c = 0; c <= str_len(src); c++)
	{
		dest[c] = src[c];
	}
	return (dest);
}

char **get_token(char *inputptr, ssize_t bytesread)
{
	char **commandsto = NULL;
	char  *dlim = " \t\n\0", *tken = NULL;
	int i = 0;
	int tken_len;

	commandsto = malloc(sizeof(char *) * (bytesread + 1));
	if (commandsto == NULL)
		return (NULL);

	tken = strtok(inputptr, dlim);

	while(tken != NULL)
	{
		tken_len = str_len(tken);
		commandsto[i] = malloc(sizeof(char) * (tken_len + 1));
		if (commandsto[i] == NULL)
			return (NULL);
		str_cpy(commandsto[i], tken);
		tken = strtok(NULL, dlim);
		i++;
	}
	commandsto[i] = NULL;
	return (commandsto);
}
