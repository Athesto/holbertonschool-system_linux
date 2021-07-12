        global _start

        section .text
_start:
        mov rax, 1                     ; set systemcall exit
        mov rbx, '@'                   ; set output value '@' == 40h == 64d
        int 0x80                       ; interrupt program

