.data
	message: .asciiz "Exercise on functions\n"
	
.text
	main:
		jal displayMessage
		
		# Print 5
		addi $s0, $zero, 5
		
		li $v0, 1
		add $a0, $zero, $s0
		syscall
		
	# Tell the program that the process is done
	li $v0, 10
	syscall
	
	displayMessage:
		li $v0, 4
		la $a0, message
		syscall
		
		jr $ra