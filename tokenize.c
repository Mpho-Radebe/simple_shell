#include "simple_shell.h"
#include <stddef.h>
#include <string.h>

/**
 * rm_trail_space - remove the trailing spaces
 * @str: the string
 *
 */
void rm_trail_space(char *str)
{
	while (*str != '\0')
	{
		if (*str == ' ' || *str == '\n' || *str == '\0' || *str == '\t')
			*str = '\0';
		str++;
	}
}

/**
 * tokenize - tokenizes the strings
 *
 * @all_tokens: all the tokens
  * @line: string being tokenized
 * @delims: delimiters
 */
void tokenize(char **all_tokens, char *line, char *delims)
{
	char* token = NULL;
	size_t len = 0;

	token = strtok(line, delims);

	while (tokekn != NULL)
	{
		rm_trail_space(token);
		all_tokens[(int)(len)] = token;
		len++;

		token = strtok(NULL, delims);
	}
	all_tokens[len] = NULL;
}


