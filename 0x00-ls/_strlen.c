#include "hls.h"

/**
 * _strlen - len of string
 * @s: input str
 * Return: len
 */
size_t _strlen(const char *s)
{
	size_t len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}
