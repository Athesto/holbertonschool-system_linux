CC=gcc
CFLAGS=-Wall -Wextra -Werror -g -pedantic
SRC=""

%:
	rm -rf a.out
	$(CC) $(CFLAGS) $(SRC)
	valgrind -q ./a.out
	@echo "--test--"
	@./a.out | diff -u - mains/results/$*-main && echo "\033[32mtest passed\033[0m" || echo "\033[31m failed\033[0m"
	@echo "--endtest--"
	@betty-doc *.c *.h 1>/dev/null
	@betty-style *.c *.h


0: SRC=laps.c mains/$*-main.c
1: SRC=_getline.c mains/$*-main.c

