        global asm_memcpy
asm_memcpy:
        push RBP
        mov RAX, 0                ; dest
        mov RBX, 0                ; src
        mov RCX, 0                ; count
        mov R8, 0                 ; tmp
        mov R9, 0                 ; s
        mov R10, 0                ; carry

        mov RAX, RDI
        mov RBX, RSI
        mov ECX, EDX
        mov R8, RAX               ; tmp = dest
        mov R9, RBX               ; s = src

loop:
        cmp RCX, 0
        pushf
        dec RCX
        popf
        je finish_memcpy
        mov R10B, byte [R9]
        mov byte [R8], R10B
        inc R8
        inc R9
        jmp loop

finish_memcpy:
        pop RBP
        ret
