.data
i:
	.quad 1
.data
j:
	.quad 10
.text
.globl main
main:
############# preamble before function
pushq %rbp
movq %rsp, %rbp
subq $8, %rsp	#allocate local variables
pushq %rbx
pushq %r12
pushq %r13
pushq %r14
pushq %r15
####### body of function
MOV j, %r8
MOV %r8, i
MOV $3, %r8
MOV %r8, -8(%rbp)
MOV $4, %r8
MOV %r8, -8(%rbp)
.L1:
MOV -8(%rbp), %r8
MOV $0, %r9
CMP %r9, %r8
JG .L4
MOV $0, %r9
JMP .L3
.L4:
MOV $1, %r9
.L3:
CMP $0, %r9
JE .L2
MOV i, %r8
MOV %r8, %r10
ADD $1, %r8
MOV %r8, i
MOV -8(%rbp), %r8
MOV %r8, %r10
SUB $1, %r8
MOV %r8, -8(%rbp)
JMP .L1
.L2:
MOV i, %r8
MOVQ %r8, %rdi	 # first argument
MOVQ $0, %rax	 #there are zero floating point args
PUSHQ %r10
PUSHQ %r11
CALL print_integer
POPQ %r10
POPQ %r11
############# postamble after function
popq %r15
popq %r14
popq %r13
popq %r12
popq %rbx
movq %rbp, %rsp
popq %rbp
ret
