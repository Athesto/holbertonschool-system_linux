#include "hls.h"

/**
 * _perror - write error message
 * @argv: argument for error
 */
void _perror(char *argv)
{
	char msg[1024];
	char *tmp;
	char *program = globals()->program;
	int *status = &globals()->status;

	switch (errno)
	{
		case EACCES:
			tmp = "%s: cannot open directoy %s";
			break;
		default:
			tmp = "%s: cannot access %s";

	}
	sprintf(msg, tmp, program, argv);
	perror(msg);
	*status = 2;
}
