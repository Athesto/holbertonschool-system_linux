#include "hls.h"
#include <stdio.h>

int test_0(char **);

/**
 * main - holebrton ls implementation
 * @argc: counter
 * @argv: arguments of ls
 * Return: {1,2,3} = {ok,ERR1,ERR2}
 */
int main(int argc, char *argv[])
{
	int code = 0;

	code = test_0(argv);
	(void)argc;
	return (code);
}

/**
 * test_0 - progam
 * @argv: arguments
 * Return: statuscode
 */
int test_0(char **argv)
{
	int status = 0;
	flag_t myflags;
	pre_t pre = {0};
	int areArgs = 0;
	char buffer[1028];
	char *tmp;
	int args_counter = 0;
	char *single_argv[] = {
		"",
		".",
		NULL
	};
	int i_argv;
	char **tmp_argv;
	struct stat mystats = {0};
	int outcode = 0;

	for (i_argv = 1; argv[i_argv]; i_argv++)
	{
		if (argv[i_argv][0] != '-')
		{
			args_counter++;
			areArgs = 1;
		}
	}


	if (areArgs)
	{
		tmp_argv = argv;
	}
	else
	{
		tmp_argv = single_argv;
		tmp_argv[0] = argv[0];
	}


	myflags = get_flags(argv);

	for (i_argv = 1; tmp_argv[i_argv]; i_argv++)
	{
		tmp = tmp_argv[i_argv];
		if (tmp[0] != '-')
		{
			lstat(tmp, &mystats);
			switch (mystats.st_mode & S_IFMT)
			{
				case S_IFREG:
					if (myflags.l)
						long_format(pre, buffer, tmp);
					else
						_strcpy(buffer, tmp);
					printf("%s\n", buffer);
					break;

				default:
					status = get_pre(&pre, myflags, tmp);
					if (!status)
					{
						if (i_argv > 1)
							printf("\n");
						pre.argc = args_counter;
						get_array(pre, myflags, tmp);
						outcode = 0;
					}
					else
					{
						/* printf("%d, %d\n", status, ENOENT); */
						switch (status)
						{
							case EACCES:
								fprintf(stderr,
										"%s: cannot open directory %s: "\
										"Permission denied\n",
										argv[0],
										tmp);
								break;
							case ENOENT:
								fprintf(stderr,
										"%s: cannot access %s: " \
										"No such file or directoy\n",
										argv[0],
										tmp);
								break;
						}
						outcode = 2;
					}
			}
		}
	}
	return (outcode);

}
