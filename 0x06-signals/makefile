CC=gcc
CFLAGS=-g -Wall -Wextra -Werror -pedantic -std=gnu90
SRC=$*-*.c tests/$*-main.c

%:
	@rm -rf a.out
	$(CC) $(CFLAGS) $(SRC)

5: SRC=$*-*.c
