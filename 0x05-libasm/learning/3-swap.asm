        global swap
swap:
        mov eax, DWORD[rdi]
        mov ecx, DWORD[rsi]
        mov DWORD[rsi], eax
        mov DWORD[rdi], ecx
        ret
