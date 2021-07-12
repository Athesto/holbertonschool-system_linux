;filetype nasm
section .text

global _start

_start:
	mov eax, 0x1
	mov ebx, '@'
	int 0x80

