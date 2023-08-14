#ifndef SIMPLE_SHELL_H_
#define SIMPLE_SHELL_H_

/*header files*/
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

void showprompt(void);
void executemd(char *argv[]);

#endif /*SIMPLE_SHELL_H_*/
