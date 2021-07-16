#include "hls.h"

/**
 * main - ls program
 * @argc: len  of list arguments
 * @argv: list of arguments
 * Return: 0 ok
 */
int main(int argc, char *argv[])
{

	int output;

	globals()->program = argv[0];

	output = hls(argv);

	(void) argc;
	return (output);
}
