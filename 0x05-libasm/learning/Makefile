ARG=""
#as
3a 4c:
	@rm -rf a.out
	as -g $@-*.s -o a.o
	ld a.o -o a.out
	@echo
	./a.out; echo "$$?"
	@rm a.o

#nasm
3b 3c 3d 4a 4b 4d:
	@rm -rf a.out
	nasm -g -f elf64 $@-*.asm -o a.o
	ld a.o -o a.out
	@echo
	./a.out; echo "$$?"
	@rm a.o

#gcc
%:
	@rm -rf a.out
	nasm -f elf64 $@-*.asm -o a.o
	gcc -ggdb tests/$@-main*.c a.o
	@echo 
	./a.out $(ARGS)
	@rm a.o

1 0: ARGS=10 20

