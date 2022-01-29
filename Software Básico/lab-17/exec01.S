.section .rodata
	str01: .asciz "color: %ld, filled: %d\n"
	
.data
	.globl c1
	.align 8
	c1: .long 0 # # x +0
		.long 0 # # y +4
		.byte 0 # # filled +8
		.zero 7 # # padding
		.quad 0 # # color +16
	
.text

.globl main
main:

	pushq %rbp
	movq  %rsp, %rbp
	
	# # Usando %rcx para referenciar a estrutura
	movq $c1, %rcx 
	
	# # c1.x = 10;
	movl $10, 0(%rcx)
	
	# # c1.y = 2 * c1.x;
	movl 0(%rcx), %edx # # c1.x
	imull $2, %edx # # 2 * c1.x
	movl %edx, 0(%rcx) # # c1.y = 2 * c1.x;
	
	# # c1.filled = 1;
	movb $1, 8(%rcx)
	
	# # if (c1.y > 30)
	# # (c1.y > 30) = !(c1.y <= 30)
	movl 4(%rcx), %edx # # c1.y
	cmpl $30, %edx
	jle BlocoElse
	
	# # c1.color = RED
	movq $2, 16(%rcx)
	
	jmp DepoisIf
	
BlocoElse:
	
	# # c1.color = BLUE
	movq $1, 16(%rcx)
	
DepoisIf:
	
	# # printf("color: %ld, filled: %d\n", c1.color, (int)c1.filled);
	# # printf precisa do %eax zerado
	movl $0, %eax
	
	# # Passando os parâmetros:
	# # str01 = %rdi
	# # c1.color = 16(%rcx) = %rsi
	# # (int) c1.filled = 8(%rcx) = %edx
	
	movq $str01, %rdi
	movq 16(%rcx), %rsi
	movsbl 8(%rcx), %edx
	
	call printf
	
	movl $0, %eax
	leave
	ret
