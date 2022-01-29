
.section .rodata
	.globl strIf
	strIf: .string "'a' é maior do que 'b'\n"
	
	.globl strElse
	strElse: .string "'a' não é maior do que 'b'\n"
	
.data
	#int a = 100;
	.globl a
	.align 4
	a: .long 100
	
	#int b = 200;
	.globl b
	.align 4
	b: .long 200
.text

.globl main
main:

	pushq %rbp
	movq  %rsp, %rbp
   
	# #if (a > b) = if (!(a <= b))
	movl 	a, %eax
	movl 	b, %ecx
  	
  	# #(a <= b)
	cmpl 	%ecx, %eax
	jle 	blocoElse
	
	# #printf("'a' é maior do que 'b'\n");
	movq 	$strIf, %rax
	call 	print_rax_as_string
	
	jmp depoisTudo

blocoElse:
	# #printf("'a' não é maior do que 'b'\n");
	movq 	$strElse, %rax
	call 	print_rax_as_string	
depoisTudo:

   movl $0, %eax

   leave
   ret
