        global asm_strstr
asm_strstr:
        push RBP
        mov RAX, 0                ; s1
        mov RBX, 0                ; s2
        mov R8, 0                 ; l1
        mov R9, 0                 ; l2

        mov RAX, RDI
        mov RBX, RSI

; -----  R9 = strlen(RBX)
        mov R9, RBX
loop_len_searching_string:
        cmp byte [R9], 0
        je break_loop_len_searching_string
        inc R9
        jmp loop_len_searching_string

break_loop_len_searching_string:
        sub R9, RBX
; ----- end strlen

        cmp R9, 0
        je finish

; -----  R8 = strlen(RAX)
        mov R8, RAX
loop_len_output:
        cmp byte [R8], 0
        je break_loop_len_output
        inc R8
        jmp loop_len_output

break_loop_len_output:
        sub R8, RAX
; end len_output

loop_cmp_lens:
        cmp R8, R9                ; l1, l2
        jb ret_zero               ; l1 < l2 -> ret_zero
        dec r8
; ;R10 = memcmp(cs, ct, count)
        mov R11, R9               ; count = l2
        mov R12, 0                ; res
        mov R13, RAX              ; su1 = cs
        mov R14, RBX              ; su2 = ct
loop_memcmp:
        cmp R11, 0
        jl finish_memcmp          ; count < 0
        mov R12B, byte [R13]      ; res = *su1
        sub R12B, byte [R14]      ; res -= *su2
        cmp R12, 0
        jne finish_memcmp         ; res != 0 -> break

        inc R13                   ; ++su1
        inc R14                   ; ++su2
        dec R11                   ; count--
        jmp loop_memcmp

finish_memcmp:
        mov R10, R12              ; count = res
; ; end memcmp
        cmp R10, 0                ; R10 = memcmp(s1, s2, l2)
        je finish                 ; R10 == 0 -> finish
        inc RAX
        jmp loop_cmp_lens

ret_zero:
        mov RAX, 0
        jmp finish

finish:
        pop RBP
        ret
