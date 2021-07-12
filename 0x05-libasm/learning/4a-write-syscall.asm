; call write function with syscall and eax=1 edi=fd esi=msg edx=len
        global _start

        section .text
_start:
        mov eax, 1                ; load syscall-code=write(1)
        mov edi, 2                ; load fd=2
        mov esi, msg              ; load pointer to msg
        mov edx, len              ; load len=($ - msg)
        syscall                   ; call write(fd, msg, len)
        mov eax, 60               ; load syscall-code=exit(60)
        mov edi, '@'              ; load status=64
        syscall                   ; call exit(status)

        section data
msg:
        db "hola my amigo", 0xA
        len equ $ - msg
