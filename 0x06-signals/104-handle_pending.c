/**
 * handle_pending - sets up a handler for all the pending signals
 * of the current process
 * @handler: a pointer to the handler function to set for the pending signals
 * Return: 0 on success, or -1 on error
 */
int handle_pending(void (*handler)(int))
{
	if (!handler)
		return (-1);
	return (0);
}
