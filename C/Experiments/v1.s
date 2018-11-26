	.file	"v1.c"
	.section	.rodata
.LC0:
	.string	"eeeeeeeeeerrrrrrrrrrrrrrr"
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
	andl	$-16, %esp
	subl	$32, %esp
	movl	$8, 24(%esp)
	movl	$9, 28(%esp)
	movl	24(%esp), %eax
	andl	$1, %eax
	testl	%eax, %eax
	je	.L2
	movl	$.LC0, (%esp)
	call	printf
.L2:
	movl	$0, %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 4.8.4-2ubuntu1~14.04.1) 4.8.4"
	.section	.note.GNU-stack,"",@progbits
