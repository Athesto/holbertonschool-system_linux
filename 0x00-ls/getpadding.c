#include "hls.h"
/**
 * getpadding - it gets the padding for the format of l flag
 * @list: linked list
 * Return: structure of padding
 */
padding_t getpadding(linked_t *list)
{
	linked_t *runner;
	padding_t padding = {0}, max_pd = {0};
	int len;
	struct stat mystat = {0};
	int counter, tmp;

	for (runner = list; runner; runner = runner->next)
	{
		getlstat(&mystat, runner);
		max_pd.pad_links = max_t(max_pd.pad_links, (int)mystat.st_nlink);

		len = _strlen(getpwuid(mystat.st_uid)->pw_name);
		max_pd.pad_usr = max_t(max_pd.pad_usr, len);

		len = _strlen(getgrgid(mystat.st_uid)->gr_name);
		max_pd.pad_grp = max_t(max_pd.pad_grp, len);

		max_pd.pad_size = max_t(max_pd.pad_size, mystat.st_size);
	}
	counter = 0;
	for (counter = 0, tmp = max_pd.pad_links; tmp; counter++)
		tmp /= 10;
	padding.pad_links = counter;

	padding.pad_usr = max_pd.pad_usr;
	padding.pad_grp = max_pd.pad_grp;

	counter = 0;
	for (counter = 0, tmp = max_pd.pad_size; tmp; counter++)
		tmp /= 10;
	padding.pad_size = counter;

	return (padding);

}
