#include <stdio.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#define MAX_COMMAND_LENGTH 100
/**
 * main - shell command
 *
 * Return: Always 0.
 */
int main(void)
{
char command[MAX_COMMAND_LENGTH];
while (1)
{
scanf("%[^\n]", command);
command[strcspn(command, "\n")] = '\0';
if (fork() == 0)
{
execlp(command, command, NULL);
printf("Command not found: %s\n", command);
exit(1);
}
else
{
wait(NULL);
}
}
return (0);
}
