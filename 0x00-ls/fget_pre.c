#include "hls.h"
#include "string.h"
/**
 * get_pre - get previous valuies
 * @data: my data
 * @my_flags: my flags
 * @path: paths
 * Return: Status code
 */
int get_pre(pre_t *data, flag_t my_flags, char *path)
{
	int len = 0;
	int max_size = 0;
	int isAlmost;
	DIR *dir;
	char *file_name;
	struct dirent *entry;
	struct stat mystat = {0};
	int total_blocks = 0;
	char buffer[80];

	dir = opendir(path);
	if (!dir)
	{
		return (errno);
	}

	while ((entry = readdir(dir)) != NULL)
	{
		file_name = entry->d_name;

		isAlmost = my_flags.A &&\
					_strcmp(file_name, ".") &&\
					_strcmp(file_name, "..");

		if (my_flags.a || isAlmost || file_name[0] != '.')
		{
			len++;
			sprintf(buffer, "%s%s", path, file_name);
			lstat(buffer, &mystat);
			total_blocks += mystat.st_blocks;
			if (mystat.st_size > max_size)
				max_size = mystat.st_size;
		}

	}
	closedir(dir);
	data->len = len;
	data->max_size = max_size;
	data->blocks = total_blocks;
	return (EXIT_SUCCESS);
}

