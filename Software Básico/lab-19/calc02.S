.data

.globl str
str: .string "Soma: %ld\n"

.text

.globl calc
calc:
	pushq %rbp
	movq  %rsp, %rbp
	subq $64, %rsp
	
	# # Salvando os registradores callee-saved %r15 e %r14
	movq %r15, -48(%rbp)
	movq %r14, -56(%rbp)
	
	# # int i = 0; é %r14d
	movl $0, %r14d
	
	# # int j = 4; é %r15d
	movl $4, %r15d
	
	# # int sum; é -4(%rbp)
	# # int vet1[5]; começa em -24(%rbp)
	# # short vet2[5]; começa em -34(%rbp)
	
	# # filli(vet1, 5, i);
	leaq -24(%rbp), %rdi
	movl $5, %esi
	movl %r14d, %edx
	
	call filli
	
	# # fills(vet2, 5, j);
	leaq -34(%rbp), %rdi
	movl $5, %esi
	movl %r15d, %edx
	
	call fills
	
	# # sum = 0;
	movl $0, -4(%rbp)

	# # for ( ; i < 5; i++, j--)
BlocoFor:
	# # i < 5 = !(i >= 5)
	cmpl $5, %r14d
	jge DepoisFor
	
	# # sum += vet1[i] + vet2[j];
	
	# # Usaremos %eax como auxiliar para a soma
	movl -4(%rbp), %eax # # sum
	
	# # Passando vet1 para o registrador auxiliar caller-saved %r10
	leaq -24(%rbp), %r10
	
	# # Passando i para o registrador auxiliar caller-saved %r11
	movslq %r14d, %r11
	
	# # Somando vet1[i] a sum (%eax)
	addl (%r10, %r11, 4), %eax # # sum + vet1[i]
	
	
	# # Passando vet2 para o registrador auxiliar caller-saved %r10
	leaq -34(%rbp), %r10
	
	# # Passando j para o registrador auxilia caller-saved %r11
	movslq %r15d, %r11
	
	# # Somando vet2[j] a sum (%eax)
	
	# # Passando vet2[j] extendido para um auxiliar %r9d
	movswl (%r10, %r11, 2), %r9d
	addl %r9d, %eax # # sum + vet1[i] + vet2[j]
	
	
	# # Passando o resultado da soma para a variável local sum -4(%rbp)
	movl %eax, -4(%rbp)
	
	# # i++
	addl $1, %r14d
	
	# # j--
	subl $1, %r15d
	
	jmp BlocoFor
	
DepoisFor:
	
	# # colocando sum em %eax para retorná-lo
	movl -4(%rbp), %eax
	
	# # Recuperando os registradores callee-saved %r15, e %r14
	movq -48(%rbp), %r15
	movq -56(%rbp), %r14
	
	leave
	ret
