#include "main.h"

/**
*read_command - function that reads a command
*
*@cmd: command to be read
*
*@par: pointer to command
*/
void read_command(char cmd[], char *par[])
{
	char line[1024];
	int count = 0, i = 0, j = 0;
	char *array[100], *pch;

	for (;;)
	{
		int c = fgetc(stdin);

		line[count++] = (char)c;

		if (c == '\n')
			break;
	}
	if (count == 1)
		return;

	pch = strtok(line, " \n");

	while (pch != NULL)
	{
		array[i++] = strdup(pch);
		pch = strtok(NULL, " \n");
	}
	strcpy(cmd, array[0]);

	for (j = 0; j < i; j++)
		par[j] = array[j];
		par[i] = NULL;
}

/**
*prompt - function that asks for an input
*
*/
void prompt(void)
{
	printf("($)");
}

/**
*main - opeartes like shell
*
*Return: 0 (success)
*/
int main(void)
{
	pid_t child_pid;
	char cmd[100], command[100], *parameters[20];
	char *envp[] = { (char *) "PATH=/bin", 0 };

	while (1)
	{
		prompt();
		read_command(command, parameters);

		child_pid = fork();

		if (child_pid == -1)
		{
			perror("Error:");
			return (1);
		}
		 if (strcmp(command, "exit") == 0)
                        break;

		if (child_pid == 0)
		{
			strcpy(cmd, "/bin/");
			strcat(cmd, command);
			execve(cmd, parameters, envp);

			if (execve(cmd, parameters, envp) == -1)
                	{
                        	perror("not found");
				exit(1);
                	}

		}
		else
		{
			wait(NULL);
		}
	}
	return (0);
}
