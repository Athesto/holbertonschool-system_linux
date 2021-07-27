#include "_getline.h"

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
	char *buf, *dst = NULL;
	fd_t *list;
	ssize_t bytes;

	list = linked_get(fd);
	if (fd == -1 || !list)
		return (NULL);

	buf = list->buf;
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

/**
 * linked_get - manage file descriptors
 * @fd: if -1: free all file descriptors, or search fd,
 * if the fd not found it create it
 * Return: struct of file descriptor
 */
fd_t *linked_get(const int fd)
{
	static fd_t *head;
	fd_t *runner;

	if (fd == -1)
	{
		linked_free(head);
		return (NULL);
	}

	for (runner = head; runner && runner->fd != fd; runner = runner->next)
		;

	if (runner == NULL)
		runner = linked_add(&head, fd);

	return (runner);
}

/**
 * linked_free - free linked list
 * @head: head of linked list
 */
void linked_free(fd_t *head)
{
	if (head)
		linked_free(head->next);
	free(head);
}

/**
 * linked_add - add new element into the linked list
 * @head: reference to the linked list
 * @fd: file descriptor
 * Return: new node or null if it FAILS
 */
fd_t *linked_add(fd_t **head, const int fd)
{
	fd_t *new;

	new = malloc(sizeof(*new));
	if (!new)
		return (NULL);
	new->fd = fd;
	new->next = NULL;
	memset(new->buf, 0, READ_SIZE);

	if (*head == NULL)
		new->next = *head;

	*head = new;
	return (new);
}
