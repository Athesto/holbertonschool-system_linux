#include "hls.h"
#include <stdlib.h>
#include <stdio.h>
/**
 * get_array - get elements
 * @data: input data
 * @my_flags: flags
 * @path: filepath
 * Return: struct
 */
struct dirent **get_array(pre_t data, flag_t my_flags, char *path)
{
	struct dirent **array;
	DIR *dir;
	struct dirent *entry;
	char *filename;
	int isAlmost;
	int i;

	array = malloc((data.len + 1) * sizeof(*array));
	if (!array)
		return (NULL);

	{
		/*array, dir (flags, path) */
		{
			dir = opendir(path);
			i = 0;
			while ((entry = readdir(dir)) != NULL)
			{
				filename = entry->d_name;
				isAlmost = my_flags.A &&\
						   _strcmp(filename, ".") &&\
						   _strcmp(filename, "..");

				if (my_flags.a || isAlmost || filename[0] != '.')
				{
					array[i] = entry;
					i++;
				}

			}
			array[i] = NULL;
		}

		/* (flags, array)*/
		{
			data.path = path;
			print(data, my_flags, array);
			closedir(dir);
		}
	}
	free(array);
	return (NULL);
}
