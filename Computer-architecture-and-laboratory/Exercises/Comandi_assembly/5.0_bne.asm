.data
	message: .asciiz "The numbers are different."
	message2: .asciiz "The numbers are equal."
	input1: .asciiz "Insert the first number: "
	input2: .asciiz "Insert the secondo number: "
	
.text
	main:	
		# Print input1 message
		li $v0, 4
		la $a0, input1
		syscall
		
		# Ask user for first number
		li $v0, 5
		syscall
		
		# Move user input from $v0 to $t0
		move $t0, $v0
		
		# Print input1 message
		li $v0, 4
		la $a0, input2
		syscall
		
		# Ask user for second number
		li $v0, 5
		syscall
		
		# Move user input from $v0 to $t0
		move $t1, $v0
		
		# Compare the inserted numbers and, if not equal, branch to numbersDifferent 		
		bne $t0, $t1, numbersDifferent
		
		# Print message2 if the numbers are equal
		li $v0, 4
		la $a0, message2
		syscall
		
		li $v0, 10
		syscall
	
	numbersDifferent:
		li $v0, 4
		la $a0, message
		syscall
		
		li $v0, 10
		syscall