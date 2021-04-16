#include <stddef.h>
/**
 * _strchr - search char in string
 * @cs: string
 * @c: Searching character
 * Return: Pointer to c in cs, NULL otherwise
 */
char *_strchr(char *cs, char c)
{
	if (!cs)
		return (NULL);

	while (*cs)
	{
		if (*cs == c)
			return (cs);
		cs++;
	}
	return (NULL);
}
