#ifndef SIMPLE_SHELL_H
#define SIMPLE_SHELL_H

#include <stddef.h>

int is_white_space(char *str);
char *_getenv(const char *name);
void print_strings(char **strings);
void tokenize(char **all_tokens, char *line, char *delims);

#endif
