#翻译代码
#######		data		#########
.data
	arrs:
		.word 9,7,15,19,20,30,11,18
	N:
		.word 8
	result:
		.word 0
	string1:
		.asciiz"The result is: "
	
#######		text		#########
.text
.globl main
.globl N
.globl loop
.globl exit


main:
	la $t1,arrs	            #数组起始地址

	sumn:
	addi $t3,$0,0			#计数器
	addi $t4,$0,0			#sum

	loop:
	lw	 $t0,($t1)			#$t0=arrs[i]
	add  $t4,$t4,$t0		#sum=sum+arrs[i]
	addi $t1,$t1,4			#指向数组下一个地址
	addi $t3,$t3,1			#i=i+1

	lw $t0,N
	blt $t3,$t0,loop

	li $v0,4				#打印"The result is: "
	la $a0,string1
	syscall

	li $v0,1				#打印result
	move $a0,$t4
	syscall

	exit:
	li $v0,10
	syscall