.globl aux
aux:
	pushq %rbp
	movq %rsp, %rbp
	
	# # Vamos precisar reservar 48 bytes de memória (menor múltiplo de 16 em que cabem 48 bytes)
	subq $48, %rsp
	
	# # Os valores passados por parâmetro estão nos seguintes registradores:
	# # int i 	%edi
	# # int j 	%esi
	# # int k 	%edx
	# # int l 	%ecx
	# # int m 	%r8d
	# # int n 	%r9d
	
	# # int r = calc(f, e, d, c, b, a);
	# # Vamos usar a pilha para inverter os parâmetros
	
	movq %rdi,  -8(%rbp) 
	movq %rsi, -16(%rbp) 
	movq %rdx, -24(%rbp) 
	movq %rcx, -32(%rbp) 
	movq %r8,  -40(%rbp) 
	movq %r9,  -48(%rbp) 
	
	movq -48(%rbp), %rdi
	movq -40(%rbp), %rsi
	movq -32(%rbp), %rdx
	movq -24(%rbp), %rcx
	movq -16(%rbp), %r8
	movq -8(%rbp),  %r9
	
	call calc
	
	# # calc retorna seu valor no registrador caller saved %eax
	
	# # return r + a + b + c + d + e + f;
	# # Pega de volta os parâmetros passados inicialmente
	
	movq -8(%rbp),  %rdi
	movq -16(%rbp), %rsi
	movq -24(%rbp), %rdx
	movq -32(%rbp), %rcx
	movq -40(%rbp), %r8
	movq -48(%rbp), %r9
	
	# # Vamos somando r, a, b, c, d, e, f no registrador caller saved %r10d
	movl $0, %r10d
	addl %eax, %r10d
	addl %edi, %r10d
	addl %esi, %r10d
	addl %edx, %r10d
	addl %ecx, %r10d
	addl %r8d, %r10d
	addl %r9d, %r10d
	
	# # Para retornar o resultado, ele deve estar em %eax
	movl %r10d, %eax
	
	leave
	ret

