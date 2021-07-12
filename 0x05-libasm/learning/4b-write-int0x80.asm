; call write function with int0x80 and eax=4 ebx=fd ecx=msg edx=len
        global _start

        section .text
_start:
        mov eax, 4                ; load syscall-code=write(4?)
        mov ebx, 2                ; load fd=2
        mov ecx, msg              ; load pointer to msg
        mov edx, len              ; load len=($ - msg)
        int 0x80                  ; call write(fd, msg, len)
        mov eax, 1                ; load syscall-code=exit(1?)
        mov ebx, '@'              ; load status=64
        int 0x80                  ; call exit(status)

        section .data
msg:
        db "hello world", 0xA
        len equ $ - msg
