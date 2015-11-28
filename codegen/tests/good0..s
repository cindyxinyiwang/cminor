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
pushq %rdi
pushq %rsi
subq %rbp	#allocate local variables
pushq %rbx
pushq %r12
pushq %r13
pushq %r14
pushq %r15
####### body of function
MOV -16(%rbp), %rax
MOV %rax, -8(%rbp)
MOV $12, %rax
MOV %rax, -24(rbp)
############# postamble after function
popq %r15
popq %r14
popq %r13
popq %r12
popq %rbx
movq %rbp, %rsp
popq %rvp
ret
