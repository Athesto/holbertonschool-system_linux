#ifndef _GETLINE_H_
#define _GETLINE_H_

#include <unistd.h>

#define READ_SIZE 2
char *_strchr(const char *str, char c);
char *shift(char *dst, char *src);
char *_getline(const int fd);
#endif /* _GETLINE_H_ */
