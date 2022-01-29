.section .rodata
	str: .asciz "sum: %ld\n"

.globl sum
sum:
	pushq %rbp
	movq  %rsp, %rbp
	subq $32, %rsp # # Precisa salvar 4 registradores
	
	# # node_t *node = %rdi
	
	# # int i = %r11d (caller-saved)
	# # long s = %r10 (caller-saved)
	
	# # int i = 0;
	movl $0, %r11d
	
	# # long s = 0;
	movq $0, %r10
	
	# # while (i < node->used)
BlocoWhile:
	# # Movendo node->used (node + 48) para o %r9d (caller-saved)
	movl 48(%rdi), %r9d
	# # (i < node->used) = !(i >= node->used)
	cmpl %r9d, %r11d
	jge DepoisWhile
	
	# # s += getvalue (node, i++)
	
	# # Salvando os registradores caller-saved pra chamar a função
	movq %r11, -8(%rbp)
	movq %r10, -16(%rbp)
	movq %rsi, -24(%rbp)
	movq %rdi, -32(%rbp)
	
	# # Passando os parâmetros
	
	# # node = %rdi (já está aqui)
	# # i = %esi tem que passar de %r11d pra ele
	movl %r11d, %esi
	
	call getvalue
	
	# # Recuperando os registradores caller saved
	
	movq -8(%rbp), %r11
	movq -16(%rbp), %r10
	movq -24(%rbp), %rsi
	movq -32(%rbp), %rdi
	
	# # Somando o resultado (%rax) a s (%r10)
	addq %rax, %r10
	
	# # i++
	incl %r11d
	
	jmp BlocoWhile
DepoisWhile:
	
	# # return s
	movq %r10, %rax
	
	leave
	ret
