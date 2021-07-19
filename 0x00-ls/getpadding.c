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
	struct stat mystat = {0};
	int counter, tmp, len = 0;
	char *user_name, *user_group;
	struct passwd *passwd_s;
	struct group *group_s;

	for (runner = list; runner; runner = runner->next)
	{
		getlstat(&mystat, runner);

		max_pd.pad_links = max_t(max_pd.pad_links, (int)mystat.st_nlink);

		passwd_s = getpwuid(mystat.st_uid);
		user_name = (passwd_s) ? passwd_s->pw_name : NULL;
		len = (user_name) ? _strlen(user_name) : 0;
		max_pd.pad_usr = max_t(max_pd.pad_usr, len);

		group_s = getgrgid(mystat.st_uid);
		user_group = (group_s) ? group_s->gr_name : NULL;
		len = (user_group) ? _strlen(user_group) : 0;
		max_pd.pad_grp = max_t(max_pd.pad_grp, len);

		max_pd.pad_size = max_t(max_pd.pad_size, mystat.st_size);
	}

	for (counter = 0, tmp = max_pd.pad_links; tmp; counter++)
		tmp /= 10;
	padding.pad_links = counter;

	for (counter = 0, tmp = max_pd.pad_size; tmp; counter++)
		tmp /= 10;
	padding.pad_size = counter;

	padding.pad_usr = max_pd.pad_usr;
	padding.pad_grp = max_pd.pad_grp;

	return (padding);

}
