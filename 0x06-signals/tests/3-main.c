#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

#include "../signals.h"
typedef unsigned long int u16;

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

	handler = current_handler_sigaction();
	printf("Address of the current handler: %#lx\n", (u16)handler);

	/* Set 'print_hello()` as the handler for SIGINT */
	set_print_hello();

	handler = current_handler_sigaction();
	printf("Address of the 'print_hello' function: %#lx\n", (u16)&print_hello);
	printf("Address of the current handler: %#lx\n", (u16)handler);

	for (i = 0; ; i++)
	{
		printf("[%d] Wait for it ...\n", i);
		sleep(1);
	}
	return (EXIT_SUCCESS);
}
