        BITS 64

        global add_me

add_me:
        mov eax, edi              ; ACC = ARG1
        add eax, esi              ; ACC += ARG2
        ret                       ; return ACC

