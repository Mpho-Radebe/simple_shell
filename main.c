#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include "simple_shell.h"

int getfullpath(char *program, char* full_path)
{
    struct stat stat_;
    int l = 0;
    char *path[100];

    tokenize(path, getenv("PATH"), ":");

    while (path[l] != NULL)
    {
        sprintf(full_path, "%s/%s", path[l], program);
        if (stat(full_path, &stat_) == 0)
            return 1;
        l++;
    }

    return 0;
}

void copy(char **from, char **to)
{
    int k = 1;

    while (from[k] != NULL)
    {
        to[k - 1] = from[k];
        k++;
    }
    to[k - 1] = NULL;
}

/**
 * main - the main program
 * @argc: argument count
 * @argv: argument vector
 * @env: enviroment variable
 *
 * Return: 0 or 1
 */
int main(int argc, char **argv, char **env)
{
	pid_t child_pid;
	char *response = NULL;
	char *params[100], program_name[250];
	int status;
	size_t len1;
	struct stat stat_;
	int not_first_time = 0;

	while (1)
	{
		if (not_first_time || argc <= 1)
		{
			printf("#cisfun$ ");
			if (getline(&response, &len1, stdin) == -1)
				return (1);
			if (is_white_space(response))
				return (1);
			tokenize(params, response, " \n");
        }
		else
		{
			not_first_time = 1;
            copy(argv, params);
		}
		if (strcmp(params[0], "exit") == 0)
			break;
		if (strcmp(params[0], "env") == 0)
		{
			print_strings(env);
			continue;
		}
		if (stat(params[0], &stat_) == -1)
		{
			if(getfullpath(params[0], program_name) == 0)
			{
				printf("%s: No such file or directory\n", argv[0]);
				continue;
			}
			else
				params[0] = program_name;
		}
		child_pid = fork();
		if (child_pid == 0)
			execve(params[0], params, NULL);
		else
			wait(&status);
	}
	return (0);
}
