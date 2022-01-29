.section .rodata



.data
	.globl v1
	.align 2
	v1: .word 1, 2
	
	.globl v2
	.align 8
	v2: .quad 1, 2, 3

.text

# # void aux(short *a1, int p1)
.globl aux
aux:
	pushq %rbp
	movq  %rsp, %rbp
	subq $32, %rsp
	
	# # Vamos precisar salvar 3 registradores, então reservamos 32 bytes de memória
	
	# # int i será o registrador caller saved %rcx
	
	# # i = 2
	movl $2, %ecx

BlocoFor
	# # (i >= 0) = !(i < 0)
	cmpl $0, %ecx
	jl DepoisFor
	
	# # Salvamos o i (%rcx) e o a1 (%rdi) e p1 (%esi) antes de chamar a função
	movq %rcx, -8(%rbp)
	movq %rdi, -16(%rbp)
	movq %rsi, -24(%rbp)
	
	# # Passando os parâmetros
	# # a1 = %rdi (já está no registrador)
	# # p1 = %esi (já está no registrador)
	# # v2 = %rdx (não precisa salvar, pois puxamos da memória só quando vamos passar como parâmetro)
	# # i =  %ecx (já está no registrador)
	
	# # Passamos v2 como parâmetro através de %rdx
	movq $v2, %rdx
	
	call sum
	
	# # Puxamos os registradores que salvamos de volta
	mov -8(%rbp), %rcx
	movq -16(%rbp), %rdi
	movq -24(%rbp), %rdi
	
	# # i--
	subl $1, %rcx
	
	jmp BlocoFor
	
DepoisFor:
	
	leave
	ret


.globl main
main:

	pushq %rbp
	movq  %rsp, %rbp
	
	# # Precisaremos salvar 1 registrador, portanto, alocaremos 16 bytes de memória
	subq $16, %rsp
	
	# # int i = 0; será o registrador caller saved %esi
	movl $0, %esi

# # while (i < 2)	
BlocoWhile:
	(i < 2) = !(i >= 2)
	cmpl $2, %esi
	jge DepoisWhile
	
	# # Salvamos somente i (%esi) antes de chamar a função
	movq %rsi, -8(%rbp)
	
	
	# # Passando os parâmetros:
	# # v1 = %rdi (não precisa salvar, pois puxamos da memória só quando vamos passar como parâmetro)
	# # i = %esi (já está no registrador)
	
	movq $v1, %rdi
	
	# # Chamamos a função
	call aux
	
	# # Puxamos i (%rsi) de volta
	movq -8(%rbp), %rsi
	
	# # i++;
	incl %esi
	
	jmp BlocoWhile
	
DepoisWhile:
	
	movl $0, %eax

	leave
	ret
