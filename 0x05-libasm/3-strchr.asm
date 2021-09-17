        global asm_strchr
asm_strchr:
        push RBP
        mov RAX, 0                ; output string
        mov RCX, 0                ; searching char
        mov R8, 0                 ; dereference input string

        mov RAX, RDI              ; initialize
        mov CL, SIL

loop:
        cmp byte [RAX], CL
        je finish
        cmp byte [RAX], 0
        je ret_zero
        inc RAX
        jmp loop

ret_zero:
        mov RAX, 0
        jmp finish

finish:
        pop RBP
        ret
