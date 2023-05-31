	.section	__TEXT,__text,regular,pure_instructions
	.build_version macos, 10, 15	sdk_version 10, 15, 6
	.globl	_ft_putchar             ## -- Begin function ft_putchar
	.p2align	4, 0x90
_ft_putchar:                            ## @ft_putchar
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	subq	$16, %rsp
                                        ## kill: def $dil killed $dil killed $edi
	movb	%dil, -1(%rbp)
	movl	$1, %edi
	leaq	-1(%rbp), %rsi
	movl	$1, %edx
	callq	_write
	addq	$16, %rsp
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.globl	_ft_atoi                ## -- Begin function ft_atoi
	.p2align	4, 0x90
_ft_atoi:                               ## @ft_atoi
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	movq	%rdi, -16(%rbp)
	movl	$0, -36(%rbp)
	cmpq	$0, -16(%rbp)
	jne	LBB1_2
## %bb.1:
	movq	$0, -8(%rbp)
	jmp	LBB1_22
LBB1_2:
	movq	$1, -24(%rbp)
	movq	$0, -32(%rbp)
LBB1_3:                                 ## =>This Inner Loop Header: Depth=1
	movq	-16(%rbp), %rax
	movslq	-36(%rbp), %rcx
	movsbl	(%rax,%rcx), %edx
	cmpl	$32, %edx
	movb	$1, %sil
	movb	%sil, -37(%rbp)         ## 1-byte Spill
	je	LBB1_7
## %bb.4:                               ##   in Loop: Header=BB1_3 Depth=1
	xorl	%eax, %eax
                                        ## kill: def $al killed $al killed $eax
	movq	-16(%rbp), %rcx
	movslq	-36(%rbp), %rdx
	movsbl	(%rcx,%rdx), %esi
	cmpl	$9, %esi
	movb	%al, -38(%rbp)          ## 1-byte Spill
	jl	LBB1_6
## %bb.5:                               ##   in Loop: Header=BB1_3 Depth=1
	movq	-16(%rbp), %rax
	movslq	-36(%rbp), %rcx
	movsbl	(%rax,%rcx), %edx
	cmpl	$13, %edx
	setle	%sil
	movb	%sil, -38(%rbp)         ## 1-byte Spill
LBB1_6:                                 ##   in Loop: Header=BB1_3 Depth=1
	movb	-38(%rbp), %al          ## 1-byte Reload
	movb	%al, -37(%rbp)          ## 1-byte Spill
LBB1_7:                                 ##   in Loop: Header=BB1_3 Depth=1
	movb	-37(%rbp), %al          ## 1-byte Reload
	testb	$1, %al
	jne	LBB1_8
	jmp	LBB1_9
LBB1_8:                                 ##   in Loop: Header=BB1_3 Depth=1
	movl	-36(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -36(%rbp)
	jmp	LBB1_3
LBB1_9:
	movq	-16(%rbp), %rax
	movslq	-36(%rbp), %rcx
	movsbl	(%rax,%rcx), %edx
	cmpl	$45, %edx
	je	LBB1_11
## %bb.10:
	movq	-16(%rbp), %rax
	movslq	-36(%rbp), %rcx
	movsbl	(%rax,%rcx), %edx
	cmpl	$43, %edx
	jne	LBB1_14
LBB1_11:
	movq	-16(%rbp), %rax
	movslq	-36(%rbp), %rcx
	movsbl	(%rax,%rcx), %edx
	cmpl	$45, %edx
	jne	LBB1_13
## %bb.12:
	imulq	$-1, -24(%rbp), %rax
	movq	%rax, -24(%rbp)
LBB1_13:
	movl	-36(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -36(%rbp)
LBB1_14:
	jmp	LBB1_15
LBB1_15:                                ## =>This Inner Loop Header: Depth=1
	xorl	%eax, %eax
                                        ## kill: def $al killed $al killed $eax
	movq	-16(%rbp), %rcx
	movslq	-36(%rbp), %rdx
	movsbl	(%rcx,%rdx), %esi
	cmpl	$0, %esi
	movb	%al, -39(%rbp)          ## 1-byte Spill
	je	LBB1_19
## %bb.16:                              ##   in Loop: Header=BB1_15 Depth=1
	xorl	%eax, %eax
                                        ## kill: def $al killed $al killed $eax
	movq	-16(%rbp), %rcx
	movslq	-36(%rbp), %rdx
	movsbl	(%rcx,%rdx), %esi
	cmpl	$48, %esi
	movb	%al, -40(%rbp)          ## 1-byte Spill
	jl	LBB1_18
## %bb.17:                              ##   in Loop: Header=BB1_15 Depth=1
	movq	-16(%rbp), %rax
	movslq	-36(%rbp), %rcx
	movsbl	(%rax,%rcx), %edx
	cmpl	$57, %edx
	setle	%sil
	movb	%sil, -40(%rbp)         ## 1-byte Spill
LBB1_18:                                ##   in Loop: Header=BB1_15 Depth=1
	movb	-40(%rbp), %al          ## 1-byte Reload
	movb	%al, -39(%rbp)          ## 1-byte Spill
LBB1_19:                                ##   in Loop: Header=BB1_15 Depth=1
	movb	-39(%rbp), %al          ## 1-byte Reload
	testb	$1, %al
	jne	LBB1_20
	jmp	LBB1_21
LBB1_20:                                ##   in Loop: Header=BB1_15 Depth=1
	imulq	$10, -32(%rbp), %rax
	movq	-16(%rbp), %rcx
	movslq	-36(%rbp), %rdx
	movsbq	(%rcx,%rdx), %rcx
	addq	%rcx, %rax
	subq	$48, %rax
	movq	%rax, -32(%rbp)
	movl	-36(%rbp), %esi
	addl	$1, %esi
	movl	%esi, -36(%rbp)
	jmp	LBB1_15
LBB1_21:
	movq	-32(%rbp), %rax
	imulq	-24(%rbp), %rax
	movq	%rax, -8(%rbp)
LBB1_22:
	movq	-8(%rbp), %rax
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.globl	_ft_putnbr              ## -- Begin function ft_putnbr
	.p2align	4, 0x90
_ft_putnbr:                             ## @ft_putnbr
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	subq	$16, %rsp
	movl	%edi, -4(%rbp)
	cmpl	$0, -4(%rbp)
	jge	LBB2_2
## %bb.1:
	movl	$45, %edi
	callq	_ft_putchar
	imull	$-1, -4(%rbp), %edi
	callq	_ft_putnbr
	jmp	LBB2_7
LBB2_2:
	cmpl	$0, -4(%rbp)
	jl	LBB2_5
## %bb.3:
	cmpl	$9, -4(%rbp)
	jg	LBB2_5
## %bb.4:
	movl	-4(%rbp), %eax
	addl	$48, %eax
                                        ## kill: def $al killed $al killed $eax
	movsbl	%al, %edi
	callq	_ft_putchar
	jmp	LBB2_6
LBB2_5:
	movl	-4(%rbp), %eax
	cltd
	movl	$10, %ecx
	idivl	%ecx
	movl	%eax, %edi
	callq	_ft_putnbr
	movl	-4(%rbp), %eax
	cltd
	movl	$10, %ecx
	idivl	%ecx
	movl	%edx, %edi
	callq	_ft_putnbr
LBB2_6:
	jmp	LBB2_7
LBB2_7:
	addq	$16, %rsp
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.globl	_ft_putstre             ## -- Begin function ft_putstre
	.p2align	4, 0x90
_ft_putstre:                            ## @ft_putstre
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movl	$-1, -12(%rbp)
	movl	$1, %edi
	leaq	L_.str(%rip), %rsi
	movl	$7, %edx
	callq	_write
LBB3_1:                                 ## =>This Inner Loop Header: Depth=1
	movq	-8(%rbp), %rax
	movl	-12(%rbp), %ecx
	addl	$1, %ecx
	movl	%ecx, -12(%rbp)
	movslq	%ecx, %rdx
	cmpb	$0, (%rax,%rdx)
	je	LBB3_3
## %bb.2:                               ##   in Loop: Header=BB3_1 Depth=1
	movq	-8(%rbp), %rax
	movslq	-12(%rbp), %rcx
	addq	%rcx, %rax
	movl	$1, %edi
	movq	%rax, %rsi
	movl	$1, %edx
	callq	_write
	jmp	LBB3_1
LBB3_3:
	movl	$1, %edi
	leaq	L_.str.1(%rip), %rsi
	movl	$5, %edx
	callq	_write
	addq	$16, %rsp
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.globl	_philo_task             ## -- Begin function philo_task
	.p2align	4, 0x90
_philo_task:                            ## @philo_task
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	subq	$64, %rsp
	movq	%rdi, -8(%rbp)
	movl	$32, %edi
	callq	_malloc
	movq	%rax, -16(%rbp)
	movq	-8(%rbp), %rax
	movq	%rax, -16(%rbp)
	leaq	L_.str.2(%rip), %rdi
	movb	$0, %al
	callq	_printf
	leaq	L_.str.3(%rip), %rdi
	movl	%eax, -28(%rbp)         ## 4-byte Spill
	movb	$0, %al
	callq	_printf
	movq	$0, -24(%rbp)
LBB4_1:                                 ## =>This Inner Loop Header: Depth=1
	cmpq	$1, -24(%rbp)
	jge	LBB4_4
## %bb.2:                               ##   in Loop: Header=BB4_1 Depth=1
	movq	-16(%rbp), %rax
	movl	24(%rax), %esi
	leaq	L_.str.4(%rip), %rdi
	xorl	%ecx, %ecx
                                        ## kill: def $cl killed $cl killed $ecx
	movb	%cl, %al
	movb	%cl, -29(%rbp)          ## 1-byte Spill
	callq	_printf
	movq	-16(%rbp), %rdx
	addq	$24, %rdx
	movq	%rdx, %rdi
	movl	%eax, -36(%rbp)         ## 4-byte Spill
	callq	_pthread_mutex_lock
	movq	-16(%rbp), %rdx
	movl	24(%rdx), %esi
	leaq	L_.str.5(%rip), %rdi
	movb	-29(%rbp), %cl          ## 1-byte Reload
	movl	%eax, -40(%rbp)         ## 4-byte Spill
	movb	%cl, %al
	callq	_printf
	lock		incl	_x(%rip)
	movq	-16(%rbp), %rdx
	addq	$24, %rdx
	movq	%rdx, %rdi
	movl	%eax, -44(%rbp)         ## 4-byte Spill
	callq	_pthread_mutex_unlock
	movq	-16(%rbp), %rdx
	movq	24(%rdx), %rdx
                                        ## kill: def $edx killed $edx killed $rdx
	leaq	L_.str.6(%rip), %rdi
	movl	%edx, %esi
	movl	%eax, -48(%rbp)         ## 4-byte Spill
	movb	$0, %al
	callq	_printf
## %bb.3:                               ##   in Loop: Header=BB4_1 Depth=1
	movq	-24(%rbp), %rax
	addq	$1, %rax
	movq	%rax, -24(%rbp)
	jmp	LBB4_1
LBB4_4:
	leaq	L_.str.3(%rip), %rdi
	movb	$0, %al
	callq	_printf
	xorl	%ecx, %ecx
	movl	%ecx, %edx
	movl	%eax, -52(%rbp)         ## 4-byte Spill
	movq	%rdx, %rax
	addq	$64, %rsp
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.globl	_creat_threads          ## -- Begin function creat_threads
	.p2align	4, 0x90
_creat_threads:                         ## @creat_threads
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	subq	$32, %rsp
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movq	%rdx, -24(%rbp)
	movl	$0, -28(%rbp)
LBB5_1:                                 ## =>This Inner Loop Header: Depth=1
	movl	-28(%rbp), %eax
	movq	-8(%rbp), %rcx
	cmpl	(%rcx), %eax
	jae	LBB5_5
## %bb.2:                               ##   in Loop: Header=BB5_1 Depth=1
	xorl	%eax, %eax
	movl	%eax, %esi
	movq	-24(%rbp), %rcx
	leaq	-16(%rbp), %rdi
	leaq	_philo_task(%rip), %rdx
	callq	_pthread_create
	xorl	%r8d, %r8d
	movl	%r8d, %esi
	movl	%eax, -32(%rbp)
	movq	-16(%rbp), %rdi
	callq	_pthread_join
	cmpl	$0, -32(%rbp)
	je	LBB5_4
## %bb.3:                               ##   in Loop: Header=BB5_1 Depth=1
	leaq	L_.str.7(%rip), %rdi
	callq	_ft_putstre
LBB5_4:                                 ##   in Loop: Header=BB5_1 Depth=1
	movl	-28(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -28(%rbp)
	jmp	LBB5_1
LBB5_5:
	addq	$32, %rsp
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.globl	_full_struct            ## -- Begin function full_struct
	.p2align	4, 0x90
_full_struct:                           ## @full_struct
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movq	-16(%rbp), %rax
	movq	8(%rax), %rdi
	callq	_ft_atoi
                                        ## kill: def $eax killed $eax killed $rax
	movq	-8(%rbp), %rcx
	movl	%eax, (%rcx)
	movq	-16(%rbp), %rcx
	movq	40(%rcx), %rdi
	callq	_ft_atoi
                                        ## kill: def $eax killed $eax killed $rax
	movq	-8(%rbp), %rcx
	movl	%eax, 16(%rcx)
	movq	-16(%rbp), %rcx
	movq	16(%rcx), %rdi
	callq	_ft_atoi
                                        ## kill: def $eax killed $eax killed $rax
	movq	-8(%rbp), %rcx
	movl	%eax, 4(%rcx)
	movq	-16(%rbp), %rcx
	movq	24(%rcx), %rdi
	callq	_ft_atoi
                                        ## kill: def $eax killed $eax killed $rax
	movq	-8(%rbp), %rcx
	movl	%eax, 8(%rcx)
	movq	-16(%rbp), %rcx
	movq	32(%rcx), %rdi
	callq	_ft_atoi
                                        ## kill: def $eax killed $eax killed $rax
	movq	-8(%rbp), %rcx
	movl	%eax, 12(%rcx)
	movq	-8(%rbp), %rcx
	movq	$0, 24(%rcx)
	addq	$16, %rsp
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.globl	_print_elem             ## -- Begin function print_elem
	.p2align	4, 0x90
_print_elem:                            ## @print_elem
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	subq	$32, %rsp
	leaq	16(%rbp), %rax
	cmpl	$0, (%rax)
	movq	%rax, -8(%rbp)          ## 8-byte Spill
	je	LBB7_2
## %bb.1:
	movq	-8(%rbp), %rax          ## 8-byte Reload
	movl	(%rax), %esi
	leaq	L_.str.8(%rip), %rdi
	movb	$0, %al
	callq	_printf
	movq	-8(%rbp), %rcx          ## 8-byte Reload
	movl	16(%rcx), %esi
	leaq	L_.str.9(%rip), %rdi
	movl	%eax, -12(%rbp)         ## 4-byte Spill
	movb	$0, %al
	callq	_printf
	movq	-8(%rbp), %rcx          ## 8-byte Reload
	movl	4(%rcx), %esi
	leaq	L_.str.10(%rip), %rdi
	movl	%eax, -16(%rbp)         ## 4-byte Spill
	movb	$0, %al
	callq	_printf
	movq	-8(%rbp), %rcx          ## 8-byte Reload
	movl	8(%rcx), %esi
	leaq	L_.str.11(%rip), %rdi
	movl	%eax, -20(%rbp)         ## 4-byte Spill
	movb	$0, %al
	callq	_printf
	movq	-8(%rbp), %rcx          ## 8-byte Reload
	movl	12(%rcx), %esi
	leaq	L_.str.12(%rip), %rdi
	movl	%eax, -24(%rbp)         ## 4-byte Spill
	movb	$0, %al
	callq	_printf
LBB7_2:
	addq	$32, %rsp
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
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
	subq	$48, %rsp
	movl	$0, -4(%rbp)
	movl	%edi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	leaq	L_.str.13(%rip), %rdi
	movb	$0, %al
	callq	_printf
	cmpl	$5, -8(%rbp)
	je	LBB8_2
## %bb.1:
	cmpl	$6, -8(%rbp)
	jne	LBB8_5
LBB8_2:
	leaq	-40(%rbp), %rax
	movq	-16(%rbp), %rsi
	movq	%rax, %rdi
	callq	_full_struct
	xorl	%ecx, %ecx
	movl	%ecx, %esi
	movq	-40(%rbp), %rax
	addq	$24, %rax
	movq	%rax, %rdi
	callq	_pthread_mutex_init
	movq	-16(%rbp), %rdi
	movl	%eax, -44(%rbp)         ## 4-byte Spill
	callq	_analyse_data
	cmpl	$0, %eax
	jne	LBB8_4
## %bb.3:
	movl	$1, %edi
	leaq	L_.str.14(%rip), %rsi
	movl	$3, %edx
	callq	_write
	movl	$0, -4(%rbp)
	jmp	LBB8_7
LBB8_4:
	movq	-24(%rbp), %rsi
	leaq	-40(%rbp), %rax
	movq	%rax, %rdi
	movq	%rax, %rdx
	callq	_creat_threads
	movl	_x(%rip), %esi
	leaq	L_.str.15(%rip), %rdi
	movb	$0, %al
	callq	_printf
	jmp	LBB8_6
LBB8_5:
	leaq	L_.str.16(%rip), %rdi
	callq	_ft_putstre
LBB8_6:
	movl	$0, -4(%rbp)
LBB8_7:
	movl	-4(%rbp), %eax
	addq	$48, %rsp
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.globl	_x                      ## @x
.zerofill __DATA,__common,_x,4,2
	.section	__TEXT,__cstring,cstring_literals
L_.str:                                 ## @.str
	.asciz	"\033[1;32m"

L_.str.1:                               ## @.str.1
	.asciz	"\033[0m\n"

L_.str.2:                               ## @.str.2
	.asciz	"===a=c=c=e=s======\n"

L_.str.3:                               ## @.str.3
	.asciz	"\n================\n"

L_.str.4:                               ## @.str.4
	.asciz	"first_mutex = %d \n"

L_.str.5:                               ## @.str.5
	.asciz	"after_lock_mutex = %d \n"

L_.str.6:                               ## @.str.6
	.asciz	"final_mutex = %d \n"

L_.str.7:                               ## @.str.7
	.asciz	"error while thread creation"

L_.str.8:                               ## @.str.8
	.asciz	" philo.number_of_philo = %d \n"

L_.str.9:                               ## @.str.9
	.asciz	" philo->repeat_turn    = %d \n"

L_.str.10:                              ## @.str.10
	.asciz	" philo->time_to_die    = %d \n"

L_.str.11:                              ## @.str.11
	.asciz	" philo->time_to_eat    = %d \n"

L_.str.12:                              ## @.str.12
	.asciz	" philo->time_to_sleep  = %d \n"

L_.str.13:                              ## @.str.13
	.asciz	"HI"

L_.str.14:                              ## @.str.14
	.asciz	"by\n"

L_.str.15:                              ## @.str.15
	.asciz	"\n *|x|* = %d \n"

L_.str.16:                              ## @.str.16
	.asciz	"remember : Enter enough argument"

.subsections_via_symbols
