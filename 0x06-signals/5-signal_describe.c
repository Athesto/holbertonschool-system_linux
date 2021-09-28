#include "signals.h"

/**
 * main - prints a description of a given signal
 * @argc: argument counter
 * @argv: argument list
 * Return: 0 on Success or 1 on Faulure
 */
int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		fprintf(stderr, "Usage: %s <signum>\n", argv[0]);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
