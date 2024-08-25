.data
	message: .asciiz "Fine del loop."
	space: .asciiz ", "
	
.text
	main:
		addi $s0, $zero, 0
	
		while:
			bgt $s0, 50, exit
		
			jal printValue
			jal printSpace
		
			addi $s0, $s0, 1
		
			j while
		
	exit:
	
	li $v0, 4
	la $a0, message
	syscall
	
	li $v0, 10
	syscall
	
	printValue:
		li $v0, 1
		move $a0, $s0
		syscall
		
		jr $ra
		
		li $v0, 10
		syscall
					
	printSpace:
		li $v0, 4
		la $a0, space
		syscall
		
		jr $ra
		
		li $v0, 10
		syscall