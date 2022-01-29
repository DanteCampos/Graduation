.section .rodata
	str: .asciz "a = %f, b = %f, e = %f\n"

.data

.text

.globl calc2
calc2:

	pushq %rbp
	movq  %rsp, %rbp
	subq $16, %rsp # # Para salvar 2 registradores PF


	# # float a = %xmm0
	# # float b = %xmm1
	
	# # Salvando os registradores %xmm0 e %xmm1
	movss %xmm0, -8(%rbp)
	movss %xmm1, -16(%rbp)
	
	# # double e = a + cos(b);
	# # double e será o registrador %xmm2
	
	# # Passando b (%xmm1) como parâmetro (e convertendo para double)
	movss %xmm1, %xmm0
	cvtss2sd %xmm0, %xmm0
	
	# # Chamando a função cos
	call cos
	
	# # Trazendo "a" (-8(%rbp)) para %xmm1 para convertê-lo pra double e somá-lo ao cos(b) (%xmm0)
	movss -8(%rbp), %xmm1 # # a
	cvtss2sd %xmm1, %xmm1 # # (double) a
	
	# # Soma "a" (%xmm1) ao cos(b) (%xmm0)
	addsd %xmm1, %xmm0
	
	# # Passando (a + cos(b)) (%xmm0) para "e" (%xmm2)
	movsd %xmm0, %xmm2 
	
	# # printf("a = %f, b = %f, e = %f\n", a, b, e);
	
	# # Parâmetros
	# # str0 = %rdi
	# # a = %xmm0
	# # b = %xmm1
	# # e = %xmm2
	
	# # Passando $str para %rdi
	movq $str, %rdi
	
	# # Passando a (-8(%rbp)) para %xmm0 e convertendo para double
	movss -8(%rbp), %xmm0
	cvtss2sd %xmm0, %xmm0
	
	# # Passando b (-16(%rbp)) para %xmm1 e convertendo para double
	movss -16(%rbp), %xmm1
	cvtss2sd %xmm1, %xmm1
	
	# # "e" já está em %xmm2
	
	# # Como são 3 parâmetros PF, colocamos 3 em %eax
	movl $3, %eax
	
	call printf
	
	# # return b;
	# # Colocamos b em %xmm0 para retorná-lo
	movss -16(%rbp), %xmm0
	
	leave
	ret
