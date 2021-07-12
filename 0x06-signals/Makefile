CC=gcc
CFLAGS=-Wall -Wextra -Werror -pedantic -g -std=gnu90
SRC=
ARGS=
EXTRA=


%:
	@rm -rf a.out
	$(CC) $(CFLAGS) $(SRC)
	@betty-style $(SRC)
	@betty-doc $(SRC) 1>/dev/null
	valgrind -q ./a.out $(ARGS)
	$(EXTRA)

# SRC
0 2 4 10 100 101 102: SRC=$@-*.c tests/$@-main*.c
1 3: SRC=$@-*.c tests/$@-main*.c tests/more-fun.c
5 6 7: SRC=$@-*.c
103: SRC=$@-*.c tests/$@-main*.c 102-*.c
104: SRC=$@-*.c tests/$@-main*.c 102-*.c 103-*.c

7b: SRC=tests/7-*.c
8b: SRC=tests/8-*.c

# ARGS
5: ARGS=10
10: ARGS=1

#EXTRA
5: EXTRA=eval i=0; while [ $$i -le 31 ]; do ./a.out $$i; i=$$(( i + 1 )); done

8:
	./$@-*.sh

9:
	sh tests/9-*.sh

