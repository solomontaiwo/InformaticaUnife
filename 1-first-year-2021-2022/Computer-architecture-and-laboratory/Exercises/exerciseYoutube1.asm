.text
	addi $s0, $zero, 0	# f
	addi $s1, $zero, 1	# g
	addi $s2, $zero, 2	# h
	addi $s3, $zero, 3	# i
	addi $s4, $zero, 4	# j
	
	add $t0, $s1, $s2
	add $t1, $s3, $s4
	
	sub $s0, $t0, $t1	# 3 - 7
	
	li $v0, 1
	add $a0, $s0, $zero
	syscall