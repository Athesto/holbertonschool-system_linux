#include "signals.h"
/**
 * response - response for interruptions
 * @code: interruption code
 *
 */
void response(int code)
{
	printf("Gotcha! [%d]\n", code);
}

/**
 * handle_signal - handle signal
 * Return: 0 on Success or -1 on error
 */
int handle_signal(void)
{
	if (signal(SIGINT, response) == SIG_ERR)
		return (-1);
	return (0);
}
