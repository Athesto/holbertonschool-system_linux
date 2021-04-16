#include "hls.h"
/**
 * print - print info
 * @data: important information
 * @myflags: struct with all flags
 * @array: array of elments
 */
void print(pre_t data, flag_t myflags, struct dirent **array)
{
	int i;
	char *filename;
	char buffer[1024];

	if (myflags.l)
	{
		if (data.argc > 1)
			printf("%s:\n", data.path);
		printf("total %d\n", data.blocks / 2);
	}


	for (i = 0; array[i]; i++)
	{
		filename = array[i]->d_name;
		if (myflags.l)
		{
			long_format(data, buffer, filename);
			printf("%s\n", buffer);
		}
		else if (myflags.one)
		{
			printf("%s\n", filename);
		}
		else
		{
			printf("%s ", filename);
		}
	}
	if (!myflags.l && !myflags.one)
		printf("\n");
}

