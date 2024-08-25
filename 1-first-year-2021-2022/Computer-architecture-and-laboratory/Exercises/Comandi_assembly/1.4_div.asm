.data
	number1: .word 10
	number2: .word 5
	
.text
	lw $t0, number1
	lw $t1, number2
	
	div $s0, $t0, $t1
	
	li $v0, 1
	add $a0, $s0, $zero
	syscall