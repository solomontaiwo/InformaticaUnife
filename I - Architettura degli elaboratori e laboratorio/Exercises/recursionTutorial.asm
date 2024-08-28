.data
	promptMessage: .asciiz "Enter a number to find its factorial: "
	resultMessage: .ascii "\nThe factorial of the number is "
	theNumber: .word 0
	theAnswer: .word 0
	
.text
	.globl main
	main:
		li $v0, 4
		la $a0, promptMessage
		syscall
		
		li $v0, 5
		syscall
		
		sw $v0, theNumber
		
		lw $a0, theNumber
		jal findFactorial
		sw $v0, theAnswer
		
		li $v0, 4
		la $a0, resultMessage
		syscall
		
		li $v0, 1
		lw $a0, theAnswer
		syscall
		
		li $v0, 10
		syscall
		
.globl findFactorial
findFactorial:
	subu $sp, $sp, 8
	sw $ra, ($sp)
	sw $s0, 4($sp)
	
	li $v0, 1
	beq $a0, 0, factorialDone
	
	move $s0, $a0
	sub $a0, $a0, 1
	jal findFactorial
	
	mul $v0, $s0, $v0
	
	factorialDone:
		lw $ra, ($sp)
		lw $s0, 4($sp)
		addu $sp, $sp, 8
		jr $ra