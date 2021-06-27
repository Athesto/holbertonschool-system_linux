#include "signals.h"
/**
 * main - prints a description of a given signal
 * @argc: argument counter
 * @argv: is the signal number to be described
 * Return: EXIT_FAILURE or EXIT_SUCCESS
 */
int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		printf("Usage: %s <signum>\n", argv[0]);
		return (EXIT_FAILURE);
	}
	printf("%d: %s\n", 1, "Hangup");

	return (EXIT_SUCCESS);
}
