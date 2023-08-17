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
void executemd(char **input_command);
int str_len(char *s);
char *str_cpy(char *dest, char *src);
char **get_token(char *inputptr, ssize_t bytesread);
int _strcmp(char *s1, char *s2);
#endif /*SIMPLE_SHELL_H_*/
