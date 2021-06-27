#include "../signals.h"
/**
 * print_hello - print hello
 * @code: input code
 */
void print_hello(int code)
{
	(void)code;
	printf("Hello :\n");
}

/**
 * set_print_hello - fun = SIGINT
 */
void set_print_hello(void)
{
	signal(SIGINT, print_hello);
}
