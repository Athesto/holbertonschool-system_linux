CC=gcc
CFLAGS=-g -Wall -Werror -Wextra -pedantic 
SRC=*.c
DST=hls
ARG=

build:
	@rm -f hls
	$(CC) $(CFLAGS) $(SRC) -o $(DST)
	@betty-style *.c *.h
	@betty-doc *.c *.h 1>/dev/null
	@#./hls $(ARG)

