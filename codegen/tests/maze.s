.text
.globl main
main:
############# preamble before function
pushq %rbp
movq %rsp, %rbp
subq $32, %rsp	#allocate local variables
pushq %rbx
pushq %r12
pushq %r13
pushq %r14
pushq %r15
####### body of function
MOV $20, %r8
MOV %r8, -8(%rbp)
MOV $20, %r8
MOV %r8, -16(%rbp)
PUSHQ %r10	#saves caller-saved registers
PUSHQ %r11
PUSHQ %r10	#saves caller-saved registers
PUSHQ %r11
MOV $0, %r8
MOV %r8, %rdi
CALL time
POPQ %r11
POPQ %r10
MOV %rax, %r10
MOV %r10, %rdi
CALL srand
POPQ %r11
POPQ %r10
MOV %rax, %r10
MOV $0, %r8
MOV %r8, -32(%rbp)
.L1:
MOV -32(%rbp), %r8
MOV -16(%rbp), %r9
CMP %r9, %r8
JL .L4
MOV $0, %r9
JMP .L3
.L4:
MOV $1, %r9
.L3:
CMP $0,%r9
JE .L2
MOV $0, %r8
MOV %r8, -24(%rbp)
.L5:
MOV -24(%rbp), %r8
MOV -8(%rbp), %r10
CMP %r10, %r8
JL .L8
MOV $0, %r10
JMP .L7
.L8:
MOV $1, %r10
.L7:
CMP $0,%r10
JE .L6
PUSHQ %r10	#saves caller-saved registers
PUSHQ %r11
CALL rand
POPQ %r11
POPQ %r10
MOV %rax, %r11
MOV $2, %r8
MOV $0, %rdx
MOV %r11, %rax
MOV %r8, %rbx
div %rbx
MOV %rdx, %r8
MOV $1, %r11
CMP %r11, %r8
JE .L10
MOV $0, %r11
JMP .L9
.L10:
MOV $1, %r11
.L9:
CMP $0, %r11
JE .L11
MOV $47, %r8
MOVQ %r8, %rdi	 # first argument
MOVQ $0, %rax	 #there are zero floating point args
PUSHQ %r10
PUSHQ %r11
CALL print_character
POPQ %r10
POPQ %r11
JMP .L12
.L11:
MOV $92, %r8
MOVQ %r8, %rdi	 # first argument
MOVQ $0, %rax	 #there are zero floating point args
PUSHQ %r10
PUSHQ %r11
CALL print_character
POPQ %r10
POPQ %r11
.L12:
MOV -24(%rbp), %r8
MOV %r8, %r12
ADD $1, %r8
MOV %r8, -24(%rbp)
JMP .L5
.L6:
MOV $.LS0, %r8
MOV %r8, %rdi	 # first argument
MOVQ $0, %rax	 #there are zero floating point args
PUSHQ %r10
PUSHQ %r11
CALL print_string
POPQ %r10
POPQ %r11
MOV -32(%rbp), %r8
MOV %r8, %r13
ADD $1, %r8
MOV %r8, -32(%rbp)
JMP .L1
.L2:
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
.string "\n"
