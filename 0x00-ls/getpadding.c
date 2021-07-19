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
	int len = 0;
	struct stat mystat = {0};
	int counter, tmp;
	char *user_name, *user_group;
	struct passwd *passswd_s;
	struct group *group_s;

	printf("entry in get padding\n");
	for (runner = list; runner; runner = runner->next)
	{
		printf("entry in get padding\n");
		getlstat(&mystat, runner);

		max_pd.pad_links = max_t(max_pd.pad_links, (int)mystat.st_nlink);
		printf("post getlstat\n");

		passswd_s = getpwuid(mystat.st_uid);
		if (passswd_s)
			user_name = passswd_s->pw_name;
		else
			user_name = NULL;

		if (user_name)
			len = _strlen(user_name);
		max_pd.pad_usr = max_t(max_pd.pad_usr, len);
		printf("post pwuid\n");

		group_s = getgrgid(mystat.st_uid);

		if (group_s)
			user_group = group_s->gr_name;
		else
			user_group = NULL;

		if (user_group)
			len = _strlen(user_group);
		max_pd.pad_grp = max_t(max_pd.pad_grp, len);

		max_pd.pad_size = max_t(max_pd.pad_size, mystat.st_size);
	}
	printf("post for padding\n");
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
