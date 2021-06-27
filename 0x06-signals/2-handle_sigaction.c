#include "signals.h"
#include "string.h"

/**
 * printGotcha - print Gotcha and code
 * @code: input code
 */
void printGotcha(int code)
{
	printf("Gotcha! [%d]\n", code);
	fflush(stdout);
}

/**
 * handle_sigaction - set a handler for the signal SIGINT
 * Return: 0 on success, or -1 on error
 */
int handle_sigaction(void)
{
	sigaction_t act; /* vagrant is happy with a variable initalized */

	memset(&act, 0, sizeof(act));
	act.sa_handler = printGotcha;
	return (sigaction(SIGINT, &act, NULL));
}
