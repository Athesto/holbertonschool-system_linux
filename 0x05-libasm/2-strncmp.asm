        global asm_strncmp

asm_strncmp:
        push RBP
        mov RAX, 0                ; char of string1
        mov RBX, 0                ; char of string2
        mov RCX, 0                ; counter of string

loop:
        cmp EDX, 0
        jz ret_zero
        mov AL, [RDI + RCX]
        mov BL, [RSI + RCX]
        inc RCX
        cmp AL, BL
        jb ret_minus1
        ja ret_plus1
        cmp AL, 0
        jz ret_zero
        dec EDX
        jmp loop

ret_plus1:
        mov EAX, 1
        jmp finish

ret_zero:
        mov EAX, 0
        jmp finish

ret_minus1:
        mov EAX, -1
        jmp finish

finish:
        pop RBP
        ret
