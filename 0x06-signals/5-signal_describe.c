#include "signals.h"
/**
 * main - prints a description of a given signal
 * @argc: argument counter
 * @argv: is the signal number to be described
 * Return: EXIT_FAILURE or EXIT_SUCCESS
 */
int main(int argc, char *argv[])
{
	char *name;

	if (argc != 2)
	{
		printf("Usage: %s <signum>\n", argv[0]);
		return (EXIT_FAILURE);
	}
	name = strsignal(atoi(argv[1]));
	printf("%s: %s\n", argv[1], name);
	return (EXIT_SUCCESS);
}
