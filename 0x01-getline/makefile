CC=gcc
CFLAGS=-Wall -Wextra -Werror -g -pedantic
SRC=""

%:
	rm -rf a.out
	$(CC) $(CFLAGS) $(SRC)
	valgrind -q ./a.out

0: SRC=laps.c mains/$*-main.c

