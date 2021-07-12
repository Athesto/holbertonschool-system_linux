        .text

        .globl _start #the start is necesary

        #to run a program it has to set variables
_start:
        movl $1, %eax
        movl $99, %ebx
        int $0x80

