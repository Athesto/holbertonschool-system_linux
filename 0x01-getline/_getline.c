#include "_getline.h"
#include <stdio.h> /* printf */
#include <string.h> /* strdup */
#include <stdlib.h> /* realloc */

/**
 * _getline - clone of getline
 * @fd: the file descriptor to read from
 * Return: a null-terminated string that does not include the newline character
 *
 * Notes:
 * - If there are no more lines to return, or if there is an error,
 *   the function should return NULL
 */
char *_getline(const int fd)
{
	int i, len_buf, len_dst;
	static char buf[READ_SIZE];
	char *dst = NULL;
	ssize_t bytes;

	while (1)
	{
		if (*buf)
		{
			for (len_buf = 0; buf[len_buf] && buf[len_buf] != '\n'; len_buf++)
				;
			for (len_dst = 0; dst && dst[len_dst]; len_dst++)
				;
			dst = realloc(dst, sizeof(*dst) * (len_dst + len_buf + 1));
			for (i = 0; i < len_buf ; i++)
				dst[len_dst + i] = buf[i];
			dst[len_dst + len_buf] = '\0';
			shift(buf, buf + len_buf);

			if (*buf == '\n')
			{
				shift(buf, buf + 1);
				break;
			}
		}
		bytes = read(fd, buf, READ_SIZE);
		if (bytes == -1)
			return (NULL);

		buf[bytes] = '\0';
		if (bytes == 0)
			break;
	}
	return (dst);
}


/**
 * shift - move str from a point
 * @dst: destination string
 * @src: source string
 * Return: destination string
 */
char *shift(char *dst, char *src)
{
	int i;
	int diff = (src - dst);

	for (i = 0; i < READ_SIZE; i++)
	{
		if (i + diff < READ_SIZE)
			dst[i] = src[i];
		else
			dst[i] = '\0';
	}
	return (dst);
}

