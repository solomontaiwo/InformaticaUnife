.data
	message1: .asciiz "After while loop is done."
	space: .asciiz ", "

.text
	main:
		addi $t0, $zero, 0
		
		while:
			bgt $t0, 10, exit
			jal printNumber
			addi $t0, $t0, 1
			
			j while
		exit:
			li $v0, 4
			la $a0, message1
			syscall
	
			li $v0, 10
			syscall
	
	printNumber:
		li $v0, 1
		add $a0, $t0, $zero
		syscall
		
		li $v0, 4
		la $a0, space
		syscall
		
		jr $ra
		
		li $v0, 10
		syscall		