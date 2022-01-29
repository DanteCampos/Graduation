.section .rodata
	str01: .asciz "%d\n"

.data

	# # int vet[7] = {1,2,3,0,4,5,0};
	.globl vet
	.align 4
	vet: .long 1, 2, 3, 0, 4, 5, 0

.text

.globl main
main:

	pushq %rbp
	movq  %rsp, %rbp
	
	# # int i; será %ebx 
	
	movl $0, %ebx
BlocoFor:
	# # (i < 7) = !(i >= 7)
	cmpl $7, %ebx
	jge DepoisFor
	
	# # printf("%d\n", vet[i]);
	
	
	
	# # Colocando a str01 e o i nos registradores de passagem de parâmetro
	movq $str01, %rdi
	
	movslq %ebx, %rax
	movq $vet, %r13
	movl (%r13, %rax, 4), %esi
	
	# # Printf exige que %eax seja 0
	movl $0, %eax
	
	call printf
	
	# # i++;
	incl %ebx
	jmp BlocoFor
DepoisFor:
	
	
	movl $0, %eax
	leave
	ret
