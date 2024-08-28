.data
	number1: .word 37
	number2: .word 22
	
.text
	lw $t0, number1
	lw $t1, number2
	add $t2, $t0, $t1
	
	li $v0, 1
	move $a0, $t2
	syscall