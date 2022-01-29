.data

.text

.globl calc1
calc1:

	pushq %rbp
	movq  %rsp, %rbp

	# # double a = %xmm0
	# # float b = %xmm1
	
	# # return (a+b)*(a-b);
	
	cvtss2sd %xmm1, %xmm1 # # Passando de float pra double
	
	# # Vamos passar a-b para %xmm2
	movsd %xmm0, %xmm2 # # a
	subsd %xmm1, %xmm2 # # a-b
	
	# # Vamos somar (a+b) em %xmm0
	addsd %xmm1, %xmm0 # # a+b
	
	# # Fazendo a multiplicação de %xmm2 (a-b) por %xmm0 (a+b) e deixando o resultado em %xmm0
	mulsd %xmm2, %xmm0
	
	# # Valor de resultado (a+b)*(a-b) já está em %xmm0, só retorna
	
	leave
	ret
