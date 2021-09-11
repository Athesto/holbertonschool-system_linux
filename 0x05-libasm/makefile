%:
	@rm -rf *.o *.out
	nasm -g -felf64 $*-*.asm -o a.o
	gcc -g a.o tests/$*-*.c
