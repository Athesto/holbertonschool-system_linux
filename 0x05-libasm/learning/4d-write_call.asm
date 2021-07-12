        global main
        extern write
        section .text

main:
        mov rdi, msg
        call write
        ret

msg:
        db "hello"

