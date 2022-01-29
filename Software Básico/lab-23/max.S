.section .rodata
	.align 8
	constante: .double 0.0

.data

.text

.globl max_prod
max_prod:

	pushq %rbp
	movq  %rsp, %rbp
	subq $32, %rsp # # Precisa salvar 2 variáveis locais e o parâmetro
	
	# # Parâmetros recebidos
	# # produto_t *ptr = %rdi
	
	# # Salvando o parâmetro na pilha
	movq %rdi, -8(%rbp)
	
	# # Variáveis locais que serão utilizadas:
	# # double m = -16(%rbp)
	# # tmp = -24(%rbp)
	
	# # double m = 0.0;
	movsd constante, %xmm0 # # Auxiliar
	movsd %xmm0, -16(%rbp)
	
	# # While (ptr->id)
BlocoWhile:
	# # Passando ptr para o auxiliar caller-saved %rax
	movq -8(%rbp), %rax
	
	# # int id está no início da estrutura, ou seja, é (%rax)
	# # Salvando ptr->id no auxiliar caller saved %r8d
	movl (%rax), %r8d # # ptr->id
	
	# # (ptr->id) = (ptr->id != 0) = !(ptr->id = 0)
	cmpl $0, %r8d
	je DepoisWhile
	
	# # double tmp = floor (ptr->value);
	# # Passando o parâmetro double ptr->value = 8(%rax) = %xmm0
	movsd 8(%rax), %xmm0
	
	call floor
	
	# # Retorno está em %xmm0, passamos para tmp = -24(%rbp)
	movsd %xmm0, -24(%rbp)
	
	# # if (m < tmp)
	# # tmp já está em %xmm0
	# # Passamos m = -16(rbp) para %xmm1
	movsd -16(%rbp), %xmm1
	
	# # (m < tmp) = !(m >= tmp)
	ucomisd %xmm0, %xmm1
	jae EndIf
	
	# # m = tmp;
	# # tmp está em %xmm0
	movsd %xmm0, -16(%rbp)

EndIf:
	
	# # ptr++;
	# # ptr soma sizeof(produto_t) = (sizeof(int) + 4 + sizeof(double)) = 16
	# # Fazemos a conta com o auxiliar caller-saved %rax
	movq -8(%rbp), %rax
	addq $16, %rax
	movq %rax, -8(%rbp)
	
	jmp BlocoWhile
	
DepoisWhile:
	
	# # return m;
	movsd -16(%rbp), %xmm0
	
	leave
	ret
