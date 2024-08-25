.text
	main:
		addi $s0, $zero, 47	# a = 47
		addi $s1, $zero, 4	# b = 4
		
		addi $a0, $s0, 0	# argument 1
		addi $a1, $s1, 0	# argument 2
		
		jal abs
		
		addi $s2, $v0, 0	# result
		
		addi $v0, $zero, 1
		addi $a0, $s2, 0
		syscall
		
		addi $v0, $zero, 10
		syscall
		
	abs:
		addi $sp, $sp, -8
		sw $t0, 0($sp)
		sw $t1, 4($sp)
		
		slt $t2, $a1, $a0	# p < q
		beq $t2, $zero, else
		sub $v0, $a0, $a1
		
		j join
		
		else:
			sub $v0, $a1, $a0
		
		join:
			lw $t0, 0($sp)
			lw $t1, 4($sp)
			addi $sp, $sp, 8
			jr $ra
