#include "_getline.h"
/**
 * _getline - custom getline
 * @fd: file descriptor to read from
 * Return: NULL if it's an error or a pointer j
 */
char *_getline(const int fd)
{
	char local_buffer[READ_SIZE] = {0};
	char *buffer;
	ssize_t bytes;

	bytes = read(fd, local_buffer, READ_SIZE);
	if (bytes > 0)
	{
		buffer = malloc((bytes + 1) * sizeof(*buffer));
		if (!buffer)
			return (NULL);
		strcpy(buffer, local_buffer);

		return (buffer);
	}

	return (NULL);
}
