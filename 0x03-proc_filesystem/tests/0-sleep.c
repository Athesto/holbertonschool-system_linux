#include <string.h>		/* strdup */
#include <unistd.h>		/* sleep, getpid */
#include <stdio.h>		/* printf */

int main(void)
{
	char *msg;
	pid_t pid;
	int counter;

	msg = strdup("Welcome to Holberton");
	pid = getpid();
	counter = 0;
	while(1)
	{
		printf("[%d] %4d: %s\n", pid, counter++, msg);
		sleep(1);
	}

}

