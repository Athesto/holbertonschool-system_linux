#include "hls.h"

/**
 * _perror - write error message
 * @argv: argument for error
 */
void _perror(char *argv)
{
	char msg[1024];
	char *program = globals()->program;
	int *status = &globals()->status;

	sprintf(msg, "%s: cannot access '%s'", program, argv);
	perror(msg);
	*status = 2;
}
