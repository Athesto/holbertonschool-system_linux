#include "hls.h"

/**
 * _perror - write error message
 * @argv: argument for error
 */
void _perror(char *argv)
{
	char *msg;
	char *tmp;
	char *program = globals()->program;
	int *status = &globals()->status;

	switch (errno)
	{
		case EACCES:
			tmp = "%s: cannot open directory %s";
			break;
		default:
			tmp = "%s: cannot access %s";

	}
	msg = malloc(strlen(tmp) + strlen(program) + strlen(argv));
	sprintf(msg, tmp, program, argv);
	perror(msg);
	free(msg);
	*status = 2;
}
