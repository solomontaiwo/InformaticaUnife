.data 
	message1: .asciiz ".\nWhile loop is done."
	comma: .asciiz ", "
	
.text
	main:
		addi $t0, $zero, 0
		
		while:
			bgt $t0, 10, exit
			jal printNumber
			
			addi $t0, $t0, 1
			
			blt $t0, 11, printComma
			
			j while
		exit:
			li $v0, 4
			la $a0, message1
			syscall
			
			li $v0, 10
			syscall
			
	printNumber:
		li $v0, 1
		add $a0, $zero, $t0
		syscall
		
		jr $ra
		
	printComma:
		li $v0, 4
		la $a0, comma
		syscall
		
		j while