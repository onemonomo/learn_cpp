	.section	__TEXT,__text,regular,pure_instructions
	.build_version macos, 10, 14
	.globl	_main                   ## -- Begin function main
	.p2align	4, 0x90
_main:                                  ## @main
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	subq	$16, %rsp
	movl	$4, %eax
	movl	%eax, %edi
	movl	$0, -4(%rbp)
	movl	$1000, -8(%rbp)         ## imm = 0x3E8
	callq	__Znwm
	movl	$1, %ecx
	movq	%rax, %rdi
	movl	$1, (%rax)
	movq	%rdi, -16(%rbp)
	movl	%ecx, %eax
	addq	$16, %rsp
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function

.subsections_via_symbols
