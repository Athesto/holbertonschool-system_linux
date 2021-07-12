#include "signals.h"


void printCaught(int code)
{
	printf("Caught %d\n", code);
	fflush(stdout);
}
/**
 * main - sets a handler for the signal SIGINT,
 * and exits right after the signal is received and handled
 * Return: EXIT_SUCCESS
 *
 */
int main(void)
{
	sigset_t set;
	int code;
	sigaction_t handler;



	sigemptyset(&set);
	sigaddset(&set, SIGINT);

	sigwait(&set, &code);
	printf("Signal recived\n");
	fflush(stdout);

	return (EXIT_SUCCESS);
}
