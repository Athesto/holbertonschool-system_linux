        global asm_strcmp

asm_strcmp:
        push RBP
        mov RAX, 0                ; char of string1
        mov RBX, 0                ; char of string2
        mov RDX, 0                ; counter of stings

loop:
        mov AL, [RDI + RDX]
        mov BL, [RSI + RDX]
        inc RDX
        cmp AL, BL
        jb ret_minus1
        ja ret_plus1
        cmp AL, 0
        jz ret_zero
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
