#输入两个整数，并输出和
######    text segment                    ###########
   
       .text
       .globl main

main:  
       inputData:
       la $t0, value       #$t0 保存初始值的地址

	   li $v0, 4	
	   la $a0,string1
	   syscall

       li $v0, 5           #读取整数值（kernel serice 5）
       syscall
       sw $v0, 0($t0)      #保存读取的整数值

	   li $v0,4
	   la $a0,string2
	   syscall

       li $v0, 5           #读取第二个整数
       syscall
       sw $v0, 4($t0)

       lw $t1, 0($t0)
       lw $t2, 4($t0)
       add $t3,  $t1, $t2   #求两个整数之和
       sw  $t3,8($t0)

       li $v0, 4            #打印字符串（kernel service 4)    
       la $a0, msg1   
       syscall

       li $v0, 1            #打印整数（kernel service 1）
       move  $a0, $t3
       syscall

	   li $v0,4				#判断是否结束
	   la $a0,string3
	   syscall

	   la $t0 value1
	   li $v0,5
	   syscall
	   sw $v0, 0($t0)
	   lw $t0 value1
	   beqz $t0,inputData

	   li $v0, 10
	   syscall



######   data segment####################################

       .data
value: .word 0,0,0
value1: .word 0
msg1:  .asciiz "result= "
string1:  .asciiz "Please enter 1st number: "
string2:  .asciiz "Please enter 2nd number: "
string3:  .asciiz"\nDo you want to try another(0—continue/1—exit):"

##end of file 