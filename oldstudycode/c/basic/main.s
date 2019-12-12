	.file	"main.c"
	.section	.rodata
	.align 4
.LC0:
	.string	"\350\257\267\350\276\223\345\205\245\350\265\267\345\247\213\346\225\260\345\255\227\345\222\214\347\273\223\346\235\237\346\225\260\345\255\227"
.LC1:
	.string	"%d%d"
.LC2:
	.string	"sum(%d,%d):%d\n"
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
	movl	$.LC0, %eax
	movl	%eax, (%esp)
	call	printf
	movl	$.LC1, %eax
	leal	20(%esp), %edx
	movl	%edx, 8(%esp)
	leal	16(%esp), %edx
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	__isoc99_scanf
	movl	16(%esp), %eax
	movl	%eax, 24(%esp)
	movl	$0, 28(%esp)
	jmp	.L2
.L3:
	movl	16(%esp), %eax
	movl	24(%esp), %edx
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	sum
	movl	%eax, 28(%esp)
	movl	16(%esp), %edx
	movl	$.LC2, %eax
	movl	28(%esp), %ecx
	movl	%ecx, 12(%esp)
	movl	24(%esp), %ecx
	movl	%ecx, 8(%esp)
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	printf
	addl	$1, 24(%esp)
.L2:
	movl	20(%esp), %eax
	cmpl	%eax, 24(%esp)
	jle	.L3
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.ident	"GCC: (Ubuntu/Linaro 4.6.3-1ubuntu5) 4.6.3"
	.section	.note.GNU-stack,"",@progbits
