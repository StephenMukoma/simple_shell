#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>

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

void prompt()
{
	printf("($)");
}

int main(void)
{
	char cmd[100], command[100], *parameters[20];

	while (1)
	{
		prompt();
		read_command(command, parameters);

		if (fork() != 0)
			wait(NULL);

		else
		{
			execve(cmd, parameters, NULL);
		}
	if (strcmp(command, "exit") == 0)
		break;
	}
	return (0);
}