#include "simple_shell.h"

#include <stdio.h>
#include <stddef.h>

/**
 * print_strings - prints strings in an array of strings
 * @strings: an array of strings
 */
void print_strings(char **strings)
{
	int i;

	if (strings == NULL)
		return;
	for (i = 0; ; i++)
	{
		if (strings[i] == NULL)
			break;
		printf("%s\n", strings[i]);
	}
}

