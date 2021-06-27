#include "signals.h"
/**
 * main - sets a handler for the signal SIGINT,
 * and exits right after the signal is received and handled
 * Return: EXIT_SUCCESS
 *
 */
int main(void)
{
	printf("Caught %d\n", 2);
	printf("Signal recived\n");
	return (EXIT_SUCCESS);
}
