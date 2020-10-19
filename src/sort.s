	.file	"sort.c"
	.text
	.p2align 4
	.globl	bubblesort
	.type	bubblesort, @function
bubblesort:
.LFB0:
	.cfi_startproc
	endbr64
	movl	%esi, %edx
	leaq	8(%rdi), %r9
	subl	$1, %edx
	js	.L13
	testl	%edx, %edx
	jle	.L14
	.p2align 4,,10
	.p2align 3
.L7:
	subl	$1, %edx
	movq	%rdi, %rax
	movq	%rdx, %r8
	leaq	(%r9,%rdx,8), %rsi
	.p2align 4,,10
	.p2align 3
.L5:
	movq	(%rax), %rdx
	movq	8(%rax), %rcx
	cmpq	%rcx, %rdx
	jle	.L4
	movq	%rcx, (%rax)
	movq	%rdx, 8(%rax)
.L4:
	addq	$8, %rax
	cmpq	%rsi, %rax
	jne	.L5
.L6:
	movl	%r8d, %edx
	testl	%edx, %edx
	jg	.L7
.L14:
	subl	$1, %edx
	movl	%edx, %r8d
	jns	.L6
	ret
.L13:
	ret
	.cfi_endproc
.LFE0:
	.size	bubblesort, .-bubblesort
	.ident	"GCC: (Ubuntu 9.3.0-17ubuntu1~20.04) 9.3.0"
	.section	.note.GNU-stack,"",@progbits
	.section	.note.gnu.property,"a"
	.align 8
	.long	 1f - 0f
	.long	 4f - 1f
	.long	 5
0:
	.string	 "GNU"
1:
	.align 8
	.long	 0xc0000002
	.long	 3f - 2f
2:
	.long	 0x3
3:
	.align 8
4:
