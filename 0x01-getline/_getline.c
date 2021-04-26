#include "_getline.h"

/**
 * _getline - custom getline
 * @fd: file descriptor to read from
 * Return: NULL if it's an error or a pointer j
 */
char *_getline(const int fd)
{
	static char local_buffer[READ_SIZE] = {0};
	static char *tmp;
	char *output;
	int len;

	if (local_buffer[0] == '\0')
	{
		read(fd, local_buffer, READ_SIZE);
		tmp = local_buffer;
	}

	len = 0;
	while (tmp[len] && tmp[len] != '\n')
		len++;

	if (!tmp[len])
		return (NULL);

	output = malloc((len + 1) * sizeof(*output));
	if (!output)
		return (NULL);

	strncpy(output, tmp, len);
	output[len] = '\0';
	tmp = tmp + (len + 1);
	return (output);
}
