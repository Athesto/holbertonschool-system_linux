#include "signals.h"
/**
 * current_handler_signal - retrieves the current handler of the signal SIGINT
 * Return: a pointer to the current handler of SIGINT
 */
void (*current_handler_signal(void))(int)
{
	handler_t handler;

	handler = signal(SIGINT, NULL);
	signal(SIGINT, handler);

	if (handler == SIG_ERR)
		return (NULL);
	return (handler);
}
