#include "hls.h"
void print_content_dir(linked_t *entry_list);
void get_content_dir(DIR *dir, char *parent, linked_t **entry_list);

/**
 * print_content - print content of lists
 * @dir_list: list of directories
 * @file_list: list of files
 */
void print_content(linked_t *dir_list, linked_t *file_list)
{
	int file_counter;
	int dir_counter;
	int *entry_counter = &globals()->entry_counter;
	flag_t *flags = &globals()->flags;
	linked_t *runner, *entry_list;
	DIR *dir;
	padding_t padding = {0};


	padding = getpadding(file_list);

	file_counter = 0;

	for (runner = file_list; runner; runner = runner->next, file_counter++)
	{
		if (file_counter)
			printf(flags->One ? "\n" : "  ");
		if (flags->l)
			printl(runner, padding);
		else
			printf("%s", runner->name);
	}
	if (file_counter)
		printf("\n");
	/*
	 * I don't want to use it here.
	 * But, I'm trying to free some memory before allocate more
	 */
	list_free(file_list);

	dir_counter = 0;
	for (runner = dir_list; runner; runner = runner->next, dir_counter++)
	{
		dir = opendir(runner->name);
		if (!dir)
		{
			_perror(runner->name);
			continue;
		}
		entry_list = NULL;
		get_content_dir(dir, runner->name, &entry_list);

		if (file_counter || dir_counter)
			printf("\n");

		if (*entry_counter > 1 || !(dir_list && !dir_list->next))
			printf("%s:\n", runner->name);
		if (flags->l)
			printf("total 0\n");
		/* print_content_dir(entry_list); */
		list_free(entry_list);
		closedir(dir);
	}
}

/**
 * print_content_dir - read directory and print it content
 * @entry_list: list of entries
 */
void print_content_dir(linked_t *entry_list)
{
	int counter;
	flag_t *flags = &globals()->flags;
	linked_t *runner;
	padding_t padding = {0};

	if (flags->l)
		padding = getpadding(entry_list);

	counter = 0;
	for (runner = entry_list; runner; runner = runner->next, counter++)
	{
		if (counter)
			printf(flags->One ? "\n" : "  ");

		if (flags->l)
			printl(runner, padding);
		else
			printf("%s", runner->entry->d_name);

	}
	if (counter)
		printf("\n");
}

/**
 * get_content_dir - get a list of entry elements
 * @dir: directory of entries
 * @parent: name of parent
 * @entry_list: entry
 */
void get_content_dir(DIR *dir, char *parent, linked_t **entry_list)
{
	flag_t *flags = &globals()->flags;
	struct dirent *entry;
	linked_t *node;
	char *name;
	int isEnable = 0;
	int counter;

	for (counter = 0; (entry = readdir(dir)) != NULL; counter++)
	{
		name = entry->d_name;
		isEnable = 0;
		isEnable |= name[0] != '.';
		isEnable |= flags->a;
		isEnable |= flags->A && !(!_strcmp(name, ".") || !_strcmp(name, ".."));

		if (isEnable)
		{
			node = list_append(entry_list, DIR_ENTRY, entry);
			if (node)
			{
				node->parent = parent;
				node->name = name;
			}
		}

	}

}
