#include "hls.h"
/**
 * hls - holberton clone os ls
 * @argv: list of arguments
 * Return: output of ls 0, 1, 2
 */
int hls(char *argv[])
{
	int *status = &globals()->status;
	linked_t *file_list = NULL;
	linked_t *dir_list = NULL;


	splitargv(&dir_list, &file_list, argv);
	print_content(dir_list, file_list);


	list_free(file_list);
	list_free(dir_list);
	return (*status);

}
