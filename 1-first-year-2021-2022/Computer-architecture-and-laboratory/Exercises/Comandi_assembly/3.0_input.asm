.data
	prompt: .asciiz "Enter your age: "
	message: .asciiz "Your age is "
	
.text
	main:
		# Promt the user to enter his age
		li $v0, 4
		la $a0, prompt
		syscall
		
		# Get user's age
		li $v0, 5
		syscall
		
		# Move the user input to a temporary register
		move $s0, $v0
		
		# Display final message
		li $v0, 4
		la $a0, message
		syscall
		
		# Print age
		li $v0, 1
		move $a0, $s0
		syscall

	li $v0, 10
	syscall
