##fib-o.asm---A program to compute Fibonacci numbers
##Registers used:
##           $v0   -syscall parameter and return value
##			 $a0   -syscall parameter---the string to print
		.text
main:
		subu	$sp,$sp,32
		sw		$ra,28($sp)
		sw		$fp,24($sp)
		addu	$fp,$sp,32

		## Get n from the user, put into $a0
		li		$v0,5
		syscall
		move	$a0,$v0
		jal		fib

		move	$a0,$v0
		li		$v0,1
		syscall

		la		$a0,newline
		li		$v0,4
		syscall

		li		$v0,10
		syscall

## fib--(hacked-up caller-save method)
## Registers used:
##		$a0		- initially n.
##		$t0		- parameter n.
##		$t1		- fib(n-1).
##		$t2		- fib(n-2).
		.text
fib:
		bgt		$a0,1,fib_recurse
		li		$v0,1
		jr		$ra

fib_recurse:
		subu	$sp,$sp,32
		sw		$ra,28($sp)
		sw		$fp,24($sp)
		addu	$fp,$sp,32

		move	$t0,$a0

		sw		$t0,20($sp)
		sub		$a0,$t0,1
		jal		fib
		move	$t1,$v0
		lw		$t0,20($sp)

		sw		$t1,16($sp)
		sub		$a0,$t0,2
		jal		fib
		move	$t2,$v0
		lw		$t1,16($sp)

		add		$v0,$t1,$t2
		lw		$ra,28($sp)
		lw		$fp,24($sp)
		addu	$sp,$sp,32
		jr		$ra

## data for fib-o.asm:
		.data
newline:		.asciiz"\n"

##end of fib-o.asm