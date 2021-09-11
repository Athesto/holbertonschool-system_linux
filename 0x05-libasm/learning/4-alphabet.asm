        global print_alphabet

        section .text
print_alphabet:
        push RSP
        push RBP
        mov RAX, 1                ; write syscall
        mov RDI, 1                ; fd 1 stdout
        mov byte [RSP], 'a' - 1
        mov RSI, RSP              ; msg
        mov RDX, 1                ; message size
loop:
        inc byte [RSP]
        syscall                   ; syscall write
        cmp byte [RSP], 'z'
        jnz loop
        pop RBP
        pop RSP
        ret

