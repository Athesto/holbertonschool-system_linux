#ifndef _GETLINE_H_
#define _GETLINE_H_
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#define READ_SIZE 10240
char *_getline(const int fd);

#endif /* _GETLINE_H_ */
