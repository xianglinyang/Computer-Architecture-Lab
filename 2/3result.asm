#�������
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
	la $t1,arrs	            #������ʼ��ַ

	sumn:
	addi $t3,$0,0			#������
	addi $t4,$0,0			#sum

	loop:
	lw	 $t0,($t1)			#$t0=arrs[i]
	add  $t4,$t4,$t0		#sum=sum+arrs[i]
	addi $t1,$t1,4			#ָ��������һ����ַ
	addi $t3,$t3,1			#i=i+1

	lw $t0,N
	blt $t3,$t0,loop

	li $v0,4				#��ӡ"The result is: "
	la $a0,string1
	syscall

	li $v0,1				#��ӡresult
	move $a0,$t4
	syscall

	exit:
	li $v0,10
	syscall