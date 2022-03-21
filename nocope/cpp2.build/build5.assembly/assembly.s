	.section	__TEXT,__text,regular,pure_instructions
	.build_version macos, 11, 0	sdk_version 11, 3
	.globl	__Z8multiplydd                  ## -- Begin function _Z8multiplydd
	.p2align	4, 0x90
__Z8multiplydd:                         ## @_Z8multiplydd
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	movsd	%xmm0, -8(%rbp)
	movsd	%xmm1, -16(%rbp)
	movsd	-8(%rbp), %xmm0                 ## xmm0 = mem[0],zero
	mulsd	-16(%rbp), %xmm0
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.globl	__Z6devidedd                    ## -- Begin function _Z6devidedd
	.p2align	4, 0x90
__Z6devidedd:                           ## @_Z6devidedd
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	movsd	%xmm0, -8(%rbp)
	movsd	%xmm1, -16(%rbp)
	movsd	-8(%rbp), %xmm0                 ## xmm0 = mem[0],zero
	divsd	-16(%rbp), %xmm0
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
.subsections_via_symbols
