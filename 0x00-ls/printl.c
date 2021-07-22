#include "hls.h"
#define BUFSIZE 256

char *getmtime(struct stat mystat);
void getmode(char *p_mode, char *permissions, struct stat mystat);
void _getlink(char *buffer, linked_t *entry, int size);
/**
 * printl - print ls with l flag
 * @entry: path of entry
 * @padding: padding for format
*/
void printl(linked_t *entry, padding_t padding)
{
	char *pre_format = "%%c%%s %%%dd %%%ds %%%ds %%%dd %%s %%s";
	char buffer[BUFSIZE] = "";
	char own_uid[10], group_uid[10];
	char mode;
	struct stat mystat = {0};
	int links;
	off_t size;
	char permissions[] = "rwxrwxrwx";
	char *own, *group, *mod_time, *name;
	struct passwd *passwd_s;
	struct group *group_s;

	getlstat(&mystat, entry);
	sprintf(own_uid, "%d", mystat.st_uid);
	sprintf(group_uid, "%d", mystat.st_gid);

	name = entry->name;
	getmode(&mode, permissions, mystat);
	passwd_s = getpwuid(mystat.st_uid);
	own = (passwd_s) ? passwd_s->pw_name : own_uid;
	group_s = getgrgid(mystat.st_uid);
	group = (group_s) ? group_s->gr_name : group_uid;

	links = mystat.st_nlink;
	size = mystat.st_size;
	mod_time = getmtime(mystat);

	sprintf(buffer, pre_format,
			padding.pad_links, padding.pad_usr,
			padding.pad_grp, padding.pad_size);

	printf(buffer, mode, permissions, links, own, group, size, mod_time, name);
	if (mode == 'l')
	{
		_getlink(buffer, entry, BUFSIZE);
		printf(" -> %s", buffer);
	}
}

/**
 * getmode - set mode and permisions
 * @p_mode: pointer to mode
 * @permissions: read/write/execute/sticky permisions for file
 * @mystat: informations of struct stat
 */
void getmode(char *p_mode, char *permissions, struct stat mystat)
{
	int tmp;
	char mode;

	tmp = mystat.st_mode & S_IFMT;
	mode = '?';
	mode = (tmp == S_IFSOCK) ? 's' : mode; /*socket*/
	mode = (tmp == S_IFLNK)  ? 'l' : mode; /*symbolic link*/
	mode = (tmp == S_IFREG)  ? '-' : mode; /*regular file*/
	mode = (tmp == S_IFBLK)  ? 'b' : mode; /*block device*/
	mode = (tmp == S_IFDIR)  ? 'd' : mode; /*directory*/
	mode = (tmp == S_IFCHR)  ? 'c' : mode; /*character device*/
	mode = (tmp == S_IFIFO)  ? 'p' : mode; /*FIFO*/
	*p_mode = mode;

	permissions[0] = (mystat.st_mode & S_IRUSR) ? 'r' : '-';
	permissions[1] = (mystat.st_mode & S_IWUSR) ? 'w' : '-';
	tmp = '-';
	tmp = (mystat.st_mode & S_IXUSR) ? 'x' : tmp; /*user write permission*/
	tmp = (mystat.st_mode & S_ISUID) ? 'S' : tmp; /*is-gid*/
	permissions[2] = tmp;
	permissions[3] = (mystat.st_mode & S_IRGRP) ? 'r' : '-';
	permissions[4] = (mystat.st_mode & S_IWGRP) ? 'w' : '-';
	tmp = '-';
	tmp = (mystat.st_mode & S_IXGRP) ? 'x' : tmp; /*user write permission*/
	tmp = (mystat.st_mode & S_ISGID) ? 'S' : tmp; /*is-gid*/
	permissions[5] = tmp;
	permissions[6] = (mystat.st_mode & S_IROTH) ? 'r' : '-';
	permissions[7] = (mystat.st_mode & S_IWOTH) ? 'w' : '-';
	tmp = '-';
	tmp = (mystat.st_mode & S_IXOTH) ? 'x' : tmp; /*other write permission*/
	tmp = (mystat.st_mode & S_ISVTX) ? 't' : tmp; /*sticky*/
	permissions[8] = tmp;
}

/**
 * getmtime - get the set time of a struct stat
 * @mystat: stat of element
 * Return: String with format
 *
 */
char *getmtime(struct stat mystat)
{
	int colon_counter = 2;
	char *mod_time;
	int i;

	mod_time = ctime(&mystat.st_mtime);

	while (*mod_time != ' ')
		mod_time++;
	mod_time++;
	for (i = 0; mod_time[i]; i++)
	{
		if (mod_time[i] == ':')
		{
			colon_counter--;
			continue;
		}
		if (!colon_counter)
			mod_time[i - 1] = '\0';

	}
	return (mod_time);
}
/**
 * getlstat - return the lstat of a node
 * @mystat: reference of a stats
 * @list: pointer to node
 */
void getlstat(struct stat *mystat, linked_t *list)
{
	char *name_format = "%s/%s";
	int len;
	char *name;

	if (list->parent == NULL)
		name = list->name;
	else
	{
		len = 0;
		len += _strlen(name_format);
		len += _strlen(list->name);
		len += _strlen(list->parent);

		name = malloc(len);
		sprintf(name, name_format, list->parent, list->name);
	}

	lstat(name, mystat);
	if (list->parent)
		free(name);
}
/**
 * _getlink - get information of a link
 * @buffer: output buffer
 * @entry: entry value
 * @size: size of buffer
 */
void _getlink(char *buffer, linked_t *entry, int size)
{
	char *name_format = "%s/%s";
	int len;
	char *name;

	if (entry->parent == NULL)
		name = entry->name;
	else
	{
		len = 0;
		len += _strlen(name_format);
		len += _strlen(entry->name);
		len += _strlen(entry->parent);

		name = malloc(len);
		sprintf(name, name_format, entry->parent, entry->name);
	}
	len = readlink(name, buffer, size);
	buffer[len] = '\0';
	if (entry->parent)
		free(name);
}

