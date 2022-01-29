.data

.globl str
str: .string "Soma: %ld\n"

.text

.globl main
main:
	pushq %rbp
	movq  %rsp, %rbp
	subq $32, %rsp # #Precisa armazenar 12 bytes e um registrador
	
	# # char c; vai ser o %al
	# # int i; é -4(%rbp)
	# # long l; é -16(%rbp)
	
	# # c = constante
	call constante
	
	# # Salvando c para chamar função
	movq %rax, -24(%rbp)
	
	# # init(&l, &i, c);
	leaq -16(%rbp), %rdi # # &l
	leaq -4(%rbp), %rsi # # &i
	movb %al, %dl
	call init
	
	# # Recuperando c
	movq -24(%rbp), %rax
	
	# # printf("Soma: %ld\n", l+i+c);
	movq $str, %rdi
	
	# # fazendo l+i+c
	movq -16(%rbp), %rsi # # l
	
	movslq -4(%rbp), %rcx
	addq %rcx, %rsi # # l+i
	
	movsbq %al, %rcx
	addq %rcx, %rsi # # l+i+c
	
	movl $0, %eax # #printf precisa de %eax zerado
	
	call printf
	
	movl $0, %eax
	leave
	ret
