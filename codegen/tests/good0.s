.text
.globl fib
fib:
############# preamble before function
pushq %rbp
movq %rsp, %rbp
pushq %rdi
subq $0, %rsp	#allocate local variables
pushq %rbx
pushq %r12
pushq %r13
pushq %r14
pushq %r15
####### body of function
MOV -8(%rbp), %r8
MOV $1, %r9
CMP %r9, %r8
JL .L2
MOV $0, %r9
JMP .L1
.L2:
MOV $1, %r9
.L1:
CMP $0, %r9
JE .L3
MOV $0, %r8
MOV %r8, %rax
############# call these before return
popq %r15
popq %r14
popq %r13
popq %r12
popq %rbx
movq %rbp, %rsp
popq %rbp
RET
JMP .L4
.L3:
MOV -8(%rbp), %r8
MOV $2, %r10
CMP %r10, %r8
JL .L6
MOV $0, %r10
JMP .L5
.L6:
MOV $1, %r10
.L5:
CMP $0, %r10
JE .L7
MOV $1, %r8
MOV %r8, %rax
############# call these before return
popq %r15
popq %r14
popq %r13
popq %r12
popq %rbx
movq %rbp, %rsp
popq %rbp
RET
JMP .L8
.L7:
PUSHQ %r10	#saves caller-saved registers
PUSHQ %r11
MOV -8(%rbp), %r8
MOV $1, %r11
SUB %r11, %r8
MOV %r8, %rdi
CALL fib
POPQ %r11
POPQ %r10
MOV %rax, %r11
PUSHQ %r10	#saves caller-saved registers
PUSHQ %r11
MOV -8(%rbp), %r8
MOV $2, %r12
SUB %r12, %r8
MOV %r8, %rdi
CALL fib
POPQ %r11
POPQ %r10
MOV %rax, %r12
ADD %r11, %r12
MOV %r12, %rax
############# call these before return
popq %r15
popq %r14
popq %r13
popq %r12
popq %rbx
movq %rbp, %rsp
popq %rbp
RET
.L8:
.L4:
############# postamble after function
popq %r15
popq %r14
popq %r13
popq %r12
popq %rbx
movq %rbp, %rsp
popq %rbp
ret
.text
.globl main
main:
############# preamble before function
pushq %rbp
movq %rsp, %rbp
pushq %rdi
pushq %rsi
subq $8, %rsp	#allocate local variables
pushq %rbx
pushq %r12
pushq %r13
pushq %r14
pushq %r15
####### body of function
MOV $.LS0, %r8
MOV %r8, %rdi	 # first argument
MOVQ $0, %rax	 #there are zero floating point args
PUSHQ %r10
PUSHQ %r11
CALL print_string
POPQ %r10
POPQ %r11
MOV $0, %r8
MOV %r8, -24(%rbp)
.L9:
MOV -24(%rbp), %r8
MOV $45, %r11
CMP %r11, %r8
JL .L12
MOV $0, %r11
JMP .L11
.L12:
MOV $1, %r11
.L11:
CMP $0,%r11
JE .L10
MOV -24(%rbp), %r8
MOVQ %r8, %rdi	 # first argument
MOVQ $0, %rax	 #there are zero floating point args
PUSHQ %r10
PUSHQ %r11
CALL print_integer
POPQ %r10
POPQ %r11
MOV $.LS1, %r8
MOV %r8, %rdi	 # first argument
MOVQ $0, %rax	 #there are zero floating point args
PUSHQ %r10
PUSHQ %r11
CALL print_string
POPQ %r10
POPQ %r11
PUSHQ %r10	#saves caller-saved registers
PUSHQ %r11
MOV -24(%rbp), %r8
MOV %r8, %rdi
CALL fib
POPQ %r11
POPQ %r10
MOV %rax, %r12
MOVQ %r12, %rdi	 # first argument
MOVQ $0, %rax	 #there are zero floating point args
PUSHQ %r10
PUSHQ %r11
CALL print_integer
POPQ %r10
POPQ %r11
MOV $.LS2, %r8
MOV %r8, %rdi	 # first argument
MOVQ $0, %rax	 #there are zero floating point args
PUSHQ %r10
PUSHQ %r11
CALL print_string
POPQ %r10
POPQ %r11
MOV -24(%rbp), %r8
MOV $1, %r12
ADD %r8, %r12
MOV %r12, -24(%rbp)
JMP .L9
.L10:
MOV $0, %r8
MOV %r8, %rax
############# call these before return
popq %r15
popq %r14
popq %r13
popq %r12
popq %rbx
movq %rbp, %rsp
popq %rbp
RET
############# postamble after function
popq %r15
popq %r14
popq %r13
popq %r12
popq %rbx
movq %rbp, %rsp
popq %rbp
ret
.data
.LS0:
.string "Table of Fibonnacci Numbers\n"
.LS1:
.string "\t"
.LS2:
.string "\n"
