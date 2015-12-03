.text
.globl draw_box
draw_box:
############# preamble before function
pushq %rbp
movq %rsp, %rbp
pushq %rdi
pushq %rsi
pushq %rdx
subq $0, %rsp	#allocate local variables
pushq %rbx
pushq %r12
pushq %r13
pushq %r14
pushq %r15
####### body of function
PUSHQ %r10	#saves caller-saved registers
PUSHQ %r11
MOV $255, %r8
MOV %r8, %rdi
MOV $255, %r8
MOV %r8, %rdi
MOV $255, %r8
MOV %r8, %rdi
CALL gfx_color
POPQ %r11
POPQ %r10
MOV %rax, %r10
PUSHQ %r10	#saves caller-saved registers
PUSHQ %r11
MOV -8(%rbp), %r8
MOV %r8, %rdi
MOV -16(%rbp), %r8
MOV %r8, %rdi
MOV -8(%rbp), %r8
MOV -24(%rbp), %r9
ADD %r8, %r9
MOV %r9, %rdi
MOV -16(%rbp), %r8
MOV %r8, %rdi
CALL gfx_line
POPQ %r11
POPQ %r10
MOV %rax, %r10
PUSHQ %r10	#saves caller-saved registers
PUSHQ %r11
MOV -8(%rbp), %r8
MOV -24(%rbp), %r9
ADD %r8, %r9
MOV %r9, %rdi
MOV -16(%rbp), %r8
MOV %r8, %rdi
MOV -8(%rbp), %r8
MOV -24(%rbp), %r9
ADD %r8, %r9
MOV %r9, %rdi
MOV -16(%rbp), %r8
MOV -24(%rbp), %r9
ADD %r8, %r9
MOV %r9, %rdi
CALL gfx_line
POPQ %r11
POPQ %r10
MOV %rax, %r10
PUSHQ %r10	#saves caller-saved registers
PUSHQ %r11
MOV -8(%rbp), %r8
MOV -24(%rbp), %r9
ADD %r8, %r9
MOV %r9, %rdi
MOV -16(%rbp), %r8
MOV -24(%rbp), %r9
ADD %r8, %r9
MOV %r9, %rdi
MOV -8(%rbp), %r8
MOV %r8, %rdi
MOV -16(%rbp), %r8
MOV -24(%rbp), %r9
ADD %r8, %r9
MOV %r9, %rdi
CALL gfx_line
POPQ %r11
POPQ %r10
MOV %rax, %r10
PUSHQ %r10	#saves caller-saved registers
PUSHQ %r11
MOV -8(%rbp), %r8
MOV %r8, %rdi
MOV -16(%rbp), %r8
MOV -24(%rbp), %r9
ADD %r8, %r9
MOV %r9, %rdi
MOV -8(%rbp), %r8
MOV %r8, %rdi
MOV -16(%rbp), %r8
MOV %r8, %rdi
CALL gfx_line
POPQ %r11
POPQ %r10
MOV %rax, %r10
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
subq $72, %rsp	#allocate local variables
pushq %rbx
pushq %r12
pushq %r13
pushq %r14
pushq %r15
####### body of function
MOV $100, %r8
MOV %r8, -8(%rbp)
MOV $500, %r8
MOV %r8, -16(%rbp)
MOV $500, %r8
MOV %r8, -24(%rbp)
MOV -8(%rbp), %r8
MOV -16(%rbp), %r9
MOV %r8, %rax
IMUL %r9, %rax
MOV %rax, %r9
MOV $2, %r8
MOV %r9, %rax
CDQ
IDIV %r8, %rax
MOV %rax, %r8
MOV %r8, -32(%rbp)
MOV -8(%rbp), %r8
MOV -24(%rbp), %r9
MOV %r8, %rax
IMUL %r9, %rax
MOV %rax, %r9
MOV $2, %r8
MOV %r9, %rax
CDQ
IDIV %r8, %rax
MOV %rax, %r8
MOV %r8, -40(%rbp)
MOV -8(%rbp), %r8
MOV $3, %r9
MOV %r8, %rax
IMUL %r9, %rax
MOV %rax, %r9
MOV %r9, -48(%rbp)
MOV -8(%rbp), %r8
MOV $5, %r9
MOV $-5, %r9
MOV %r8, %rax
IMUL %r9, %rax
MOV %rax, %r9
MOV %r9, -56(%rbp)
MOV $100, %r8
MOV %r8, -64(%rbp)
PUSHQ %r10	#saves caller-saved registers
PUSHQ %r11
MOV -16(%rbp), %r8
MOV %r8, %rdi
MOV -24(%rbp), %r8
MOV %r8, %rdi
MOV $.LS0, %r8
MOV %r8, %rdi
CALL gfx_open
POPQ %r11
POPQ %r10
MOV %rax, %r10
.L1:
MOV $0, %r8
CMP $0, %r8
JE .L2
MOV $.LS1, %r8
MOV %r8, %rdi	 # first argument
MOVQ $0, %rax	 #there are zero floating point args
PUSHQ %r10
PUSHQ %r11
CALL print_string
POPQ %r10
POPQ %r11
MOV -32(%rbp), %r8
MOVQ %r8, %rdi	 # first argument
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
MOV -40(%rbp), %r8
MOVQ %r8, %rdi	 # first argument
MOVQ $0, %rax	 #there are zero floating point args
PUSHQ %r10
PUSHQ %r11
CALL print_integer
POPQ %r10
POPQ %r11
MOV $.LS3, %r8
MOV %r8, %rdi	 # first argument
MOVQ $0, %rax	 #there are zero floating point args
PUSHQ %r10
PUSHQ %r11
CALL print_string
POPQ %r10
POPQ %r11
MOV -48(%rbp), %r8
MOVQ %r8, %rdi	 # first argument
MOVQ $0, %rax	 #there are zero floating point args
PUSHQ %r10
PUSHQ %r11
CALL print_integer
POPQ %r10
POPQ %r11
MOV $.LS4, %r8
MOV %r8, %rdi	 # first argument
MOVQ $0, %rax	 #there are zero floating point args
PUSHQ %r10
PUSHQ %r11
CALL print_string
POPQ %r10
POPQ %r11
MOV -56(%rbp), %r8
MOVQ %r8, %rdi	 # first argument
MOVQ $0, %rax	 #there are zero floating point args
PUSHQ %r10
PUSHQ %r11
CALL print_integer
POPQ %r10
POPQ %r11
MOV $.LS5, %r8
MOV %r8, %rdi	 # first argument
MOVQ $0, %rax	 #there are zero floating point args
PUSHQ %r10
PUSHQ %r11
CALL print_string
POPQ %r10
POPQ %r11
PUSHQ %r10	#saves caller-saved registers
PUSHQ %r11
CALL gfx_event_waiting
POPQ %r11
POPQ %r10
MOV %rax, %r10
CMP $0, %r10
JE .L3
PUSHQ %r10	#saves caller-saved registers
PUSHQ %r11
CALL gfx_wait
POPQ %r11
POPQ %r10
MOV %rax, %r11
MOV %r11, -72(%rbp)
MOV -72(%rbp), %r8
MOV $113, %r9
CMP %r9, %r8
JE .L6
MOV $0, %r9
JMP .L5
.L6:
MOV $1, %r9
.L5:
CMP $0, %r9
JE .L7
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
JMP .L8
.L7:
.L8:
PUSHQ %r10	#saves caller-saved registers
PUSHQ %r11
CALL gfx_xpos
POPQ %r11
POPQ %r10
MOV %rax, %r11
MOV -8(%rbp), %r8
MOV %r11, %rax
IMUL %r8, %rax
MOV %rax, %r8
MOV %r8, -32(%rbp)
PUSHQ %r10	#saves caller-saved registers
PUSHQ %r11
CALL gfx_ypos
POPQ %r11
POPQ %r10
MOV %rax, %r11
MOV -8(%rbp), %r8
MOV %r11, %rax
IMUL %r8, %rax
MOV %rax, %r8
MOV %r8, -40(%rbp)
MOV $5, %r8
MOV -8(%rbp), %r11
MOV %r8, %rax
IMUL %r11, %rax
MOV %rax, %r11
MOV %r11, -48(%rbp)
JMP .L4
.L3:
.L4:
MOV -56(%rbp), %r8
MOV $1, %r11
MOV -8(%rbp), %r12
MOV %r11, %rax
IMUL %r12, %rax
MOV %rax, %r12
ADD %r8, %r12
MOV %r12, -56(%rbp)
MOV -32(%rbp), %r8
MOV $0, %r11
CMP %r11, %r8
JL .L10
MOV $0, %r11
JMP .L9
.L10:
MOV $1, %r11
.L9:
MOV -48(%rbp), %r8
MOV $0, %r12
CMP %r12, %r8
JL .L12
MOV $0, %r12
JMP .L11
.L12:
MOV $1, %r12
.L11:
AND %r11, %r12
CMP $0, %r12
JE .L13
MOV $9, %r8
MOV $-9, %r8
MOV -48(%rbp), %r11
MOV %r8, %rax
IMUL %r11, %rax
MOV %rax, %r11
MOV $10, %r8
MOV %r11, %rax
CDQ
IDIV %r8, %rax
MOV %rax, %r8
MOV %r8, -48(%rbp)
JMP .L14
.L13:
.L14:
MOV -32(%rbp), %r8
MOV -16(%rbp), %r11
MOV -8(%rbp), %r13
MOV %r11, %rax
IMUL %r13, %rax
MOV %rax, %r13
CMP %r13, %r8
JG .L16
MOV $0, %r13
JMP .L15
.L16:
MOV $1, %r13
.L15:
MOV -48(%rbp), %r8
MOV $0, %r11
CMP %r11, %r8
JG .L18
MOV $0, %r11
JMP .L17
.L18:
MOV $1, %r11
.L17:
AND %r13, %r11
CMP $0, %r11
JE .L19
MOV $9, %r8
MOV $-9, %r8
MOV -48(%rbp), %r13
MOV %r8, %rax
IMUL %r13, %rax
MOV %rax, %r13
MOV $10, %r8
MOV %r13, %rax
CDQ
IDIV %r8, %rax
MOV %rax, %r8
MOV %r8, -48(%rbp)
JMP .L20
.L19:
.L20:
MOV -40(%rbp), %r8
MOV -24(%rbp), %r13
MOV -8(%rbp), %r14
MOV %r13, %rax
IMUL %r14, %rax
MOV %rax, %r14
CMP %r14, %r8
JG .L22
MOV $0, %r14
JMP .L21
.L22:
MOV $1, %r14
.L21:
MOV -56(%rbp), %r8
MOV $0, %r13
CMP %r13, %r8
JG .L24
MOV $0, %r13
JMP .L23
.L24:
MOV $1, %r13
.L23:
AND %r14, %r13
CMP $0, %r13
JE .L25
MOV $9, %r8
MOV $-9, %r8
MOV -56(%rbp), %r14
MOV %r8, %rax
IMUL %r14, %rax
MOV %rax, %r14
MOV $10, %r8
MOV %r14, %rax
CDQ
IDIV %r8, %rax
MOV %rax, %r8
MOV %r8, -56(%rbp)
JMP .L26
.L25:
.L26:
MOV -32(%rbp), %r8
MOV -48(%rbp), %r14
MOV -64(%rbp), %r15
MOV %r14, %rax
IMUL %r15, %rax
MOV %rax, %r15
MOV -8(%rbp), %r14
MOV %r15, %rax
CDQ
IDIV %r14, %rax
MOV %rax, %r14
ADD %r8, %r14
MOV %r14, -32(%rbp)
MOV -40(%rbp), %r8
MOV -56(%rbp), %r14
MOV -64(%rbp), %r15
MOV %r14, %rax
IMUL %r15, %rax
MOV %rax, %r15
MOV -8(%rbp), %r14
MOV %r15, %rax
CDQ
IDIV %r14, %rax
MOV %rax, %r14
ADD %r8, %r14
MOV %r14, -40(%rbp)
PUSHQ %r10	#saves caller-saved registers
PUSHQ %r11
CALL gfx_clear
POPQ %r11
POPQ %r10
MOV %rax, %r14
PUSHQ %r10	#saves caller-saved registers
PUSHQ %r11
MOV -32(%rbp), %r8
MOV -8(%rbp), %r14
MOV %r8, %rax
CDQ
IDIV %r14, %rax
MOV %rax, %r14
MOV %r14, %rdi
MOV -40(%rbp), %r8
MOV -8(%rbp), %r14
MOV %r8, %rax
CDQ
IDIV %r14, %rax
MOV %rax, %r14
MOV %r14, %rdi
MOV $25, %r8
MOV %r8, %rdi
CALL draw_box
POPQ %r11
POPQ %r10
MOV %rax, %r14
PUSHQ %r10	#saves caller-saved registers
PUSHQ %r11
CALL gfx_flush
POPQ %r11
POPQ %r10
MOV %rax, %r14
PUSHQ %r10	#saves caller-saved registers
PUSHQ %r11
MOV -64(%rbp), %r8
MOV -8(%rbp), %r14
MOV %r8, %rax
IMUL %r14, %rax
MOV %rax, %r14
MOV %r14, %rdi
CALL usleep
POPQ %r11
POPQ %r10
MOV %rax, %r14
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
.string "Bounce!"
.LS1:
.string "x: "
.LS2:
.string " y: "
.LS3:
.string " vx: "
.LS4:
.string " vy: "
.LS5:
.string "\n"
