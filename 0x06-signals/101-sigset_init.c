#include "signals.h"
/**
 * sigset_init - initializes a sigset
 * @set: pointer to the signal set to initialize
 * @signals: 0-terminated array of int, each one being a signal number
 * Return: 0 on success, or -1 on error
 */
int sigset_init(sigset_t *set, int *signals)
{
	if (!set || !signals)
		return (-1);
	return (0);
}
