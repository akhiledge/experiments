	.file	"a1.c"
	.section	.rodata
.LC0:
	.string	"%d %d"
	.text
	.globl	main
	.type	main, @function
main:
.LFB0:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%esi
	pushl	%ebx
	andl	$-16, %esp
	subl	$32, %esp
	.cfi_offset 6, -12
	.cfi_offset 3, -16
	movl	$7, 16(%esp)
	movl	$8, 20(%esp)
	leal	16(%esp), %eax
	movl	%eax, 24(%esp)
	leal	20(%esp), %eax
	movl	%eax, 28(%esp)
	movl	24(%esp), %eax
	movl	(%eax), %edx
	movl	28(%esp), %eax
	movl	(%eax), %ecx
	movl	24(%esp), %eax
	movl	(%eax), %ebx
	movl	28(%esp), %eax
	movl	(%eax), %esi
	movl	24(%esp), %eax
	movl	(%eax), %eax
	xorl	%eax, %esi
	movl	28(%esp), %eax
	movl	%esi, (%eax)
	movl	28(%esp), %eax
	movl	(%eax), %eax
	xorl	%eax, %ebx
	movl	24(%esp), %eax
	movl	%ebx, (%eax)
	movl	24(%esp), %eax
	movl	(%eax), %eax
	xorl	%eax, %ecx
	movl	28(%esp), %eax
	movl	%ecx, (%eax)
	movl	28(%esp), %eax
	movl	(%eax), %eax
	xorl	%eax, %edx
	movl	24(%esp), %eax
	movl	%edx, (%eax)
	movl	20(%esp), %edx
	movl	16(%esp), %eax
	movl	%edx, 8(%esp)
	movl	%eax, 4(%esp)
	movl	$.LC0, (%esp)
	call	printf
	movl	$0, %eax
	leal	-8(%ebp), %esp
	popl	%ebx
	.cfi_restore 3
	popl	%esi
	.cfi_restore 6
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 4.8.4-2ubuntu1~14.04.1) 4.8.4"
	.section	.note.GNU-stack,"",@progbits
