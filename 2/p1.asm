#���������������������
######    text segment                    ###########
   
       .text
       .globl main

main:  
       inputData:
       la $t0, value       #$t0 �����ʼֵ�ĵ�ַ

	   li $v0, 4	
	   la $a0,string1
	   syscall

       li $v0, 5           #��ȡ����ֵ��kernel serice 5��
       syscall
       sw $v0, 0($t0)      #�����ȡ������ֵ

	   li $v0,4
	   la $a0,string2
	   syscall

       li $v0, 5           #��ȡ�ڶ�������
       syscall
       sw $v0, 4($t0)

       lw $t1, 0($t0)
       lw $t2, 4($t0)
       add $t3,  $t1, $t2   #����������֮��
       sw  $t3,8($t0)

       li $v0, 4            #��ӡ�ַ�����kernel service 4)    
       la $a0, msg1   
       syscall

       li $v0, 1            #��ӡ������kernel service 1��
       move  $a0, $t3
       syscall

	   li $v0,4				#�ж��Ƿ����
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
string3:  .asciiz"\nDo you want to try another(0��continue/1��exit):"

##end of file 