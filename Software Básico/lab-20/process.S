.section .rodata
	str: .asciz "sum: %ld\n"

.globl process
process:
	pushq %rbp
	movq  %rsp, %rbp
	
	subq $16, %rsp # # Precisa salvar %rdi
	
	# # node_t* nodes = %rdi
	
	
	# # init(&nodes[1]);
	
	# # Salvando o registrador %rdi (caller-saved) antes de chamar a função
	movq %rdi, -8(%rbp)
	
	# # Vamos usar %r11 (caller-saved) como auxiliar para armazenar o offset da estrutura inteira
	movq $56, %r11
	
	# # Passando o parâmetro &nodes[1] = &(*(nodes + 1*offset_estrutura)) para a função
	imulq $1, %r11 # # Multiplicando o offset pelo índice
	addq %r11, %rdi # # Somando para obter o endereço &nodes[1]
	
	call init
	
	# # Recuperando o registrador %rdi (caller-saved) depois de chamar a função
	movq -8(%rbp), %rdi
	
	
	# # init(&nodes[0]);
	
	# # Salvando o registrador %rdi (caller-saved) antes de chamar a função
	movq %rdi, -8(%rbp)
	
	# # Vamos usar %r11 (caller-saved) como auxiliar para armazenar o offset da estrutura inteira
	movq $56, %r11
	
	# # Passando o parâmetro &nodes[0] = &(*(nodes + 0*offset_estrutura)) para a função
	imulq $0, %r11 # # Multiplicando o offset pelo índice
	addq %r11, %rdi # # Somando para obter o endereço &nodes[0]
	
	call init
	
	# # Recuperando o registrador %rdi (caller-saved) depois de chamar a função
	movq -8(%rbp), %rdi
	
	
	# # printf("sum: %ld\n", sum(&nodes[1]));
	
	# # Chamando a sum(&nodes[1])) antes
	
	# # Salvando o registrador %rdi (caller-saved) antes de chamar a função
	movq %rdi, -8(%rbp)
	
	# # &nodes[1] = %rdi
	
	# # Vamos usar %r11 (caller-saved) como auxiliar para armazenar o offset da estrutura inteira
	movq $56, %r11
	
	# # Passando o parâmetro &nodes[1] = &(*(nodes + 1*offset_estrutura)) para a função
	imulq $1, %r11 # # Multiplicando o offset pelo índice
	addq %r11, %rdi # # Somando para obter o endereço &nodes[1]
	
	call sum
	
	# # Recuperando o registrador %rdi (caller-saved) depois de chamar a função
	movq -8(%rbp), %rdi
	
	# # sum(&nodes[1])) está em %rax
	
	# # Salvando o registrador %rdi (caller-saved) antes de chamar a função
	movq %rdi, -8(%rbp)
	
	# # Parâmetros:
	# # str = %rdi
	# # sum(&nodes[1])) = %rsi
	
	movq $str, %rdi
	movq %rax, %rsi
	
	# # Zerando %eax para chamar o printf
	movl $0, %eax
	
	call printf
	
	# # Recuperando o registrador %rdi (caller-saved) depois de chamar a função
	movq -8(%rbp), %rdi
	
	leave
	ret
