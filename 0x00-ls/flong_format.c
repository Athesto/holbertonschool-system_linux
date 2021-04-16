#include "hls.h"
#include <stdio.h>

char *gettime(time_t *);

/**
 * long_format - long format string
 * @data: input data
 * @buffer: bufer to print
 * @filename: filepath
 * Return: String with format
 */
char *long_format(pre_t data, char *buffer, char *filename)
{
	int format_len;
	char output_format[] =
		/* "%c%c%c%c%c%c%c%c%c%c %d %s %s %d %s %s"; */
		"%%c%%c%%c%%c%%c%%c%%c%%c%%c%%c %%d %%s %%s %%%dd %%s %%s";
	struct stat mystat = {0};
	struct passwd *pwd_info;
	struct group *grp_info;
	char *format_time;
	char type;
	char buffer_filename[80];

	sprintf(buffer_filename, "%s/%s", data.path, filename);

	lstat(buffer_filename, &mystat);
	pwd_info = getpwuid(mystat.st_uid);
	grp_info = getgrgid(mystat.st_gid);
	format_time = gettime(&mystat.st_mtime);

	switch (mystat.st_mode & S_IFMT)
	{
		case S_IFLNK:
			type = 'l';
			break;
		case S_IFDIR:
			type = 'd';
			break;
		case S_IFSOCK:
			type = 's';
			break;
		default:
			type = '-';
	}

	format_len = numlen(data.max_size);
	sprintf(output_format, output_format, format_len - 1);
	sprintf(buffer, output_format,
			type,
			(mystat.st_mode & S_IRUSR) > 0 ? 'r' : '-',
			(mystat.st_mode & S_IWUSR) > 0 ? 'w' : '-',
			(mystat.st_mode & S_IXUSR) > 0 ? 'x' : '-',
			(mystat.st_mode & S_IRGRP) > 0 ? 'r' : '-',
			(mystat.st_mode & S_IWGRP) > 0 ? 'w' : '-',
			(mystat.st_mode & S_IXGRP) > 0 ? 'x' : '-',
			(mystat.st_mode & S_IROTH) > 0 ? 'r' : '-',
			(mystat.st_mode & S_IWOTH) > 0 ? 'w' : '-',
			(mystat.st_mode & S_IXOTH) > 0 ? 'x' : '-',
			mystat.st_nlink,
			pwd_info->pw_name,
			grp_info->gr_name,
			mystat.st_size,
			format_time,
			filename);
	return (buffer);
}

/**
 * gettime - get the time of a element
 * @mytime: input
 * Return: String with format
 *
 */
char *gettime(time_t *mytime)
{
	int number_colon = 2;
	char *format_time;
	int i;


	format_time = ctime(mytime);
	while (*format_time != ' ')
		format_time++;
	format_time++;
	for (i = 0; format_time[i]; i++)
	{
		if (format_time[i] == ':')
			number_colon--;
			if (!number_colon)
				format_time[i] = '\0';
	}
	return (format_time);
}
