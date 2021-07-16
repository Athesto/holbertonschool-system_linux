#include "hls.h"
void print_content_dir(linked_t *entry_list);
void get_content_dir(DIR *dir, linked_t **entry_list);

/**
 * print_content - print content of lists
 * @dir_list: list of directories
 * @file_list: list of files
 */
void print_content(linked_t *dir_list, linked_t *file_list)
{
	int file_counter;
	int dir_counter;
	linked_t *runner;
	linked_t *entry_list = NULL;
	DIR *dir;

	file_counter = 0;
	for (runner = file_list; runner; runner = runner->next, file_counter++)
	{
		if (file_counter)
			printf(" ");
		printf("%s", runner->name);
	}

	if (file_counter)
		printf("\n");

	dir_counter = 0;
	for (runner = dir_list; runner; runner = runner->next, dir_counter++)
	{
		dir = opendir(runner->name);
		if (!dir)
		{
			_perror(runner->name);
			continue;
		}
		get_content_dir(dir, &entry_list);
		print_content_dir(entry_list);

		if (file_counter || dir_counter)
			printf("\n");
		if (file_counter || !(dir_list && !dir_list->next))
			printf("%s:\n", runner->name);
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
	linked_t *runner;

	counter = 0;
	for (runner = entry_list; runner; runner = runner->next, counter++)
	{
		if (counter)
			printf(" ");
		printf("%s", runner->entry->d_name);

	}
	if (counter)
		printf("\n");
}
/**
 * get_content_dir - get a list of entry elements
 * @dir: directory of entries
 * @entry_list: entry
 */
void get_content_dir(DIR *dir, linked_t **entry_list)
{
	flag_t *flags = &globals()->flags;
	struct dirent *entry;
	char *name;
	int condition = 0;
	int counter;

	for (counter = 0; (entry = readdir(dir)) != NULL; counter++)
	{
		name = entry->d_name;
		condition = 0;
		condition |= name[0] != '.';
		condition |= flags->a;
		condition |= flags->A && !(!strcmp(name, ".") || !strcmp(name, ".."));

		if (condition)
			list_append(entry_list, DIR_ENTRY, entry);

	}

}
