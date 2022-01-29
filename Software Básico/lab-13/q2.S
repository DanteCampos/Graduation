
.section .rodata

.data

.text

.globl main

main:

	pushq %rbp

	movq  %rsp, %rbp

	# # short i = 10;
	movw $10, %r8w
	
	# # short j = 20;
	movw $20, %r9w
	
	# # short k = 30;
	movw $30, %r10w
	
	# # unsigned char r = 16;
	movb $16, %r11b
	
	# # if (i < 20 || j < 30)
	# # (i < 20)
	cmpw $20, %r8w
	jl BlocoIf1
	
	# # (!(j >= 30))
	cmpw $30, %r9w
	jge DepoisIf1

BlocoIf1:
	# # r = r >> 1;
	shrb $1, %r11b 
	
DepoisIf1:
	# # if (j > 30 && k < 20)
	# # (!(j <= 30))
	cmpw $30, %r9w
	jle DepoisIf2
	
	# # (!(k >= 20))
	cmpw $20, %r10w
	jge DepoisIf2
	
	#r = r / 2;
	movzbw %r11b, %ax
	movb $2, %cl
	divb %cl
	movb %al, %r11b

DepoisIf2:
	
	# # if ( (i > 20 && j > 30) || k > 20)
	# # (!(i <= 20))
	cmpw $20, %r8w
	jle AndDeuFalso
	
	# # (j > 30)
	cmpw $30, %r9w
	jg BlocoIf3
	
AndDeuFalso:	
	# # (!(k <= 20))
	cmp $20, %r10w
	jle DepoisIf3
	
BlocoIf3:
	# # r = r + 100;
	addb $100, %r11b
	
DepoisIf3:
	
	# # printf("%u\n", r);   // Imprime como 'unsigned int'
	movzbl %r11b, %eax
	call print_eax_as_uint
	
	movl $0, %eax

	leave

	ret
