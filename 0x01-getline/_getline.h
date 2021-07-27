#ifndef _GETLINE_H_
#define _GETLINE_H_

#include <unistd.h> /* read */
#include <stdio.h> /* printf */
#include <string.h> /* strdup */
#include <stdlib.h> /* realloc */

#define READ_SIZE 2

/**
 * struct fd_s - struct of file descriptors
 * @fd: searching descriptor
 * @bytes: number of bytes in the buffer
 * @buf: return buffer
 * @next: next file descriptor's structure
 */
typedef struct fd_s
{
	int fd;
	ssize_t bytes;
	char buf[READ_SIZE];
	struct fd_s *next;
} fd_t;

char *shift(char *dst, char *src);
char *_getline(const int fd);
fd_t *linked_get(const int fd);
fd_t *linked_add(fd_t **head, const int fd);
void linked_free(fd_t *head);
#endif /* _GETLINE_H_ */
