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
 */
typedef struct linked_s
{
	char *name;
	struct linked_s *next;
	struct dirent *entry;
} linked_t;

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

/* linked list */
linked_t *list_append(linked_t **head, int type, ...);
void list_free(linked_t *head);
void print_content(linked_t *dir_list, linked_t *file_list);
#endif /* _HLS_H_ */
