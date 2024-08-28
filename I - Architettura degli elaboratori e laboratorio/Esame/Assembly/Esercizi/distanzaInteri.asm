.data
	value1: .word 7
	value2: .word 4
.text
	main:
		lw $s0, value1
		lw $s1, value2
		
		addi $a0, $s0, 0
		addi $a1, $s1, 0
	
		jal dist
	
		add $s2, $v0, $zero
	
		li $v0, 1
		add $a0, $s2, $zero
		syscall
		
		li $v0, 10
		syscall
		
	dist:
		addi $sp, $sp, -8
		sw $t0, 0($sp)
		sw $t1, 4($sp)
		
		slt $t0, $a0, $a1
		beq $t0, $zero, subInverse
		sub $t1, $a1, $a0
		
		j space
		
		space:
			addi $v0, $t1, 0
			lw $t0, 0($sp)
			lw $t1, 4($sp)
			addi $sp, $sp, 8
			jr $ra
		
		subInverse:
			sub $t1, $a1, $a0
			j space
		
		