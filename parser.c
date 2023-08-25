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
/**
  *get_token - function to tokenize string based on delimiters
  *@inputptr: string inputted at line
  *@bytesread: bytes read at line from inputptr
  *Return: arrau of token pointers
  */
char **get_token(char *inputptr, ssize_t bytesread)
{
	char **commandsto = NULL;
	char  *dlim = " \t\n\0", *tken = NULL;
	int i = 0, j;
	int tken_len;

	commandsto = malloc(sizeof(char *) * (bytesread + 1));
	if (commandsto == NULL)
		return (NULL);

	tken = strtok(inputptr, dlim);

	while (tken != NULL)
	{
		tken_len = str_len(tken);
		commandsto[i] = malloc(sizeof(char) * (tken_len + 1));
		if (commandsto[i] == NULL)
		{
			for (j = 0; j < i; j++)
			{
				free(commandsto[j]);
			}
			free(commandsto);
			return (NULL);
		}
		str_cpy(commandsto[i], tken);
		tken = strtok(NULL, dlim);
		i++;
	}
	commandsto[i] = NULL;
	return (commandsto);
}
/**
 * free_tokens - free memory
 * @commandsto: to be freed
 * Return: void
 **/
void free_tokens(char **commandsto)
{
	int i;

	if (commandsto == NULL)
		return;

	for (i = 0; commandsto[i] != NULL; i++)
	{
		free(commandsto[i]);
	}
	free(commandsto);
}

/**
  * _cd - custom cd
  * @dir: directory
  * Return: 0 on success,
  * -1 on failure
  */
int _cd(const char *dir)
{
	char *bf = NULL;
	size_t size = SIZE_BUF;

	if (dir == NULL)
		dir = getcwd(bf, size);
	if (chdir(dir) == -1)
	{
		perror(dir);
		return (98);
	}
	return (1);
}
