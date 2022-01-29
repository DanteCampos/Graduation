.section .rodata

.data

.text

.globl fat
fat:

	pushq %rbp
	movq  %rsp, %rbp
	
	# # Vamos precisar salvar 1 registrador, então alocaremos 16 bytes de espaço
	subq $16, %rsp
	
	
	# # n é passado pelo registrador %rdi
	# # if (n > 0) = !(n <= 0)
	cmpl $0, %edi
	jle DepoisIf
	
BlocoIf:
	# # return fat(n-1) * n;
	
	# # Salvamos n (%rdi) na pilha
	movq %rdi, -8(%rbp)
	
	# # Colocando passando n-1 como parâmetro para chamar fat(n-1)
	subl $1, %edi
	call fat
	
	# # Recuperamos n (%rdi)
	movq -8(%rbp), %rdi
	
	# # Multiplicamos fat(n-1)*n e colocamos o resultado em %eax
	imull %edi, %eax
	
	# # Retornamos o valor em %eax
	leave
	ret
	
DepoisIf:

	# # return 1;
	movl $1, %eax
	
	leave
	ret
