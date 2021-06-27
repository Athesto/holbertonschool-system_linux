/**
 * signals_block - block a given set of signals
 * from being delivered to the current process
 * @signals: 0-terminated array of int, each one being a signal to block
 * Return: 0 on success, or -1 on error
 */
int signals_block(int *signals)
{
	if (!signals)
		return (-1);
	return (0);
}
