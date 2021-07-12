CC=gcc
CFLAGS=-g -Wall -Wextra -Werror -pedantic -std=gnu90
SRC=*.c


0-hreadelf: SRC=0-*.c
0-hreadelf: OUT=$@
0-hreadelf: OUT=a.out
0-hreadelf:
	rm -rf $(OUT)
	$(CC) $(CFLAGS) $(SRC) -o $(OUT)
	./$(OUT) $(OUT)


1-hreadelf:
	touch 1-hreadelf

2-hreadelf:
	echo "jaja"

100-hreadelf:
	echo "jajaj"

