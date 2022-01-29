.section .rodata
	str01: .asciz "%ld\n"
	
.data

.text

.globl show
show:

	pushq %rbp
	movq  %rsp, %rbp
	
	# # Vamos precisar de 32 bytes de memória para armazenar registradores
	subq $32, %rsp
	
	# # (struct data *d) é o ponteiro pra estrutura passado como parâmetro em %rdi
	# # int i; será o registrador caller-saved %ecx
	# # long *ptr = d->elems; será o registrador caller-saved %rdx
	
	movq %rdi, %rdx
	addq $8, %rdx # # endereço de elems[0]
	
	# # i = 0;
	movl $0, %ecx
	
BlocoFor:
	# # (i < d->len) = !(i >= d->len)
	# # d->len = (%rdi)
	cmpl (%rdi), %ecx
	jge DepoisFor
	
	# # Salvando os registradores %rdi, %rdx e %rcx para chamar o printf
	movq %rdi, (%rbp)
	movq %rdx, -8(%rbp)
	movq %rcx, -16(%rbp)
	
	# # Passando os parâmetros para chamar o printf
	# # "%ld\n" = $str01 = %rdi
	movq $str01, %rdi
	
	# # ptr[i] = (%rdx + 8 * %ecx) = %rsi
	# # Usando %rax (caller-saved) como auxiliar pra transformar %ecx em 8 bytes e fazer a soma
	movslq %ecx, %rax # # i
	imulq $8, %rax # # i * sizeof(long)
	addq %rdx, %rax  # # i * sizeof(long) + ptr
	movq (%rax), %rsi # # *(i * sizeof(long) + ptr) = ptr[i]
	
	# # printf precisa do %eax zerado
	movl $0, %eax
	
	call printf
	
	# # Recuperando os registradores %rdi, %rdx e %rcx
	movq (%rbp), %rdi
	movq -8(%rbp), %rdx
	movq -16(%rbp), %rcx
	
	# # i++
	addl $1, %ecx
	
	jmp BlocoFor
DepoisFor:
	
	movl $0, %eax
	leave
	ret
