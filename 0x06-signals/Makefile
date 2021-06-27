CC=gcc
CFLAGS=-Wall -Wextra -Werror -pedantic -g -std=gnu90
SRC=


%:
	@rm -rf a.out
	$(CC) $(CFLAGS) $(SRC)
	@betty-style $(SRC)
	@betty-doc $(SRC) 1>/dev/null
	valgrind -q ./a.out

0: SRC=$@-*.c tests/$@-main*.c
1: SRC=$@-*.c tests/$@-main*.c tests/more-fun.c

