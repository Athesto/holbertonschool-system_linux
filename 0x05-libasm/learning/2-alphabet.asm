; print alphabet
        global print_alphabet

        section .text
print_alphabet:
        mov eax, '1'              ; syscode=wirte(1)
        mov edi, '1'              ; fd=1
        mov esi, msg              ; char = '@'
        mov edx, '1'              ; len = 1
        syscall
        ret

