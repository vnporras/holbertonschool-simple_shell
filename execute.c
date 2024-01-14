#include "main.h"

/**
* execute - function that executes commands.
* @userCommand: It is a pointer where the user enters commands.
*/

void execute(char *userCommand)
{
	char *args[1024];
	int argCount = 0;
	char *token;
	pid_t pid;

	token = strtok(userCommand, " ");
	while (token != NULL && argCount < 1023)
	{
		args[argCount++] = token;
		token = strtok(NULL, " ");
	}
	args[argCount] = NULL;
	pid = fork();
	if (pid == -1)
	{
		perror("Fork failed");
		exit(EXIT_FAILURE);
	}
	if (pid == 0)
	{
		execvp(args[0], args);
		perror("Error executing command");
		exit(EXIT_FAILURE);
	}
	else
	{
		int status;
		waitpid(pid, &status, 0);
	}
}
