.data
	.align 4
	.globl tamBufferAberto
	tamBufferAberto: .long 0

.text

.globl myopen
myopen:

	pushq %rbp
	movq  %rsp, %rbp

	# # Parâmetros recebidos
	# # const char *pathname = %rdi
	# # int flags = %esi
	# # int buffersize = %edx
	
	# # tamBufferAberto = buffersize;
	movl %edx, %eax
	movl %eax, tamBufferAberto
	
	# # return open(pathname, flags);
	
	# # Parâmetros a serem passados:
	# # const *char pathname = %rdi, já está lá
	# # int flags = %esi, já está lá
	
	# # Colocando o código de open (2) em %rax:
	movq $2, %rax
	
	syscall
	
	# # O retorno da função já está em %rax
	
	leave
	ret

.globl myread
myread:

	pushq %rbp
	movq  %rsp, %rbp

	# # Parâmetros recebidos
	# # int fd = %edi
	# # void *buf = %rsi
	
	
	# # return read(fd, buf, tamBufferAberto);
	
	# # Parâmetros a serem passados:
	# # int fd = %edi, já está lá
	# # void *buf = %rsi, já está lá
	# # int tamBufferAberto = %edx, vamos colocar lá
	
	movl tamBufferAberto, %edx
	
	# # Colocando o código de read (0) em %rax:
	movq $0, %rax
	
	syscall
	
	# # O retorno da função já está em %rax

	leave
	ret

    
.globl mywrite
mywrite:

	pushq %rbp
	movq  %rsp, %rbp

	# # Parâmetros recebidos
	# # int fd = %edi
	# # const void *buf = %rsi
	# # size_t count = %rdx
	
	# # return write(fd, buf, count);
	
	# # Parâmetros a serem passados:
	# # int fd = %edi, já está lá
	# # const void *buf = %rsi, já está lá
	# # size_t count = %rdx, já está lá
	
	# # Colocando o código de write (1) em %rax:
	movq $1, %rax
	
	syscall
	
	# # O retorno da função já está em %rax

	leave
	ret
    
.globl myclose
myclose:

	pushq %rbp
	movq  %rsp, %rbp

	# # Parâmetros recebidos
	# # int fd = %edi
	
	# # return close(fd);
	
	# # Parâmetros a serem passados:
	# # int fd = %edi, já está lá
	
	# # Colocando o código de close (3) em %rax:
	movq $3, %rax
	
	syscall
	
	# # O retorno da função já está em %rax

	leave
	ret
