.section .rodata
	str: .asciz "sum: %ld\n"

data:

	.globl sync
	.align 4
	sync: .long 0

# # Como a estrutura está armazenada:

	# # int size		+0
	# # padding 4
	# # long values[5]	+8
	# # int used		+48
	# # padding 4 	para o tamanho total ser múltiplo de 8
	
	# # Tamanho total da estrutura = 56 bytes

.globl getvalue
getvalue:
	pushq %rbp
	movq  %rsp, %rbp

	# # node_t* node = %rdi
	# # int i = %esi
	
	# # return node->values[i];
	# # values[i] = +8 +i*8
	
	# # Estendendo i (%esi) para o registrador auxiliar caller-saved %r11
	movslq %esi, %r11
	
	# # Multiplicando i (%r11) por 8 = (sizeof(long))
	imulq $8, %r11
	
	# # Somando 8 (offset para o começo de values[])
	addq $8, %r11
	
	# # Passando a node->values[i] = *(node + values + 8 + i*8) para %rax (caller-saved)
	movq (%rdi, %r11), %rax

	# # %rax retorna long node->values[i];
	
	leave
	ret


.globl sum
sum:
	pushq %rbp
	movq  %rsp, %rbp
	subq $32, %rsp # # Precisa salvar 3 registradores
	
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
	movq %rdi, -24(%rbp)
	
	# # Passando os parâmetros
	
	# # node = %rdi (já está aqui)
	# # i = %esi tem que passar de %r11d pra ele
	movl %r11d, %esi
	
	call getvalue
	
	# # Recuperando os registradores caller saved
	
	movq -8(%rbp), %r11
	movq -16(%rbp), %r10
	movq -24(%rbp), %rdi
	
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
