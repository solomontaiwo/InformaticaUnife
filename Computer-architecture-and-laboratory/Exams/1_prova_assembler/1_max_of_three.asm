.text
	addi $s0, $zero, 9	# a
	addi $s1, $zero, 2	# b
	addi $s2, $zero, 8	# c

	addi $s3, $s2, 0	# x, valore max (init a c)
	
	slt $t0, $s1, $s0	# b < a
	slt $t1, $s2, $s0	# c < a
	
	and $t2, $t0, $t1	# & logico
	
	beq $t2, $zero, label	# else
	
	addi $s3, $s0, 0
	
	j end
	
	label:
		slt $t3, $s2, $s1	# c < b
		beq $t3, $zero, end
		addi $s3, $s1, 0
	
	end:
		addi $v0, $zero, 1
		addi $a0, $s3, 0
		syscall