CC=gcc
CFLAGS=-Wall -Wextra -Werror -pedantic -g -std=gnu90
SRC=


%:
	@rm -rf a.out
	$(CC) $(CFLAGS) $(SRC)
	valgrind -q ./a.out
	@betty-style $(SRC)
	@betty-docs $(SRC) 1>/dev/null

0: SRC=$@*.c tests/$@-main*.c

