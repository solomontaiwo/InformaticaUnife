.text
	addi $s0, $zero, 3
	addi $s1, $zero, 2
	
	mul $s2, $s1, $s0
	
	li $v0, 1
	add $a0, $s2, $zero
	syscall