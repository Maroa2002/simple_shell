#ifndef SIMPLE_SHELL_H_
#define SIMPLE_SHELL_H_

#define SIZE_BUF 1024
#define MAX_PATH_LENGTH 256

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
char *str_cat(char *dest, char *src);
char *str_dup(char *str);
char *find_executable(char *cmd);
void printenv(void);
void EOF_handler(char *inputptr);
void free_tokens(char **commandsto);
int _cd(const char *dir);

#endif /*SIMPLE_SHELL_H_*/
