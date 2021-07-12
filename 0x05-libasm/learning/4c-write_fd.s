.data
msg:
	.ascii "Hello world\n"

.text

.globl _start

_start:
	movl $4, %eax           # syscall write(fd, msg, len)
	movl $2, %ebx           # file descriptior
	movl $msg, %ecx         # msg
	movl $12, %edx          # len
	int $0x80               # call systemcall write
	movl $1, %eax           # code exit
	sysenter                # call exit
