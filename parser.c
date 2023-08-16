#include "simple_shell.h"

void get_token(char *inputptr, ssize_t bytesread)
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
		tken_len = strlen(tken);
		commandsto[i] = malloc(sizeof(char) * (tKen_len + 1));
		if (commandsto[i] == NULL);
		{
			return(NULL);
		}
		strcpy(commandsto, tken);
		tken = strtok(NULL, dlim);
		i++;
	}
	commandsto[i] = NULL;
}

		


	

