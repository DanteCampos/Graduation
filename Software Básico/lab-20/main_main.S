.section .rodata
	str: .asciz "sum: %ld\n"

.globl main
main:
	pushq %rbp
	movq  %rsp, %rbp
	
	# # 2 estruturas nodes totalizam 112 bytes (múltiplo de 16)
	subq $112, %rsp
	
	# # process(nodes)
	
	# # Parâmetro: nodes = %rdi
	# # nodes é o endereço do começo do vetor de estrutura = &(nodes[0]) = %rbp - 112
	leaq -112(%rbp), %rdi
	
	call process
	
	
	# # return 0
	movl $0, %eax
	
	leave
	ret
