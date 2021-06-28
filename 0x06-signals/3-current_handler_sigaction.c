#include "signals.h"

/**
 * current_handler_sigaction - retrieves the current handler
 * of the signal SIGINT
 * Return: a pointer to the current handler of SIGINT, or NULL on failure
 */
void (*current_handler_sigaction(void))(int)
{
	sigaction_t prev;

	memset(&prev, 0, sizeof(prev));
	if (!sigaction(SIGINT, NULL, &prev))
		return (prev.sa_handler);
	return (NULL);
}
