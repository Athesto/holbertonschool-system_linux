        global asm_putc

asm_putc:
        push RBP                  ; save Base pointer
        mov RBP, RSP              ; save Stack pointer

        mov byte [RSP], DIL       ; load input
write:
        mov RAX, 1                ; syscall of write
        mov RDI, 1                ; stdout
        mov RSI, RSP              ; element
        mov RDX, 1                ; count
        syscall

        mov RSP, RBP              ; restore previous Stack pointer
        pop RBP                   ; restore previous Base pointer
        ret
