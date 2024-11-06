	.file	"1-3.c"
	.text
	.globl	add
	.type	add, @function
add:
.LFB0:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movl	%edi, -4(%rbp)
	movl	%esi, -8(%rbp)
	movl	-4(%rbp), %edx
	movl	-8(%rbp), %eax
	addl	%edx, %eax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	add, .-add
	.section	.rodata
.LC0:
	.string	" Temp Converter "
.LC1:
	.string	"%d"
.LC3:
	.string	"%3d %6.1f\n"
	.text
	.globl	main
	.type	main, @function
main:
.LFB1:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	leaq	.LC0(%rip), %rax
	movq	%rax, %rdi
	call	puts@PLT
	movl	$9, %esi
	movl	$60, %edi
	call	add
	movl	%eax, %esi
	leaq	.LC1(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	movl	$0, -4(%rbp)
	movl	$300, -8(%rbp)
	jmp	.L4
.L5:
	movl	-8(%rbp), %eax
	subl	$32, %eax
	pxor	%xmm1, %xmm1
	cvtsi2sdl	%eax, %xmm1
	movsd	.LC2(%rip), %xmm0
	mulsd	%xmm0, %xmm1
	movq	%xmm1, %rdx
	movl	-8(%rbp), %eax
	movq	%rdx, %xmm0
	movl	%eax, %esi
	leaq	.LC3(%rip), %rax
	movq	%rax, %rdi
	movl	$1, %eax
	call	printf@PLT
	subl	$20, -8(%rbp)
.L4:
	movl	-8(%rbp), %eax
	cmpl	-4(%rbp), %eax
	je	.L5
	movl	$0, %eax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1:
	.size	main, .-main
	.section	.rodata
	.align 8
.LC2:
	.long	1908874354
	.long	1071761180
	.ident	"GCC: (Gentoo 13.3.1_p20240614 p17) 13.3.1 20240614"
	.section	.note.GNU-stack,"",@progbits
	.section	.note.gnu.property,"a"
	.align 8
	.long	1f - 0f
	.long	4f - 1f
	.long	5
0:
	.string	"GNU"
1:
	.align 8
	.long	0xc0000002
	.long	3f - 2f
2:
	.long	0x3
3:
	.align 8
4:
