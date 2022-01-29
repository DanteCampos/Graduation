.data
	#char c = -20;
	.globl c
	c: .byte -20
	
	#int i = -256;
	.globl i
	.align 4
	i: .long -256
	
	#unsigned int ui = 1024;
	.globl ui
	.align 4
	ui: .long 1024
	
	#long l = 128;
	.globl l
	.align 8
	l: .quad 128
	
	#unsigned long ul = 2048;
	.globl ul
	.align 8
	ul: .quad 2048
	
	#int v[5] = {10,20,30,40,50};
	.globl v
	.align 4
	v: .long 10, 20, 30, 40, 50
	
	#unsigned short us = 111;
	.globl us
	.align 2
	us: .word 111


.text

.globl aux
aux:
	#long *ptr;
	#Vou usar o %r10 como ptr
	
    pushq %rbp
    movq  %rsp, %rbp

    # %rax, %rcx, %rdx, %rdi, %rsi, %r8, %r9, %r10
	
	#c = i
	movsbl	c, %eax
	movl	%eax, i
	
	#ui = i;
	movl 	i, %eax
	movl 	%eax, ui
	
	#ul = ui;
	movl 	ui, %eax
	movq 	%rax, ul
	
	#us = ul;
	movq 	ul, %rax
	movw 	%ax, us
	
	#c  = 10 + i - 5;
	movl 	$10, %eax
	addl 	i, %eax
	subl 	$5, %eax
	movb 	%al, c
	
	#i = v[2];
	movq 	$v, %rax
	movq 	$2, %rcx
	movl 	(%rax, %rcx, 4), %edx
	movl 	%edx, i
	
	#v[4] = i;
	movl 	i, %edx
	movq 	$v, %rax
	movq 	$4, %rcx
	movl 	%edx, (%rax, %rcx, 4)
	
	#v[0] = v[3] - v[2] - v[1] + i;
	movq 	$v, %rax
	movq 	$3, %rcx
	movl 	(%rax, %rcx, 4), %edx
	movq 	$2, %rcx
	subl 	(%rax, %rcx, 4), %edx
	movq 	$1, %rcx
	subl 	(%rax, %rcx, 4), %edx
	movl 	i, %ecx
	addl 	%ecx, %edx
	movq 	$0, %rcx
	movl 	%edx, (%rax, %rcx, 4)
	
	#ptr = &l;
	movq 	$l,%r10
	
	#*ptr = ul;
	movq 	ul, %rax
	movq 	%rax, (%r10)
	
	#l = l * c;
	movq 	l, %rax
	movsbq 	c, %rcx
	imulq 	%rcx, %rax
	movq 	%rax, l
	
    leave

    ret
