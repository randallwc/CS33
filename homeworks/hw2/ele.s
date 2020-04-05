	.file	"ele.c"
	.text
	.p2align 4
	.globl	ele
	.type	ele, @function
ele:
.LFB0:
	.cfi_startproc
	movl	$3, %eax
	subq	%rdi, %rax
	leaq	(%rax,%rax,8), %rcx
	leaq	(%rax,%rcx,2), %rax
	subq	%rsi, %rax
	leaq	1(%rdx,%rax,2), %rax
	movl	A(,%rax,4), %eax
	ret
	.cfi_endproc
.LFE0:
	.size	ele, .-ele
	.comm	A,456,32
	.ident	"GCC: (GNU) 9.2.0"
	.section	.note.GNU-stack,"",@progbits
