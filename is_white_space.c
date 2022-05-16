#include "simple_shell.h"
#include <ctype.h>

/**
 * is_white_space - checks if a string is just white spaces
 * @str: the string
 * Return: returns 1 or 0
 */
int is_white_space(char *str)
{
	while (*str != '\0')
	{
		if (!isspace(*str))
			return (0);
		str++;
	}
	return (1);
}

