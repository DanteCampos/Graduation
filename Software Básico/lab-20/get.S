.section .rodata
	str: .asciz "sum: %ld\n"
	
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
	
	# # Passando a node->values[i] = *(node + values + 8 + i*8) para %rax
	movq (%rdi, %r11), %rax

	# # %rax retorna long node->values[i];
	
	leave
	ret
