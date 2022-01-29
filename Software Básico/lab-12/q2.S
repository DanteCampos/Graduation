.section .rodata

.data

.text

.globl main
main:

	pushq %rbp

	movq  %rsp, %rbp

	# # scanf("%ld", &a);
	call 	read_long_to_rax
	movq 	%rax, %r8
	
	# #if (a) = if (a!=0) = (!(a == 0))
	cmpq 	$0, %r8
	je 		fim
	
		# # scanf("%ld", &b);
		call 	read_long_to_rax
		movq 	%rax, %r9
		
		# #if (b > 10) = if (! (b <= 10))
		cmpq 	$10, %r9
		jle 	elseDentro
		
			# #b = 2*a + a*b;
			movq 	%r8, %rax
			imulq 	$2, %rax 	# rax tem 2*a
			movq 	%r8, %r10
			imulq 	%r9, %r10 	# r10 tem a*b
			addq 	%r10, %rax 	# rax tem 2*a + a*b
			movq 	%rax, %r9 	# b tem 2*a + a*b
			
			# # printf("%ld\n", b);
			movq 	%r9, %rax
			call 	print_rax_as_long
		
	jmp 	fim
		
elseDentro:
	# #a = b >> 2;
	movq 	%r9, %r8 # coloca o valor de b em a
	sarq 	$2, %r8  # faz 2 shifts (aritméticos) pra direita
	
	# #printf("0x%lX\n", a);
	movq 	%r8, %rax
	call 	print_rax_as_hex
fim:

	movl $0, %eax

	leave

	ret
