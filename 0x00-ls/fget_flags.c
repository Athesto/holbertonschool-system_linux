#include "hls.h"
/**
 * get_flags - get flags from argv
 * @argv: arguments
 * Return: myflags
 */
flag_t get_flags(char **argv)
{
	int i;
	char *all_flags;
	flag_t my_flags = {0};

	if (!argv || !*argv)
		return (my_flags);

	for (i = 0; argv[i]; i++)
		if (argv[i][0] == '-')
		{
			all_flags = argv[i];
			my_flags.a = my_flags.a || (_strchr(all_flags, 'a') != NULL);
			my_flags.A = my_flags.A || (_strchr(all_flags, 'A') != NULL);
			my_flags.l = my_flags.l || (_strchr(all_flags, 'l') != NULL);
			my_flags.r = my_flags.r || (_strchr(all_flags, 'r') != NULL);
			my_flags.S = my_flags.S || (_strchr(all_flags, 'S') != NULL);
			my_flags.t = my_flags.t || (_strchr(all_flags, 't') != NULL);
			my_flags.R = my_flags.R || (_strchr(all_flags, 'R') != NULL);
			my_flags.one = my_flags.one || (_strchr(all_flags, '1') != NULL);
		}

	return (my_flags);
}
