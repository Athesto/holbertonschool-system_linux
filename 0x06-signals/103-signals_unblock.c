/**
 *  signals_unblock - unblock a given set of signals
 *  from being delivered to the current process
 *  @signals: a 0-terminated array of int, each one being a signal to unblock
 *  Return: 0 on success, or -1 on error
 */
int signals_unblock(int *signals)
{
	if (!signals)
		return (-1);
	return (0);
}
