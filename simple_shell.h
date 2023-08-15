#ifndef SIMPLE_SHELL_H_
#define SIMPLE_SHELL_H_

/* Global extern variable */
extern char **environ;

/*header files*/
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

void showprompt(void);
void executemd(char *input_command);

#endif /*SIMPLE_SHELL_H_*/
