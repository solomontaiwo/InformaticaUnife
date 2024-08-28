.data
	message: .asciiz "Hi, how are you?"
.text
	main:
		addi $s0, $zero, 10
				
		bgtz $s0, displayHi
			
	li $v0, 10
	syscall
		
	displayHi:
		li $v0, 4
		la $a0, message
		syscall
		
		li $v0, 10
		syscall