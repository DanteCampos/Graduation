.data

.globl str
str: .string "BEBAMUITOCAFEBABE"

.text

.globl process

process:

	pushq %rbp

	movq  %rsp, %rbp
	
	#ptr = &str[0];
	movq $str, %r8
	
beginwhile:

	cmpb $0, (%r8)

	je endwhile            # while() {

	#(*ptr) += 32;
	addb $32, (%r8)
	
	#ptr++;
	addq $1, %r8	
	
	jmp beginwhile         # }

endwhile:

	leave

	ret
