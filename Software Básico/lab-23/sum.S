.section .rodata
	str: .asciz "Soma %f maior que o limite %f\n"
	.align 8
	constante: .double 0.0


.data

.text

.globl sum
sum:

	pushq %rbp
	movq  %rsp, %rbp
	subq $80, %rsp # # Alocando 80 bytes pras variáveis locais e o parâmetro
	
	# # Parâmetros recebidos
	# # double limit = %xmm0
	
	# # Variáveis locais na pilha
	# # double s = -8(%rbp)
	# # double vd[4] = -40(%rbp)
	# # int vi[4] = -56(%rbp)
	# # int i = -60(%rbp)
	# # 4 bytes de padding = -64(%rbp)
	
	# # Salvando o parâmetros na pilha para chamá-lo na hora de usar e não ter problema com printf
	movsd %xmm0, -72(%rbp)
	
	# # Inicializando as variáveis locais:
	
	# # int i = 3;
	movl $3, -60(%rbp)
	
	# # double s = 0.0
	movsd constante, %xmm0
	movsd %xmm0, -8(%rbp)
	
	# # int vi[4] = {5,6,7,8};
	movl $5, -56(%rbp)
	movl $6, -52(%rbp)
	movl $7, -48(%rbp)
	movl $8, -44(%rbp)

	# # mult (vi, vd, i+1)
	# # Parâmetros para passar:
	# # vi = %rdi
	# # vd = %rsi
	# # i+1 = %edx
	
	leaq -56(%rbp), %rdi
	leaq -40(%rbp), %rsi
	movl -60(%rbp), %edx # # i
	addl $1, %edx # # i+1
	
	call mult
	
	# # while (i >= 0)
BlocoWhile:
	# # i será a variável auxiliar caller-saved %eax
	movl -60(%rbp), %eax
	
	# # (i >= 0) = !(i < 0)
	cmpl $0, %eax
	jl DepoisWhile
	
	# # s += vd[i--]
	# # s será o caller-saved %xmm0
	movsd -8(%rbp), %xmm0 # # s
	
	# # i está em %eax
	# # vd será o caller-saved %r8
	leaq -40(%rbp), %r8
	
	# # Salvamos o elemento acessado em %xmm1
	# # Extendendo i = %eax para acesso de memória no caller-saved %r9
	movslq %eax, %r9
	movsd (%r8, %r9, 8), %xmm1 # # vd[i]
	
	# # Somando vd[i] em s
	addsd %xmm1, %xmm0
	
	# # Salvando s+vd[i] em s = -8(%rbp)
	movsd %xmm0, -8(%rbp)
	
	# # i--
	subl $1, %eax
	movl %eax, -60(%rbp) # # Salva novo i na pilha
	
	# # if (s > limit)
	# # s está em %xmm0
	# # limit será passado para o auxiliar caller-saved %xmm1
	movsd -72(%rbp), %xmm1
	
	# # (s > limit) = !(s <= limit)
	ucomisd %xmm1, %xmm0
	jbe EndIf
	
	# # printf("Soma %f maior que o limite %f\n", s, limit);
	# # Parâmetros
	# # str = %rdi
	movq $str, %rdi
	# # s já está em %xmm0
	# # limit já está em %xmm1
	
	# # Como passamos 2 PFs para o printf, %eax deve conter 2
	movl $2, %eax
	
	call printf
	
EndIf:
	
	jmp BlocoWhile
	
DepoisWhile:
	
	# # return s
	movsd -8(%rbp), %xmm0
	
	leave
	ret
