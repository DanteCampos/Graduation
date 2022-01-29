.section .rodata

.Lfmt01:  .string "%ld\n"
.Lfmt02:  .string "%lu\n"
.Lfmt03:  .string "%d\n"
.Lfmt04:  .string "%u\n"
.Lfmt05:  .string "%p\n"
.Lfmt06:  .string "%s"
.Lfmt07:  .string "%c"
.Lfmt08:  .string "\n"

#-----------------------------------------------------------------------
.data

.Lbuf: .zero 1024

#-----------------------------------------------------------------------
.text

.globl print_eax_as_char
.globl print_rax_as_string
.globl print_newline

.globl print_eax_as_int
.globl print_eax_as_uint

.globl print_rax_as_long
.globl print_rax_as_ulong

.globl print_eax_as_hex
.globl print_rax_as_hex

.globl read_int_to_eax
.globl read_long_to_rax
.globl read_string_to_rax

#-----------------------------------------------------------------------
read_int_to_eax:
   pushq %rbp
   movq  %rsp, %rbp

   subq  $128, %rsp

   movq %rax,  -8(%rbp)
   movq %rcx, -16(%rbp)
   movq %rdx, -24(%rbp)
   movq  %r8, -32(%rbp)
   movq  %r9, -40(%rbp)
   movq %r10, -48(%rbp)
   movq %r11, -56(%rbp)
   movq %rdi, -64(%rbp)
   movq %rsi, -72(%rbp)

   movq  $.Lbuf, %rdi
   movq   $1024, %rsi
   movq   stdin, %rdx
   call fgets
   
   movl     $0, %eax
   movq $.Lbuf, %rdi
   call atoi
   
   #movq  -8(%rbp), %rax
   movq -16(%rbp), %rcx
   movq -24(%rbp), %rdx
   movq -32(%rbp), %r8
   movq -40(%rbp), %r9
   movq -48(%rbp), %r10
   movq -56(%rbp), %r11
   movq -64(%rbp), %rdi
   movq -72(%rbp), %rsi
   
   leave
   ret

#-----------------------------------------------------------------------
read_long_to_rax:
   pushq %rbp
   movq  %rsp, %rbp

   subq  $128, %rsp

   movq %rax,  -8(%rbp)
   movq %rcx, -16(%rbp)
   movq %rdx, -24(%rbp)
   movq  %r8, -32(%rbp)
   movq  %r9, -40(%rbp)
   movq %r10, -48(%rbp)
   movq %r11, -56(%rbp)
   movq %rdi, -64(%rbp)
   movq %rsi, -72(%rbp)

   movq  $.Lbuf, %rdi
   movq $1024, %rsi
   movq stdin, %rdx
   call fgets
   
   movl   $0, %eax
   movq $.Lbuf, %rdi
   call atol
   
   #movq  -8(%rbp), %rax
   movq -16(%rbp), %rcx
   movq -24(%rbp), %rdx
   movq -32(%rbp), %r8
   movq -40(%rbp), %r9
   movq -48(%rbp), %r10
   movq -56(%rbp), %r11
   movq -64(%rbp), %rdi
   movq -72(%rbp), %rsi
   
   leave
   ret

#-----------------------------------------------------------------------
print_eax_as_char:
   pushq %rbp
   movq  %rsp, %rbp

   subq  $128, %rsp

   movq %rax,  -8(%rbp)
   movq %rcx, -16(%rbp)
   movq %rdx, -24(%rbp)
   movq  %r8, -32(%rbp)
   movq  %r9, -40(%rbp)
   movq %r10, -48(%rbp)
   movq %r11, -56(%rbp)
   movq %rdi, -64(%rbp)
   movq %rsi, -72(%rbp)
   
   movq $.Lfmt07, %rdi
   movl   %eax, %esi
   movl     $0, %eax
   call printf
   
   movq  -8(%rbp), %rax
   movq -16(%rbp), %rcx
   movq -24(%rbp), %rdx
   movq -32(%rbp), %r8
   movq -40(%rbp), %r9
   movq -48(%rbp), %r10
   movq -56(%rbp), %r11
   movq -64(%rbp), %rdi
   movq -72(%rbp), %rsi
   
   leave
   ret

#-----------------------------------------------------------------------
print_newline:
   pushq %rbp
   movq  %rsp, %rbp

   subq  $128, %rsp

   movq %rax,  -8(%rbp)
   movq %rcx, -16(%rbp)
   movq %rdx, -24(%rbp)
   movq  %r8, -32(%rbp)
   movq  %r9, -40(%rbp)
   movq %r10, -48(%rbp)
   movq %r11, -56(%rbp)
   movq %rdi, -64(%rbp)
   movq %rsi, -72(%rbp)
   
   movq $.Lfmt08, %rdi
   movl     $0, %eax
   call printf
   
   movq  -8(%rbp), %rax
   movq -16(%rbp), %rcx
   movq -24(%rbp), %rdx
   movq -32(%rbp), %r8
   movq -40(%rbp), %r9
   movq -48(%rbp), %r10
   movq -56(%rbp), %r11
   movq -64(%rbp), %rdi
   movq -72(%rbp), %rsi
   
   leave
   ret
    
#-----------------------------------------------------------------------
read_string_to_rax:
   pushq %rbp
   movq  %rsp, %rbp

   subq  $128, %rsp

   movq %rax,  -8(%rbp)
   movq %rcx, -16(%rbp)
   movq %rdx, -24(%rbp)
   movq  %r8, -32(%rbp)
   movq  %r9, -40(%rbp)
   movq %r10, -48(%rbp)
   movq %r11, -56(%rbp)
   movq %rdi, -64(%rbp)
   movq %rsi, -72(%rbp)

   movq  %rax, %r12

   movq  %rax, %rdi
   movq  $128, %rsi
   movq stdin, %rdx
   call fgets

#--- remove '\n'
   movl $0, %ecx
.L1:
   cmpl $128, %ecx
   je   .L2

   xorq %rax,   %rax
   movb (%r12), %al
   cmpb $10,    %al
   jne  .L3
   movb $0, (%r12)
.L3:
   incq %r12
   incl %ecx
   jmp  .L1
.L2:
#---

   movq  -8(%rbp), %rax
   movq -16(%rbp), %rcx
   movq -24(%rbp), %rdx
   movq -32(%rbp), %r8
   movq -40(%rbp), %r9
   movq -48(%rbp), %r10
   movq -56(%rbp), %r11
   movq -64(%rbp), %rdi
   movq -72(%rbp), %rsi

   leave
   ret

#-----------------------------------------------------------------------
print_rax_as_string:
   pushq %rbp
   movq  %rsp, %rbp

   subq  $128, %rsp

   movq %rax,  -8(%rbp)
   movq %rcx, -16(%rbp)
   movq %rdx, -24(%rbp)
   movq  %r8, -32(%rbp)
   movq  %r9, -40(%rbp)
   movq %r10, -48(%rbp)
   movq %r11, -56(%rbp)
   movq %rdi, -64(%rbp)
   movq %rsi, -72(%rbp)
   
   movq $.Lfmt06, %rdi
   movq   %rax, %rsi
   movl     $0, %eax
   call printf
   
   movq  -8(%rbp), %rax
   movq -16(%rbp), %rcx
   movq -24(%rbp), %rdx
   movq -32(%rbp), %r8
   movq -40(%rbp), %r9
   movq -48(%rbp), %r10
   movq -56(%rbp), %r11
   movq -64(%rbp), %rdi
   movq -72(%rbp), %rsi
   
   leave
   ret

#-----------------------------------------------------------------------
print_rax_as_long:
   pushq %rbp
   movq  %rsp, %rbp

   subq  $128, %rsp

   movq %rax,  -8(%rbp)
   movq %rcx, -16(%rbp)
   movq %rdx, -24(%rbp)
   movq  %r8, -32(%rbp)
   movq  %r9, -40(%rbp)
   movq %r10, -48(%rbp)
   movq %r11, -56(%rbp)
   movq %rdi, -64(%rbp)
   movq %rsi, -72(%rbp)
   
   movq $.Lfmt01, %rdi
   movq   %rax, %rsi
   movl     $0, %eax
   call printf
   
   movq  -8(%rbp), %rax
   movq -16(%rbp), %rcx
   movq -24(%rbp), %rdx
   movq -32(%rbp), %r8
   movq -40(%rbp), %r9
   movq -48(%rbp), %r10
   movq -56(%rbp), %r11
   movq -64(%rbp), %rdi
   movq -72(%rbp), %rsi
   
   leave
   ret

#-----------------------------------------------------------------------
print_rax_as_ulong:
   pushq %rbp
   movq  %rsp, %rbp

   subq  $128, %rsp

   movq %rax,  -8(%rbp)
   movq %rcx, -16(%rbp)
   movq %rdx, -24(%rbp)
   movq  %r8, -32(%rbp)
   movq  %r9, -40(%rbp)
   movq %r10, -48(%rbp)
   movq %r11, -56(%rbp)
   movq %rdi, -64(%rbp)
   movq %rsi, -72(%rbp)
   
   movq $.Lfmt02, %rdi
   movq   %rax, %rsi
   movl     $0, %eax
   call printf
   
   movq  -8(%rbp), %rax
   movq -16(%rbp), %rcx
   movq -24(%rbp), %rdx
   movq -32(%rbp), %r8
   movq -40(%rbp), %r9
   movq -48(%rbp), %r10
   movq -56(%rbp), %r11
   movq -64(%rbp), %rdi
   movq -72(%rbp), %rsi
   
   leave
   ret

#-----------------------------------------------------------------------
print_eax_as_int:
   pushq %rbp
   movq  %rsp, %rbp

   subq  $128, %rsp

   movq %rax,  -8(%rbp)
   movq %rcx, -16(%rbp)
   movq %rdx, -24(%rbp)
   movq  %r8, -32(%rbp)
   movq  %r9, -40(%rbp)
   movq %r10, -48(%rbp)
   movq %r11, -56(%rbp)
   movq %rdi, -64(%rbp)
   movq %rsi, -72(%rbp)
   
   movq $.Lfmt03, %rdi
   movl   %eax, %esi
   movl     $0, %eax
   call printf
   
   movq  -8(%rbp), %rax
   movq -16(%rbp), %rcx
   movq -24(%rbp), %rdx
   movq -32(%rbp), %r8
   movq -40(%rbp), %r9
   movq -48(%rbp), %r10
   movq -56(%rbp), %r11
   movq -64(%rbp), %rdi
   movq -72(%rbp), %rsi
   
   leave
   ret

#-----------------------------------------------------------------------
print_eax_as_uint:
   pushq %rbp
   movq  %rsp, %rbp

   subq  $128, %rsp

   movq %rax,  -8(%rbp)
   movq %rcx, -16(%rbp)
   movq %rdx, -24(%rbp)
   movq  %r8, -32(%rbp)
   movq  %r9, -40(%rbp)
   movq %r10, -48(%rbp)
   movq %r11, -56(%rbp)
   movq %rdi, -64(%rbp)
   movq %rsi, -72(%rbp)
   
   movq $.Lfmt04, %rdi
   movl   %eax, %esi
   movl     $0, %eax
   call printf
   
   movq  -8(%rbp), %rax
   movq -16(%rbp), %rcx
   movq -24(%rbp), %rdx
   movq -32(%rbp), %r8
   movq -40(%rbp), %r9
   movq -48(%rbp), %r10
   movq -56(%rbp), %r11
   movq -64(%rbp), %rdi
   movq -72(%rbp), %rsi
   
   leave
   ret

#-----------------------------------------------------------------------
print_eax_as_hex:
   pushq %rbp
   movq  %rsp, %rbp

   subq  $128, %rsp

   movq %rax,  -8(%rbp)
   movq %rcx, -16(%rbp)
   movq %rdx, -24(%rbp)
   movq  %r8, -32(%rbp)
   movq  %r9, -40(%rbp)
   movq %r10, -48(%rbp)
   movq %r11, -56(%rbp)
   movq %rdi, -64(%rbp)
   movq %rsi, -72(%rbp)
   
   movq $.Lfmt05, %rdi
   movl   %eax, %esi
   movl     $0, %eax
   call printf
   
   movq  -8(%rbp), %rax
   movq -16(%rbp), %rcx
   movq -24(%rbp), %rdx
   movq -32(%rbp), %r8
   movq -40(%rbp), %r9
   movq -48(%rbp), %r10
   movq -56(%rbp), %r11
   movq -64(%rbp), %rdi
   movq -72(%rbp), %rsi
   
   leave
   ret

#-----------------------------------------------------------------------
print_rax_as_hex:
   pushq %rbp
   movq  %rsp, %rbp

   subq  $128, %rsp

   movq %rax,  -8(%rbp)
   movq %rcx, -16(%rbp)
   movq %rdx, -24(%rbp)
   movq  %r8, -32(%rbp)
   movq  %r9, -40(%rbp)
   movq %r10, -48(%rbp)
   movq %r11, -56(%rbp)
   movq %rdi, -64(%rbp)
   movq %rsi, -72(%rbp)
   
   movq $.Lfmt05, %rdi
   movq   %rax, %rsi
   movl     $0, %eax
   call printf
   
   movq  -8(%rbp), %rax
   movq -16(%rbp), %rcx
   movq -24(%rbp), %rdx
   movq -32(%rbp), %r8
   movq -40(%rbp), %r9
   movq -48(%rbp), %r10
   movq -56(%rbp), %r11
   movq -64(%rbp), %rdi
   movq -72(%rbp), %rsi
   
   leave
   ret

