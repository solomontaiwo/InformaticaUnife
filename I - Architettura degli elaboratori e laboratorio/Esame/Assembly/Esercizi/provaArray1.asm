.data
	array1: .word 1, 3, 5, 7, 9
	
	indice: .word 0
	contatoreLoop: .word 4
	
.text
	main:
		lw $t0, array1
		
		li $v0, 1
		lw $a0, 0($t0)
		syscall
		
		li $v0, 10
		syscall