.text
.globl main
main:
############# preamble before function
pushq %rbp
movq %rsp, %rbp
subq $0, %rsp	#allocate local variables
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
MOV $.LS1, %r8
MOV %r8, %rdi	 # first argument
MOVQ $0, %rax	 #there are zero floating point args
PUSHQ %r10
PUSHQ %r11
CALL print_string
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
.data
.LS0:
.string "hello"
.LS1:
.string "world\n"
