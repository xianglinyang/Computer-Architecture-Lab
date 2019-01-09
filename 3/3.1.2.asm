######### data #############
.data
array:		.double 1.0,2.0,3.0,4.0,5.0,6.0,7.0,8.0
float:		.double 1.0
########## text ###########
.text
.globl main

main:
		la		$t0,array
		addi	$t1,$t0,64
		#la		$t2,float
		#l.d		$f2,0($t2)
		l.d		$f2,float

loop:
		l.d		$f0,0($t0)
		l.d		$f6,8($t0)
		l.d		$f10,16($t0)
		l.d		$f14,24($t0)

		add.d	$f4,$f0,$f2
		add.d	$f8,$f6,$f2
		add.d	$f12,$f10,$f2
		add.d	$f16,$f14,$f2

		s.d		$f4,0($t0)
		s.d		$f8,8($t0)
		s.d		$f12,16($t0)

		addi	$t0,$t0,32
		bne		$t1,$t0,loop
		s.d		$f16,-8($t0)

		la		$t0,array
		addi	$t1,$t0,64
loop1:
		l.d		$f12,($t0)
		li		$v0,3
		syscall
		addi	$t0,$t0,8
		bne		$t0,$t1,loop1
exit:
		li $v0,10
		syscall

