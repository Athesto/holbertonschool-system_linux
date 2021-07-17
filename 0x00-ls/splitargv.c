#include "hls.h"
void setflag(char *);
int isdir(const char *name);

/**
 * splitargv - split arguments
 * @dir: linked list of directories
 * @file: linked list of files
 * @argv: arguments
 */
void splitargv(linked_t **dir, linked_t **file, char **argv)
{
	int i, dir_info;
	int *entry_counter = &globals()->entry_counter;

	for (i = 1; argv[i]; i++)
	{
		if (*argv[i] == '-')
		{
			setflag(argv[i]);
			continue;
		}
		(*entry_counter)++;
		dir_info = isdir(argv[i]);
		if (dir_info == 0)
			_perror(argv[i]);
		else if (dir_info == 1)
			list_append(file, ARGS, argv[i]);
		else
			list_append(dir, ARGS, argv[i]);
	}

	if (*entry_counter == 0 && *file == NULL && *dir == NULL)
		list_append(dir, ARGS, ".");
}

/**
 * isdir - check if an element is a dir
 * @name: pathname
 * Return: 0=not-file-dir, 1=file, 2=dir
 */
int isdir(const char *name)
{
	struct stat my_stat = {0};

	if (lstat(name, &my_stat))
		return (0);

	if (S_ISREG(my_stat.st_mode))
		return (1);
	return (2);
}

/**
 * setflag - set flags in global variable;
 * @argv: argument vector
 */
void setflag(char *argv)
{
	flag_t *flag = &globals()->flags;
	int i;

	for (i = 0; argv[i]; i++)
	{
		switch (argv[i])
		{
			case 'a':
				flag->a = 1;
				break;
			case 'A':
				flag->A = 1;
				break;
			case '1':
				flag->One = 1;
				break;
			case 'r':
				flag->r = 1;
				break;
			case 'S':
				flag->S = 1;
				break;
			case 't':
				flag->t = 1;
				break;
			case 'R':
				flag->R = 1;
				break;
			case 'l':
				flag->One = 1;
				flag->l = 1;
				break;
			default:
				break;
		}
	}

}
