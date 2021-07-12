        global swap

swap:
        mov eax, dword [rsi]
        mov ebx, dword [rdi]
        mov [rsi], ebx
        mov [rdi], eax
        ret
