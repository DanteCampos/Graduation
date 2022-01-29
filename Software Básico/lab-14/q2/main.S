.section .rodata

	str1: .asciz "%d\n"

.data
	
	# # int i = 0;
	.globl i
	.align 4
	i: .long 0
	
	# # unsigned char vet[LEN] = {12,3,20,8};
	.globl vet
	vet: .byte 12, 3, 20, 8
	
.text

.globl main
main:

	pushq %rbp
	movq  %rsp, %rbp

# # for ( ; i < LEN; i++) 
Loop1:
	
	# # i < LEN = !(i >= LEN)
	movl i, %eax
	cmpl $4, %eax
	jge DepoisLoop1
	
	# # filtro(vet[i], LIM)
	movq $vet, %rax
	movslq i, %rdi
	addq %rdi, %rax
	movb (%rax), %dil
	
	movq $10, %rsi
	call filtro
	
	# # printf("%d\n", filtro(vet[i], LIM));
	movq $str1, %rdi
	movl %eax, %esi
	call printf
	
	# # i++
	movl i, %eax
	incl %eax
	movl %eax, i
	
	jmp Loop1
	
DepoisLoop1:
	
	# return 0 (?)
	movl $0, %eax
	
	leave
	ret
