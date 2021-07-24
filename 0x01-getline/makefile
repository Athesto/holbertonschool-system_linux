CC=gcc
CFLAGS=-Wall -Wextra -Werror -g -pedantic
SRC=""
TEST_FILE=$*

%:
	rm -rf a.out
	$(CC) $(CFLAGS) $(SRC)
	@betty-doc *.c *.h 1>/dev/null
	@betty-style *.c *.h
	valgrind -q ./a.out
	@echo "--test--"
	@./a.out | diff -y - mains/results/$(TEST_FILE)-main && echo "\033[32mtest passed\033[0m" || echo "\033[31m failed\033[0m"
	@echo "--endtest--"


0: SRC=laps.c mains/$*-main.c
1: SRC=_getline.c mains/$*-main.c
1a: SRC=_getline.c mains/1-main.c

