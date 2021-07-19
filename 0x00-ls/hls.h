#ifndef _HLS_H_
#define _HLS_H_

#include <stdio.h> /* sprintf, perror */
#include <dirent.h> /* DIR type */
#include <errno.h>	/* errno */
#include <stdlib.h> /* malloc, free */
#include <sys/stat.h> /* stat, struct stat */
#include <dirent.h> /* stat, struct stat */
#include <string.h> /* strcmp */
#include <stdarg.h> /* va_start, va_arg, va_end */
#include <pwd.h> /* getpwuid */
#include <grp.h> /* getgrgid */
#include <time.h> /* ctime */

#define max_t(x, y) (((x) >= (y)) ? (x) : (y))

/**
 * struct flag_s - flag structure
 * @a: show all hidden file (. and ..)
 * @A: show hidden file
 * @One: one line output
 * @r: reverse Sorting
 * @S: size sorting Huge first
 * @t: time sorting New firts
 * @l: long description
 * @R: recursive listing
 */
typedef struct flag_s
	{
		char a;
		char A;
		char One;
		char r;
		char S;
		char t;
		char R;
		char l;
	} flag_t;

/**
 * struct global_s - global variables
 * @flags: flags of the program
 * @program: program name
 * @entry_counter: number of entry (no flags)
 * @status: program status, 0=no_error, 1=??, 2=perror
 */
typedef struct global_s
{
	flag_t flags;
	char *program;
	int status;
	int entry_counter;
} global_t;

/* linked list */
/**
 * struct linked_s - linked list
 * @name: name of element
 * @entry: entry of directory
 * @next: next node
 * @parent: for entries the parent directory
 */
typedef struct linked_s
{
	char *name;
	char *parent;
	struct linked_s *next;
	struct dirent *entry;
} linked_t;

/**
 * struct padding_s - the padding struct for -l flag
 * @pad_links:		- padding for links
 * @pad_usr:		- padding for user
 * @pad_grp:		- padding for group
 * @pad_size:		- paddig for size of file
 */
typedef struct padding_s
{
	int pad_links;
	int pad_usr;
	int pad_grp;
	int pad_size;
} padding_t;

/**
 * enum linked_append_opts - options for append in linked list
 * @DIR_ENTRY: if it's a entry of directory
 * @ARGS: if has args
 */
enum linked_append_opts
{
	DIR_ENTRY,
	ARGS
};

global_t *globals(void);
int hls(char *argv[]);
void splitargv(linked_t **dir, linked_t **file, char **argv);
void _perror(char *argv);
void print_content(linked_t *dir_list, linked_t *file_list);
int _strcmp(char *a, char *b);
void getlstat(struct stat *mystat, linked_t *list);
padding_t getpadding(linked_t *list);
void printl(linked_t *entry, padding_t padding);
size_t _strlen(const char *s);

/* linked list */
linked_t *list_append(linked_t **head, int type, ...);
void list_free(linked_t *head);

#endif /* _HLS_H_ */
