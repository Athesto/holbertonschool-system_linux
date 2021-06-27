#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

#include "../signals.h"

/* Our functions */
void print_hello(int);
void set_print_hello(void);

/**
 * main - Entry point
 *
 * Return: EXIT_SUCCESS or EXIT_FAILURE
 */
int main(void)
{
	void (*handler)(int);
	int i;
	char *msg[] = {
		"Address of the current handler: %#lx\n",
		"Address of the 'print_hello' function: %#lx\n",
		"Address of the current handler: %#lx\n"
	};

	handler = current_handler_sigaction();
	printf(msg[0], (unsigned long int)handler);

	/* Set 'print_hello()` as the handler for SIGINT */
	set_print_hello();

	handler = current_handler_sigaction();
	printf(msg[1], (unsigned long int)&print_hello);
	printf(msg[2], (unsigned long int)handler);

	for (i = 0; ; i++)
	{
		printf("[%d] Wait for it ...\n", i);
		sleep(1);
	}
	return (EXIT_SUCCESS);
}
