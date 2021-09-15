        global asm_strlen

asm_strlen:
        push RBP
        mov EAX, -1
        mov ecx, 0
loop:
        inc EAX
        mov CL, byte[RDI + RAX]
        jecxz finish
        jmp loop
finish:
        pop RBP
        ret
