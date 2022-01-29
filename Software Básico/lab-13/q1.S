.section .rodata

	str01: .ascii "soma = "

.data
	# # int nums[4] = {65, -105, 111, 34};
	.globl nums
	.align 4
	nums: .long 65, -105, 111, 34

.text

.globl main
main:

	pushq %rbp
	movq  %rsp, %rbp

	# # int i = 0;
	movl $0, %ecx
	
	# # int s = 0;
	movl $0, %edx
	
Loop:
	# # while (i<4) = (!(i>=4))
	cmpl $4, %ecx
	jge DepoisLoop
	
	# # s = s + nums[i++];
	movq $nums, %r8
	movslq %ecx, %r9
	imulq $4, %r9
	addq %r8, %r9
	movl (%r9), %eax
	addl %eax, %edx
	
	# # i++
	incl %ecx
	
	jmp Loop
	
DepoisLoop:
	# # printf ("soma = %d\n", s);
	movq $str01, %rax
	call print_rax_as_string
	
	movl %edx, %eax
	call print_eax_as_int


	movl $0, %eax

	leave

	ret
