#ifndef _HSL_TEST_H_
#define _HSL_TEST_H_

#include <dirent.h>		/* get_pre */
#include <pwd.h>		/* getpwnam */
#include <grp.h>		/* getgrnam */
#include <sys/types.h>	/* get_pre */
#include <sys/stat.h>	/* get_pre */
#include <unistd.h>		/* lstat */
#include <time.h>		/* ctime */
#include <stdlib.h>		/* free, malloc */
#include <stdio.h>		/* sprintf, fprintf */
#include <errno.h>		/* errorno */

/**
 * struct flags - flags
 * @a: show all
 * @A: allmost all (ignores ., ..)
 * @l: long list
 * @r: reverse
 * @S: sort by Size
 * @t: sort by time
 * @R: recursive search
 * @one: -1 one line print
 */
typedef struct flags
{
	char a;
	char A;
	char l;
	char r;
	char S;
	char t;
	char R;
	char one;
} flag_t;

/**
 * struct prereq - prerequisites
 * @len: len of string
 * @max_size: max size
 * @blocks: total block
 * @argc: argc
 * @path: path
 */
typedef struct prereq
{
	size_t len;
	int max_size;
	int blocks;
	int argc;
	char *path;
} pre_t;

char *_strchr(char *, char);
int _strcmp(char *, char *);
flag_t get_flags(char **);
int get_pre(pre_t *, flag_t, char *);
struct dirent **get_array(pre_t, flag_t, char *);
void print(pre_t, flag_t, struct dirent **);
int numlen(int);
char *long_format(pre_t data, char *, char *);


#endif /* _HSL_TEST_H_ */
