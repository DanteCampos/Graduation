.section .rodata

	str1: .asciz "Hello"

	str3: .asciz "Retorno: %d\n"

.data

	# # int retorno = 0;
	.globl retorno
	.align 4
	retorno: .long 0

.text

.globl main

main:

	pushq %rbp
	movq  %rsp, %rbp
	
	# # show("Hello", 123, &retorno);
	movq $str1, %rdi
	movq $123, %rsi
	movq $retorno, %rdx
	call show
	
	# # printf("Retorno: %d\n", retorno);
	movq $str3, %rdi
	movl retorno, %esi
	call printf
	
	# return 0 (?)
	movl $0, %eax
	
	leave
	ret
