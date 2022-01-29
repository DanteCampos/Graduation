
.section .rodata

.data

.text

.globl filtro

filtro:

	pushq %rbp
	movq  %rsp, %rbp

	# # int r; vai ser %eax
	
	# # unsigned short a = (unsigned short)x;
	movzbw %dil, %cx
	
	# # unsigned short b = (unsigned short)lim;
	movw %si, %dx
	
BlocoIf:
	# # if (a < b) = !(a >= b)
	cmpw %dx, %cx
	jge BlocoElse
	
	# # r = 0;
	movl $0, %eax
	jmp DepoisIf
	
BlocoElse:
	
	# # r = (int)lim;
	movswl %dx, %eax

DepoisIf:
	
	# # return r;
	# # r já é %eax pra retornar
	
	leave
	ret
