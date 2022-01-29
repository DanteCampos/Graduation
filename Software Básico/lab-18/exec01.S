.section .rodata
	str01: .asciz "Diferença em %d/%d: %ld\n"
.data
	.align 8
	prods:	.byte 0 # # mes +0
			.zero 7 # # padding
			.quad 0 # # preco +8
			.long 0 # # ano +16
			.zero 4 # # padding
			
			# #	tamanho da estrutura = 24 bytes
			
			.byte 0 # # mes +0
			.zero 7 # # padding
			.quad 0 # # preco +8
			.long 0 # # ano +16
			.zero 4 # # padding

media:
	pushq %rbp
	movq  %rsp, %rbp
	
	
	# # Parâmetros
	# # Produto *ptr = %rdi
	# # long size = %rsi

	# # i = %r10d (caller-saved)
	# # int i = 0;
	movl $0, %r10d
	
	# # soma = %r11 (caller-saved)
	# # long soma = 0;
	movq $0, %r11
	
	
	# # for (i=0; i<size; i++)
	movl $0, %r10d
	
BlocoFor:
	# # (i < size) = !(i >= size)
	# # Passando i para um registrador quad auxiliar (%r9 é caller-saved)
	movslq %r10d, %r9
	cmpq %rsi, %r9
	jge DepoisFor
	
	# # soma += ptr[i].preco;
	
	# # jogaremos o endereço de ptr[i].preco para o nosso registrador auxiliar caller-saved %r9
	movslq %r10d, %r9 # # i
	imulq $24, %r9 # # i * sizeof(struct Produto) = [i]
	addq $8, %r9 # # i * sizeof(struct Produto) + 8 = [i].preco
	addq %rdi, %r9 # # i * sizeof(struct Produto) + 8 + ptr = ptr[i].preco
	
	# # Passando o conteúdo do %r9 para outro registrador auxiliar caller-saved (%r8)
	movq (%r9), %r8
	
	# # Somando soma +=ptr[i].preco
	addq %r8, %r11
	
	
	# # i++
	incl %r10d
	jmp BlocoFor
	
DepoisFor:
	
	# # return soma/size;
	
	# # Passando o divisor (%rsi) para %rcx
	movq %rsi, %rcx
	
	# # Passando o dividendo (%r11) para %rax
	movq %r11, %rax
	
	cqto
	idivq %rcx
	
	# # O resultado está em %rax já, agora é só retornar
	
	leave
	ret

.globl main
main:

	pushq %rbp
	movq  %rsp, %rbp

	# # Salvando as callee-saved que vamos usara no código
	# # Alocamos 32 bytes
	subq $32, %rsp
	
	movq %r12, -0(%rbp)
	movq %r13, -8(%rbp)
	movq %r14, -16(%rbp)
	movq %r15, -24(%rbp)
	
	
	# # i = %r13d
	# # int i = 0
	movl $0, %r13d
	
	# # Salvamos o endereço de prods em %r12 (callee-saved) para usá-lo
	movq $prods, %r12
	
	# # Iremos usar %r14 (callee-saved) como auxiliar
	movq $0, %r14
	imulq $24, %r14
	
	# # prods[0].mes   = JAN;
	movb $1, (%r12, %r14)
	
	# # prods[0].preco = 100;
	movq $100, 8(%r12, %r14)
	
	# # prods[0].ano   = 2020;
	movl $2020, 16(%r12, %r14)
	
	movq $1, %r14
	imulq $24, %r14
	
	# # prods[1].mes   = FEV;
	movb $2, (%r12, %r14)
	
	# # prods[1].preco = 120;
	movq $120, 8(%r12, %r14)
	
	# # prods[1].ano   = 2020;
	movl $2020, 16(%r12, %r14)
	
	
	# # m = %r15
	# # long m = media (prods, SIZE)
	
	# # Parâmetros: (não precisamos salvar porque não vamos usar esses registradores)
	# # prods = %rdi
	# # SIZE = %rsi
	
	movq $prods, %rdi
	movq $2, %rsi
	
	call media
	
	# # Passando o resultado (em %rax) para long m (%r15)
	movq %rax, %r15
	
# # while (i < SIZE) 
BlocoWhile:
	# # (i < SIZE) = !(i >= SIZE)
	cmpl $2, %r13d
	jge DepoisWhile
	
	# # printf("Diferença em %d/%d: %ld\n", (int)prods[i].mes, prods[i].ano, prods[i].preco - m);
	
	# # Parâmetros:
	# # str01 = %rdi
	# # (int)prod[i].mes = %esi
	# # prods[i].ano = %edx
	# # prods[i].preco - m = %rcx
	
	movq $str01, %rdi # # str01
	
	# # Usando %rax (caller saved) como auxiliar para acessar prod
	# # Usando %r11 (caller saved) como i * 24 bytes
	
	movq $prods, %rax
	movslq %r13d, %r11 # # i
	imulq $24, %r11 # # i * sizeof (struct Produto)
	
	
	movsbl 0(%rax, %r11), %esi # # (int)prod[i].mes
	movl 16(%rax, %r11), %edx # # prods[i].ano
	movq 8(%rax, %r11), %rcx # # prods[i].preco
	subq %r15, %rcx # # prods[i].preco - m
	
	# # printf exige que %eax esteja zerado
	movl $0, %eax
	
	call printf
	
	# # i++
	addl $1, %r13d
	
	jmp BlocoWhile
	
DepoisWhile:
	
	# # Recuperando as callee-saved que usamos na função
	
	movq -0(%rbp), %r12
	movq -8(%rbp), %r13
	movq -16(%rbp), %r14
	movq -24(%rbp), %r15
	
	movl $0, %eax
	leave
	ret
